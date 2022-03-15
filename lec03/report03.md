## Lecture 3

### 이론
  * "."으로 시작하는 파일은 숨김 파일이다.

  * 환경변수 `$PATH`
    * 실행파일의 경로를 잡아주며 우선 순위가 있음
    * `$PATH`를 `.`으로 설정해주면 `./`없이 현재 디렉토리의 실행파일 실행 가능 (But, 실행파일로 인해 정보 유출 가능성이 있어 환경변수로 `.`을 설정하는 것은 좋지 않다.)

  * 코드나 명령어로 사용되는 "와 워드에서 사용하는 "는 다르다.

  * Pipeline(|)
    파이프라인을 통해 파이프라인 앞의 명령어의 출력값을 파이프라인 뒤의 입력값으로 사용

  * T joint(Tee)
    표준입력(stdin)에서 읽어서 표준출력(stdout)과 파일에 쓰는 명령어


### linux command

  |command|설명|
  |--|--------------------------|
  |which|실행되는 명령어의 위치 출력|
  |clear|터미널 창 정리|
  |grep|특정 문자열 찾기, stdin으로 입력 받아서 특정 단어 나오면 검출|
  |wc|줄, 단어, 글자 수 출력|

### 실습

  * ssh로 접속 시 노출되는 프롬포트 색 변경
    ```
    cp ~hwan/.profile ~hwan/.bashrc ~hwan/.bash_logout ~
    source .profile
    ```
    * shell에서 위의 명령어 실행->프롬프트가 초록색이 됨


  * Pipeline
    * shell에 `grep printf hello.c | wc` 입력 -> hello.c에 printf를 포함한 줄, 단어, 글자수 출력
  

  * Git
    1. 사용자 등록
      * `git config --global user.email "[사용자 이메일]"`
      * `git config --global user.name "[사용자 이름]"`
    2. `git clone [git repository 주소]`: 로컬에 git repository의 내용을 받아옴
    3. 원하는 내용 수정
    4. `git pull`: 서버에 업데이트 된 것이 있다면 불러옴
    5. `git add [수정한 파일]`: 수정한 파일을 staging (수정한 파일 위치에 `*`입력 시 수정된 모든 파일 staging)
    6. `git commit -m "[메시지]`: 메시지 내용으로 커밋
    7. `git push`: 서버에 수정된 내용과 커밋 업로드
  

  * Markdown
    * `#`: 제목 (`##`, `###`을 통해 부제목, 소제목 등이 가능)
    * `*`: 문장 앞 점(스페이스바 두 번을 통해 단락 나누기 가능, 중첩 가능)

      예)
      ```
      * 1234
        * 5678
      ```
      * 1234
        * 5678
    * `` ``` ``: 코드의 전후에 사용하여 코드 블록
    * `1. `, `2. `, ...: 번호 매기기
    * 엔터 두 번을 통해 줄바꿈


