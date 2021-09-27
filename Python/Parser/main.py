import requests
from bs4 import BeautifulSoup

url = "https://catalog.onliner.by/mobile"

headers = {
     "accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,"
               "application/signed-exchange;v=b3;q=0.9",
     "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) "
     "Chrome/91.0.4472.124 Safari/537.36 "
}

req = requests.get("https://catalog.onliner.by/sdapi/catalog.api/search/mobile?group=1", headers=headers)
src = req.text

soup = BeautifulSoup(src, "lxml")

mobile_phones = soup.find_all()

for mobile_names in mobile_phones:
    mobile_names = mobile_names.find("name").text
    print(mobile_names)
