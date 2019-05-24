# Kaldi를 이용하여 음성인식 모델링을 해보자!

제목에 쓰여있는 **Kaldi**(이하 칼디)가 무엇인지 그리고 **음성인식**이 어떻게 이루어지는 것인지 간단하게 확인한 후 실제 **모델링**을 해보는 실습을 하겠습니다.

## 1. Kaldi란?
음성인식기(이하 디코더, Decoder)를 만들어주는 C++ 로 구현된 툴킷입니다. 사용할 때는 bash로 간단하게 실행할 수 있습니다.
~~전문가들은 성능 향상을 위해 C++코드도 뜯어봐야겠지만~~ 우리는 일개 사용자이므로 필요에 따라 bash script 만 수정해서 돌리면 됩니다.
> **shell?** 검은창, 터미널. 쉽게 말해, 사람이 컴퓨터에게 어떤 일을 시킬 때 쓰는 프로그램. bash, zbash, ksh, csh 등이 있음.
> **shell script?** shell에 칠 명령어들을 텍스트 형태로 저장하여 실행시키는 것.  (예를들어 `ls` 와 `cd ..` 을 백번 쳐야 할 일이 있는데 script 파일에 for문으로 써놓고 그 파일만 실행하면 되는 것)

## 2. 음성 인식의 과정
ppt로 설명 드리겠습니다.

## 3. 실습
### 1) 환경
집 컴퓨터 VMware에 Ubuntu 16을 올려놓았습니다. 이를 서버로 사용합니다. 칼디를 사용하기 위해서 깔아야 하는게 원래 많은데, 다 구축해놓은 상태입니다.

### 2) 서버 접속
ip: 
port: 22
|      | id  | pwd    |
|------|-----|--------|
| 승욱 | ksw | kswksw |
| 찬영 | kcy | kcykcy |
| 지송 | cjs | cjscjs |
| 연준 | pyj | pyjpyj |

접속 후 `sudo -i` 로 root 권한을 얻으세요.
그 후 `cd /root/kaldi/egs/doremi` 로 이동합니다.

### 3) 녹음
총 21개의 wav 파일을 각자 녹음합니다.
7음계중 2개의 음을 골라 녹음 할 건데요, 아래와 같이 음계를 숫자로 표현했을 때

|   | 도 | 레 | 미 | 파 | 솔 | 라 | 시 |
|---|----|----|----|----|----|----|----|
|  | 0  | 1  | 2  | 3  | 4  | 5  | 6  |

 7_C_2(7*6/2=21) 가 되게 중복없이 골라서 녹음해주세요.
> 0 0, 0 1, 0 2, 0 3, 0 4, 0 5, 0 6, (1 0 은 포함 X) 1 1, 1 2, 1 3, ...

pc로 옮겨서 파일의 제목을 `자신의아이디_0_0.wav, 자신의아이디_0_1.wav` 의 형식으로 맞춰주세요. 
이 중에서 20개는 training에 쓰고 하나는 test 파일로 사용할 것입니다. 임의로 하나를 분리해 주세요.

### 4) Data preparation
앞에서 설명드린 Acoustic model과 Language model을 칼디가 만들 수 있도록 사람이 해줘야 하는 작업이 있습니다.

#### 녹음파일
kaldi/egs/doremi/doremi_audio/train 에 자신이 녹음한 **트레이닝** 파일 넣기(총 20개 확인)

#### Acoustic data
1. `cd kaldi/egs/doremi/data/train`
2. `vi spk2gender_자기아이디` 로 파일 생성 후 자기아이디 성별(f 또는 m) 작성
> hey f
3. `vi wav.scp_자기아이디`로 파일 생성 후 자신의 파일 위치 작성(총 20줄)
> **aey_0_1_5_2** /root/kaldi/egs/doremi/doremi_audio/train/aey_0_1_5_2.wav
4. `vi text_자기아이디` 로 파일 생성 후 파일에 녹음된 단어 작성(총 20줄)
>  **aey_0_1_5_2** do re la mi
5. `vi utt2spk_자기아이디`로 파일 생성 후 누가 발화했는지 작성(총 20줄)
> aey_0_1_5_2 **aey**
6. `cd kaldi/egs/doremi/data/local`
7. `vi corpus.txt_자기아이디`로 파일 생성 후 자기가 파일에 녹음한 단어들 작성(총 20줄)
> sol mi la fa
> re sol si do
> la do si fa

#### Language data
내가 준비해둠. 예를 들어 한 단어가 어떤 음소로 이루어져있는지 써주고 silent 같은건 어떻게 표시하겠다.. 등등을 셋팅하는 것임
> do d o
> fa f a
> la l a
> mi m i
> re r e
> si s i
> sol s o l

### 5) 서버 디코더 생성
### 6) 디코딩 테스트