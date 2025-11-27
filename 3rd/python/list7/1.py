import asyncio
import aiohttp
import webbrowser

from prywatne import CAT_API_KEY


async def koci_obrazek(session):
    url = "https://api.thecatapi.com/v1/images/search"

    headers = {
        "x-api-key": CAT_API_KEY,
    }

    params = {
        "limit": 1,
        "size": "full",
    }

    async with session.get(url, headers=headers, params=params) as resp:
        data = await resp.json()
        if not data:
            print("Brak danych z TheCatAPI :(")
            return

        obrazek_url = data[0].get("url")
        print(f"URL obrazka kota: {obrazek_url}")
  
        webbrowser.open(obrazek_url)
        print("Otwieram obrazek kota")
        print()


async def koci_fakt(session):
    url = "https://catfact.ninja/fact"

    async with session.get(url) as resp:
        data = await resp.json()
        fact = data.get("fact")

        print(f"Fakt o kocie: {fact}")
        print()


async def main():
    async with aiohttp.ClientSession() as session:
        await asyncio.gather(
            koci_obrazek(session),
            koci_fakt(session),
        )


if __name__ == "__main__":
    asyncio.run(main())
