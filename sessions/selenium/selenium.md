# 파이썬 크롤링-Beautiful Soup와 Selenium을 함께 써보자!
**Selenium**에 대해 알아보겠습니다.

## 1. Selenium이란?
버튼을 클릭하거나, 로그인을 할 때 정보를 입력하거나 등을 하기에는 Beautiful Soup만으로 한계가 있습니다. 하지만 Selenium을 이용하면 직접적으로 웹 사이트에 접근할 수 있게 됩니다. Selenium은 일반적을 웹 앱을 테스트할 때 주로 사용하는 프레임워크입니다. 일종의 자동화 프로그램으로 테스터가 일일이 클릭하거나 값을 입력하지 않아도 자동으로 원하는 정보를 찾도록 도와줍니다.

## 2. Selenium 설치
pip 명령어를 사용해 Selenium을 설치합니다.
`pip install selenium`

## 3. Web Driver 설치
자신이 사용하는 브라우저의 driver를 별도로 다운로드 해야 합니다. Selenium은 컴퓨터가 직접 웹 브라우저를 띄운 후 코드를 쳐서 동작시킬 수 있도록 web driver라는 api를 제공합니다. 컴퓨터가 이를 직접 할 수 있도록 도와주는 driver를 설치해보도록 합시다.
크롬, 파이어폭스, 사파리 등이 driver를 제공합니다. 자신의 운영체제 맞는 버전으로 다운로드하고, 그 다운로드 한 위치의 경로를 알아둡시다.
(사파리는 기본으로 제공하기 때문에 따로 다운로드할 필요가 없습니다. ~~애플만세~~)

예)`C:\downloads\chromedriver`

## 4. Selenium 시작(학교 홈페이지 로그인하기~)
Python으로 하겠습니다!
아래와 같이 Python파일을 만들고 실행해봅시다.

1|from selenium import webdriver
2|path = "Webdriver의 경로를 입력합니다."
3|driver = webdriver.Chrome(path)

크롬 창이 켜지면 성공!

`driver.get('https://www.postech.ac.kr`)
코드 아래에 입력하고, 다시 실행해봅시다.

학교 홈페이지에 접속한걸 볼 수 있습니다!
