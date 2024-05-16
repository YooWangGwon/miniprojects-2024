# miniprojects-2024
부경대학교 2024 IoT 개발자 과정 미니 프로젝트 리포지토리

개발 기간 : 2024년03월21일 ~ 2024년03월26일

## C/C++ Miniproject

### 1일차(24.03.21)
- mini project 1

	- Language : C
	- Development environment : Rasberry Pi Putty
	- 아이디와 비밀번호를 입력하여 strcmp로 비교 
	- fopen으로 파일 열기 
	- strcpy로 파일 안의 내용을 읽고 fclose로 파일 닫기
	

- mini project 2

	- Language : C
	- Development environment : Rasberry Pi Putty, Visual Studio
	- 도서 등록, 출력 기능 추가
	- 도서를 제목, 저자, 출판사를 기준으로 검색하여 조회하는 기능 추가
	- 도서를 번호로 선택하여 삭제하는 기능 추가

### 2일차(24.03.22)
- mini project 2

	- Language : C
	- Development environment : Rasberry Pi Putty
	- 도서 검색 후 대여 기능 추가
	- 대여한 도서 선택 반납 및 전체 반납 기능 추가
	- 도서 전제 삭제 기능 추가
	- Putty에서 makefile을 통해 실행파일 생성하기
	
### 3일차(24.03.25)
- mini project 2

	- Language : C
	- Development environment : Rasberry Pi Putty
	- 도서 등록 함수에서 오류 발생시 함수 종료
	- 단순 로그인 기능 추가
	- 회원가입 시 별도로 생성된 파일에 아이디와 비밀번호 저장하는 기능 추가
	- 로그인 시 별도로 생성된 파일에 저장된 아이디와 비밀번호를 불러와서 로그인에서 사용하는 기능 추가
	- 도서 선택 삭제 기능 보완(선택 삭제 중 중간 삭제 및 마지막 도서 삭제)
	
### 4일차(24.03.26)
- mini project 2

	- Language : C
	- Development environment : Rasberry Pi Putty
	- 메인 파일 내용 간략화 및 메뉴 출력 함수 추가

## Iot Miniproject2

### 1일차(24.05.17)
- 조별 자리배치
- IoT프로젝트 개요
    
	![기본설명](https://raw.githubusercontent.com/YooWangGwon/miniprojects-2024/main/images/mp001.png)

	1. IoT기기 구성 - 아두이노, 라즈베리파이 등 IoT장비들과 연결
	2. 서버 구성 - IoT기기와 통신, DB 구성, 데이터 수집 앱 개발
	3. 모니터링 구성 - 	실시간 모니터링/제어 앱, 전체 연결

- 조별 미니프로젝트
    - 5월 28일 (40시간)
    - 구체적으로 어떤 디바이스 구성, 데이터 수집, 모니터링 계획
    - 8월말 정도에 끝나는 프로젝트 일정 계획
    - **요구사항 리스트, 기능명세, UI/UX 디자인, DB설계 문서하나**로 통합
    - 5월 28일 오후 각 조별로 파워포인트/프레젠테이션 10분 발표
    - 요구사항 리스트 문서전달
    - 기능명세 문서
    - DB설계 ERD 또는 SSMS 물리적DB설계 
    - UI/UX디자인 16일(목) 내용전달

## 2일차(24.05.16)
- 미니프로젝트
	- 프로젝트 문서
	- Notion 팀프로젝트 툴 사용
	- UI/UX 디자인 툴
		- 카카오 oven : https://ovenapp.io/
		- 피그마 : https://www.figma.com/
			- 피그마 단축키
				- V - 선택도구
				- A - 직선도구
				- T - 텍스트도구
				- Space + Drag - 마우스 커서에 따라 원하는 영역으로 이동
				- Ctrl + R - 레이어 이름 변경
				- Ctrl + G - 객체 그룹화
				- Ctrl + Shift + G - 객체 그룹 해제
				- Ctrl + D - 선택한 객체 복사
				- Ctrl + [ - 선택한 객체 뒤로 보내기
				- Ctrl + ] - 선택한 객체 앞으로 보내기
		- 목업 : https://app.moqups.com
	- 프레젠테이션
		- https://www.miricanvas.com/ko 미리캔버스 활용 추천
	- 라즈베리파이 리셋팅, 네트워크 설정, VNC(OS UI작업)

- 스마트홈 연동 클래스 미니프로젝트
	1. 요구사항 정의, 기능명세, 일정정리
	2. UI/UX 디자인
		- RPi는 디자인 없음(콘솔)
		- 데이터 수신앱
		- 모니터링 앱
	3. DB 설계
	4. RPi(Rasberry Pi) 셋팅(Network)
	5. RPi GPIO, IoT디바이스 연결(카메라, HDT센서(온습도 센서), RGB LED, ...)
	6. RPi 데이터 전송 파이썬 프로그래밍
	7. PC(Server) 데이터 수신 C# 프로그래밍
	8. 모니터링 앱 개발(수신 및 송싱)
