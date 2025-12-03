import requests
from collections import deque
from urllib.parse import urljoin, urldefrag
from bs4 import BeautifulSoup
from concurrent.futures import ThreadPoolExecutor, as_completed 


def get_text(url):
    html = requests.get(url, timeout=15).text
    txt = BeautifulSoup(html, "html.parser").get_text(" ")
    
    links = []
    for a in BeautifulSoup(html, "html.parser").find_all("a", href=True):
        full = urldefrag(urljoin(url, a['href']))[0]
        if full.startswith("http"):
            links.append(full)

    return txt, links


def crawl(start, distance, action):
    visited = set()
    to_visit = deque([(start, 0)])

    with ThreadPoolExecutor(max_workers=8) as executor:
        while to_visit:
            batch = []
            while to_visit and len(batch) < 16:
                url, d = to_visit.popleft()
                if url in visited or d > distance:
                    continue
                visited.add(url)
                batch.append((url, d))

            if not batch:
                continue

            future_to_info = {
                executor.submit(get_text, url): (url, d)
                for (url, d) in batch
            }

            for future in as_completed(future_to_info):
                url, d = future_to_info[future]
                try:
                    txt, links = future.result()
                    yield url, action(txt)

                    if d < distance:
                        for l in links:
                            if l not in visited:
                                to_visit.append((l, d + 1))
                except Exception as e:
                    yield url, f"Error: {e}"


if __name__ == "__main__":
    start = "http://www.ii.uni.wroc.pl"
    dist = 2

    for url, wynik in crawl(start, dist, lambda tekst: 'Python' in tekst):
        print(f"{url}: {wynik}")
