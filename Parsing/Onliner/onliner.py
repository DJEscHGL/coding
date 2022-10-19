from bs4 import BeautifulSoup
import requests
import json
import openpyxl

book = openpyxl.Workbook()

sheet = book.active

sheet['A1'] = 'Name'
sheet['B1'] = 'MinPrice'
sheet['C1'] = 'MaxPrice'
sheet['D1'] = 'EVGPrice'
sheet['E1'] = 'URL'

i = 2
for j in range(1, 64):
    URL = 'https://catalog.onliner.by/sdapi/catalog.api/search/mobile?group=1&page=' + \
        ascii(j)
    HEADERS = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/104.0.0.0 Safari/537.36'
    }

    response = requests.get(URL, headers=HEADERS)
    response.raise_for_status()
    data = response.json()
    with open('response.json', 'w', encoding='utf-8') as file:
        json.dump(data, file, indent=2, ensure_ascii=True)

    with open('response.json') as file:
        data = json.load(file)

    for phone in data['products']:
        sheet[i][0].value = phone['full_name']
        if phone['prices'] != None:
            sheet[i][1].value = phone['prices']['price_min']['amount']
            sheet[i][2].value = phone['prices']['price_max']['amount']
            sheet[i][3].value = (float(sheet[i][1].value) +
                                 float(sheet[i][2].value)) / 2
        sheet[i][4].value = phone['html_url']
        i = i + 1


book.save("phones.xlsx")
book.close()
