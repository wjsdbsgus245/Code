# -*- coding: utf-8 -*-

from urllib.request import urlopen
from urllib.parse import quote_plus
from bs4 import BeautifulSoup

if __name__ == "__main__":
    URL = "https://comic.naver.com/webtoon/weekday.nhn"
    html = urlopen(URL)

    soup = BeautifulSoup(html, "html.parser")
    print(soup.decode('euc-kr'))