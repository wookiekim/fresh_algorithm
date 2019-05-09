# Web Application
웹 개발에 대해서 김찬영이 공부한 부분까지만 맛을 봐본다.

## Objectives
* 웹 개발 관련 기본 지식 습득
* Nodejs 기반 게시판 웹 애플리케이션 코드 이해
* Nodejs로 제작한 웹 서버 구축

## Javescrip VS Nodejs VS React
* (X)HTML: 웹에서 기본 문서를 작성할 때 필요한 언어. XML 문법을 적용.
```html
<!DOCTYPE html>
<html><head><meta charset="utf-8"></head><body>
  <div id="root"></div>
  <script src="bundle.js"></script>
</body></html>
```

* CSS: HTML로 작성된 문서에 디자인 서식을 입히고 보기 편하게 레이아웃을 정렬하는 것에 쓰이는 스타일
```html
<style type="text/css">
  선택자{속성:값;}
</style>
```

* Javascript: 개발자가 만든 문서에 방문자가 방문하여 어떤 동작을 취했을 때, 그 동작에 대응하여 반응이 일어날 수 있도록 해주는 언어
1. 인터프리터 언어
2. 클라이언트 스크립트 언어(사용자 컴퓨터에서 실행. 주로 웹 브라우저에 의해)
3. 객체 기반 언어 (BOM, DOM)

**내장 객체, 브라우저 객체 모델(BOM), 문서 객체 모델(
