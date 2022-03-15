## Lecture 1

### linux command

  |command|설명|
  |--|--------------------------|
  |ls|현재 디렉토리의 파일의 리스트 확인(-l: 디렉토리 내 상세내용 / -a: 디렉토리 내 숨김 파일 표시)|
  |pwd|현재 디렉토리 위치 확인|
  |cd|디렉토리 위치 변경(~: home / ..: 상위 디렉토리 / .: 현재 디렉토리)|
  |cat|파일 내용 합치기 및 파일 내용 출력|
  |chmod|파일의 권한 변경(본인/그룹/이외의 사람들에게 read, write, execute 권한 제어)|
  |who|접속 중인 단말 확인|
  |wc|단어 수 count|
  |whoami|현재 사용자가 사용 중인 계정 확인|
  |groups|사용자가 속한 그룹 확인|
  |hostname|호스트 이름 확인|
  |passwd|사용 중인 계정의 비밀번호 변경|
  |vi|vi editor로 파일 open|
  |history|사용한 명령어 확인|
  |mv|파일 이름 변경, 위치 이동|
  |rm|파일 삭제(-r: 디렉토리와 디렉토리 내 파일 삭제)|


### vi editor

* Normal mode
  |key|설명|
  |--|--------------------------|
  |i|insert, 커서 위치에서 편집 모드로 전환|
  |a|append, 커서 위치의 한 칸 뒤에서 편집 모드로 전환|
  |o|커서 위치에서 한 줄 내려서 편집 모드로 전환|
  |k|커서 위치 위로 이동|
  |j|커서 위치 아래로 이동|
  |l|커서 위치 오른쪽으로 이동|
  |h|커서 위치 왼쪽으로 이동|
  |:|command mode로 이동|

* Command mode
  |key|설명|
  |-|----------|
  |w|write, 저장|
  |q|quit, vi editor 종료|
  |wq|저장하고 vi editor 종료|
  |q!|강제 종료|


### 실습 내용
* Hello World를 출력하는 파일을 만들고 실행시키기
  1. `vi hello.c`를 입력하여 `hello.c` 파일을 vi editor로 open
  2. vi editor에서 `i`를 눌러 아래의 내용을 추가한다.
    ```c
    #include <stdio.h>
  
    int main()
    {
      printf("Hello World\n"); //Comment
      return 0;
    }
    ```
  3. 키보드의 `esc` 를 통해 Normal mode로 복귀
  4. 키보드의 `:`를 통해 Command mode로 이동 후 `wq`입력 및 엔터
  5. shell에 `cc hello.c` 입력 (output 파일에 별도의 이름을 지정하지 않아 `a.out` 파일 생성)
  6. shell에 `./a.out` 입력


