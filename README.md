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

### 2일차(24.05.16)
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

### 3일차(24.05.17)
- 미니프로젝트
	- 실무 프로젝트 문서
	- Jira 사용법 : https://www.atlassian.com/
	- 조별로 진행

- 라즈베리 파이 세팅ss
	1. RPi 기본 구성 - RPi + MicroSD + Power
	2. RPi 기본 세팅
		- [x] 최신 업그레이드 
			- sudo apt-get update
			- sudo apt-get upgrades
		- [x] 한글화
		- [x] 키보드 변경
		- [x] 화면사이즈 변경(RealVNC)
		- [x] Pi Apps 앱설치 도우미 앱
		- [x] Github Desktop, VS Code
		- [x] 네트워크 확인
		- [ ] RealVNC Server 자동실행 설정 - 할 필요 없음

- 스마트홍 연동 클래스 미니프로젝트
	- RPi 셋팅 진행

### 4일차(24.05.20)
- 라즈베리 파이 IoT 장비 설치
	- [X] 라즈베리 파이 카메라 연결
	- [X] GPIO HAT
	- [X] 브레드보드와 연결
	- [ ] DHT11(온습도) 센서 
	- [X] RGB LED 모듈
		- V: 5볼트 R:Red G:Green B:Blue
		- V는 5V에 연결
		- R : GPIO4
		- G : GPIO5
		- B : GPIO6
	- [-] 서보모터

### 5일차(24.05.21)
- 라즈베리 파이 IoT 장비 설치
	- [X] DHT11(온습도) 센서 
		- GND : GND 8개 중 아무곳에 연결
		- VCC : 5V 연결
		- S : GPIO18 연결
		- Adafruit Github에서 Adafruit_python_DHT 클론하기
		- sudo rm /usr/lib/python3.11/EXTERNALLY-MANAGED 실행하기
		- Adafruit_Python_DHT 디렉토리에 들어가서 sudo pip install adafruit-circuitpython-dht로 설치하기

	![LED&DHT](https://raw.githubusercontent.com/YooWangGwon/miniprojects-2024/main/images/mp002.png)


- 라즈베리파이 마우스 속도 높이기
	- sudo nano /boot/firmware/cmdline.txt로 cmdline.txt에 들어가기
	- 제일 끝에 usbhid.mousepoll=0 입력하고 저장
	- sudo reboot로 재시작

- 라즈베리파이 무선랜 연결
	- sudo nano /etc/wpa_supplicant/wpa_supplicant.cont로 wpa_supplicant에 들어가기
	- 제일 상단에 country=KR 입력 -> 저장하고 나가기
	- sudo nano /etc/rc.local 로 rc.local에 들어가기
	- exit0 위에 아래 내용 입력하고 저장
	
	```shell
	sudo iw reg set KR
	sudo iwconfig wlan0 poweroff
	```
	
	- sudo reboot으로 재시작
	- 라즈베리 파이를 사용하고 있지 않더라도 WIFI 연결이 끊기지 않음

### 6일차(24.05.22)
- 컴퓨터마다 개별 공유기 설치하기
- RealVNC
	1. 라즈베리 파이에서 RealVNC Server 실행 또는 ifconfig를 통해 라즈베리파이 IP주소 확인
	2. 컴퓨터에서 RealVNC Viewer 을 실행하여 라즈베리파이 IP주소 입력 후 컴퓨터에서 라즈베리파이 화면 조작 가능

### 7일차(24.05.23)
- RealVNC
	- RealVNC Viewer 의 Picture Quality를 Medium으로 변경

- 스마트홈 연동 클래스 미니프로젝트
	- RGB LED, DHT11(온습도 센서)
	- RPi <--> Windows 통신(MQTT)
	- WPF 모니터링 앱

- IoT 기기간 통신방법
	- Modbus - 시리얼 통신으로 데이터 전송(완전 구식)
	- OPC UA - Modbus통신 불편한 점 개선(아주 복잡)
	- **MQTT** - 가장 편리! AWS IoT, Azure IoT 클라우드 산업계표준으로 사용

	![MQTT](https://raw.githubusercontent.com/YooWangGwon/miniprojects-2024/main/images/mp003.png)


- 데이터 전달 프로세스(MQTT)
	- Publisher(출판자) : 데이터를 만들어 Broker에게 전달
	- Broker : Publisher에게 받은 데이터 중 Subscriber가 요구하는 데이터를 전달
	- Subscriber(구독자) : 원하는 데이터를 Broker에게 요청
	- Publisher와 Subscriber 관계는 고정적이지 않음 
		-> 윈도우가 Publisher나 Subscriber 역할을 할 수 있고, 라즈베리파이가 Publisher나 Subscriber 역할을 할 수 있음

- MQTT 통신
	- [X] Mosquitto Broker 설치
		- mosquitto.config : listener 1883 0.0.0.0, allow_anonymous true 
		- 방화벽 인바운드 열기
	- [X] Rpi : paho-mqtt 패키지 설치, 송신역할(publisher)
		- sudo pip install paho-mqtt
	- [X] Win : MQTT.NET Nuget 패키지 설치, 수신역할(subscriber)
		- M2Mqtt : 가볍게 사용 가능. 업데이트가 안됨.
		- MQTTNet : MS에서 개발, 무겁다, 최신까지 업데이트 잘됨

### 8일차(24.05.24)
- MQTT 통신
	- 라즈베리파이에서 얻은 온습도 정보를 MQTT를 통해 컴퓨터에 받아오기

### 9일차(24.05.27)
- 스마트홈 연동 클래스 미니프로젝트
	- [X] WPF MQTT 데이터 DB로 저장
		- Newtonsoft.Json 패키지 활용
	- [X] MQTT 데이터 실시간 모니터링
		- LiveChart2, 실시간 온도 차트
	- [ ] MQTT로 RPi 제어 (LED ON/OFF)
	- [ ] WPF MQTT 데이터 히스토리 확인

	- DB 모니터링 화면

	![DB](https://raw.githubusercontent.com/YooWangGwon/miniprojects-2024/main/images/mp004.png)

	- 실시간 모니터링 화면

	![RealTime](https://raw.githubusercontent.com/YooWangGwon/miniprojects-2024/main/images/mp005.png)

### 10일차(24.05.28)
- 스마트홈 연동 클래스 미니프로젝트 마무리
	- [X] MQTT 데이터 실시간 모니터링
		- LiveChart2
	- [X] MQTT로 RPi 제어 (LED ON/OFF)
		- 실시간 모니터링 화면에서 버튼을 누르면 적색, 녹색 LED 및 LED 꺼짐
	- [X] WPF MQTT 데이터 히스토리 확인
		- DB 연동하여 저장된 로그들 출력
		- OxyPlot.WPF 패키지 사용
		- LiveChart2는 차후에 다시

	- 시각화 모니터링 화면
	![Visualization](https://raw.githubusercontent.com/YooWangGwon/miniprojects-2024/main/images/mp006.png)


- 조별 미니 프로젝트 발표