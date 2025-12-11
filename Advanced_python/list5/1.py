import requests
from collections import deque
from urllib.parse import urljoin, urldefrag
from bs4 import BeautifulSoup

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

    while to_visit:
        url, d = to_visit.popleft()
        if url in visited or d > distance:
            continue
        visited.add(url)

        try:
            txt, links = get_text(url)
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

