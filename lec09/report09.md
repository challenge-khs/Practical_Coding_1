## report 09

### 이론
  * CPU의 주요 기능
    1. ALU (Arithmetic Logic Unit)
      연산을 담당하는 영역으로 사칙 연산과 논리 연산을 수행한다.
    2. CU (Control Unit)
      명령어를 해석하고 레지스터와 ALU 사이의 명령 흐름을 제어한다.
    3. 레지스터
      임시로 데이터를 기억하는 장치

  * ulimit
    소프트웨어 및 하드웨어 한도를 설정하는 명령어

  * Debugging
    * Debug
      프로그램 개발 단계 중 발생하는 시스템의 논리적인 오류나 비정상적인 연산을 찾아내고 그 원인을 밝히고 수정하는 작업 과정.
    * `gcc -g `를 통해 컴파일 시 debug option을 추가할 수 있다.
    * gdb - GNU Debugger
      * Command
        * alias - ni, where
        * breakpoints - break, delete
        * data - print
        * file - cd, list, load, file, search, pwd
        * obscure - compile, record
        * run - run, continue, start, step, next
        * stack - bt, backtrace, down, frame, return, up
        
        
        |Command|Meaning|
        |-------|-------|
        |ni|어셈블리 명령어 단위의 수행|
        |where|에러의 발생 위치 출력|
        |break|break point 설정|
        |delete|break point 삭제|
        |print|수식의 값을 보여줌|
        |list|현재 위치에서 소스파일 내용을 10줄 출력|
        |pwd|작업 디렉토리 출력|
        |run|프로그램 수행|
        |step|현재 행 수행 후 정지, 함수 호출 시 함수 안으로 이동|
        |next|현재 행 수행 후 정지, 함수 호출 시 함수 수행 다음행으로 이동|
        |bt|전체 스택 프레임 출력(콜스택)|
        |watch|특정 변수에 watch point를 설정하고, 특정 변수가 바뀔 때마다 break가 걸리면서 이전/현재 값을 출력한다.|
        |quit|gdb 종료|

### 실습
  * ulimit
    * `ulimit -a`를 통해 모든 제한 사항을 확인할 수 있다.
      ```
      $ ulmit -a
      core file size          (blocks, -c) 0
      data seg size           (kbytes, -d) unlimited
      scheduling priority             (-e) 0
      file size               (blocks, -f) unlimited
      pending signals                 (-i) 256271
      max locked memory       (kbytes, -l) 65536
      max memory size         (kbytes, -m) unlimited
      open files                      (-n) 1024
      pipe size            (512 bytes, -p) 8
      POSIX message queues     (bytes, -q) 819200
      real-time priority              (-r) 0
      stack size              (kbytes, -s) 8192
      cpu time               (seconds, -t) unlimited
      max user processes              (-u) 256271
      virtual memory          (kbytes, -v) unlimited
      file locks                      (-x) unlimited
      ```

  * Debugging
    * `cc -g`를 통해 컴파일 시 degug 옵션을 추가할 수 있다. debug 옵션을 통해 만들어진 실행 파일은 더 큰 용량을 가지며 `file` 명령어를 통해 debug 옵션에 대한 내용을 확인할 수 있다.
      ```
      $ cc test.c
      $ ls -al
      total 32
      drwxr-xr-x  2 pcc009 pcc 4096  1월 18 15:52 .
      drwxr-xr-x 13 pcc009 pcc 4096  1월 18 15:30 ..
      -rwxr-xr-x  1 pcc009 pcc 8616  1월 18 15:52 a.out
      -rw-r--r--  1 pcc009 pcc  878  1월 18 15:52 test.c
      -rw-r--r--  1 pcc009 pcc 2992  1월 18 15:39 test.o
      -rw-r--r--  1 pcc009 pcc  697  1월 18 15:33 ulimit.txt
      $ cc -g test.c
      $ ls -al
      total 32
      drwxr-xr-x  2 pcc009 pcc  4096  1월 18 15:52 .
      drwxr-xr-x 13 pcc009 pcc  4096  1월 18 15:30 ..
      -rwxr-xr-x  1 pcc009 pcc 11576  1월 18 15:52 a.out
      -rw-r--r--  1 pcc009 pcc   878  1월 18 15:52 test.c
      -rw-r--r--  1 pcc009 pcc  2992  1월 18 15:39 test.o
      -rw-r--r--  1 pcc009 pcc   697  1월 18 15:33 ulimit.txt
      $ file a.out
      a.out: ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 3.2.0, BuildID[sha1]=0898c6b154b5b0a175c7d78a6062ec210bd2bf16, with debug_info, not stripped
      ```
    * gdb
      * `gdb <실행파일>`을 통해 gdb을 실행시킬 수 있다.
        ```
        $ gdb a.out
        GNU gdb (Ubuntu 8.1-0ubuntu3) 8.1.0.20180409-git
        Copyright (C) 2018 Free Software Foundation, Inc.
        License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
        This is free software: you are free to change and redistribute it.
        There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
        and "show warranty" for details.
        This GDB was configured as "x86_64-linux-gnu".
        Type "show configuration" for configuration details.
        For bug reporting instructions, please see:
        <http://www.gnu.org/software/gdb/bugs/>.
        Find the GDB manual and other documentation resources online at:
        <http://www.gnu.org/software/gdb/documentation/>.
        For help, type "help".
        Type "apropos word" to search for commands related to "word"...
        Reading symbols from a.out...done.
        (gdb) 
        ```
      * `list`통해 현재 코드의 내용을 볼 수 있으며 특정 라인을 확인하거나 함수를 확인하는 것도 가능하다.
        ```
        (gdb) list
        1893    in vfscanf.c
        (gdb) list main
        28      {
        29              return a + b;
        30
        31      }
        32      int main()
        33      {
        34              long long i = 0;
        35              int ia, ib, ic, ic2;
        36              float fa;
        37              fscanf(stdin, "%d %d", &ia, ib);
        (gdb) list 10
        5       #define FX_2_MINUS_16 1.52587890625e-05F
        6       #define FX_2_PLUS_16 (1<<16)
        7       #define FX_S_15_16 11516
        8       #define FX_SYSTEM FX_S_15_16
        9
        10      typedef int fixed32;
        11
        12      fixed32 fromFloat(float fa)
        13      {
        14              return (fixed32) (fa * FX_2_PLUS_16);
        (gdb) list 30,70
        30
        31      }
        32      int main()
        33      {
        34              int i = 0;
        35              int ia, ib, ic, ic2;
        36              float fa;
        37              fscanf(stdin, "%d %d", &ia, &ib);
        38              for(i = 0; i < 64*256*256*256; i+=(256*256))
        39              {
        40                      ic = fxAdd(i, i);
        41                      ic2 = fxAdd2(i, i);
        42                      fprintf(stdout, "%f + %f : %f, %f diff = %d\n", toFloat(i), toFloat(i), toFloat(ic), toFloat(ic2), ic - ic2);
        43              }
        44              fprintf(stdout, "%d + %d : %d\n", ia, ib, ic);
        45      }
        ```
      * `break`를 통해 특정 라인까지 실행하도록 설정 할 수 있으며 breakpoint들은 스택구조로 저장된다. breakpoint들은 `delete`를 통해 삭제된다. 또한 `next`를 통해 현재 행을 실행시킬 수 있다.
        ```
        (gdb) list main
        28      {
        29              return a + b;
        30
        31      }
        32      int main()
        33      {
        34              int i = 0;
        35              int ia, ib, ic, ic2;
        36              float fa;
        37              fscanf(stdin, "%d %d", &ia, &ib);
        (gdb) break 34
        Breakpoint 1 at 0x833: file test.c, line 34.
        (gdb) run
        Starting program: /home/course/pcc009/pcc/lec09/a.out

        Breakpoint 1, main () at test.c:34
        34              int i = 0;
        (gdb) next
        37              fscanf(stdin, "%d %d", &ia, &ib);
        (gdb) next
        500 500
        38              for(i = 0; i < 64*256*256*256; i+=(256*256))
                    .
                    .
                    .
        (gdb) info break
        Num     Type           Disp Enb Address            What
        2       breakpoint     keep y   0x0000555555554833 in main at test.c:34
        breakpoint already hit 1 time
        3       breakpoint     keep y   0x0000555555554833 in main at test.c:34
        breakpoint already hit 1 time
        4       breakpoint     keep y   0x00005555555547a3 in fromFloat at test.c:14
        breakpoint already hit 1 time
        (gdb) delete breakpoints
        Delete all breakpoints? (y or n) y
        ```

---
### Project
  * 고정소수점 프로젝트
    * `#define FX_S32_31` 은 signed long long을 써서 1bit는 부호, 32bits는 정수, 31bits는 소수로 나타낸다.
      * 64bits -> long long
      * 32bits -> int
      * 16bits -> short
      * 8bits  -> char
    * float을 고정소수점을 위한 형태로, 고정소수점 형태에서 float으로 바꾸는 함수와 두 값을 더하는 함수
      ```c
      #include <stdio.h>
      // #### #### #### #### . #### #### #### ####
      // S 15 . 16
      #define FX_Q_NUM 16
      #define FX_2_MINUS_16 1.52587890625e-05F
      #define FX_2_PLUS_16 (1<<16)
      #define FX_S_15_16 11516
      #define FX_SYSTEM FX_S_15_16

      typedef int fixed32;

      fixed32 fromFloat(float fa)
      {
	      return (fixed32) (fa * FX_2_PLUS_16);
      }

      float toFloat(fixed32 xa)
      {
	      return ((float) (xa)) * FX_2_MINUS_16;
      }

      fixed32 fxAdd(fixed32 a, fixed32 b)
      {
	      return fromFloat(toFloat(a) + toFloat(b));
      }

      fixed32 fxAdd2(fixed32 a, fixed32 b)
      {
	      return a + b;
      }

      int main() 
      {
	      long long i = 0;
	      int ia, ib, ic, ic2;
	      float fa;
	      //fscanf(stdin, "%d %d", &ia, &ib);
	      for(i = 0; i < (long long) 256*256*256*256; i+=(256*256))
	      {
		      ic = fxAdd(i, i);
		      ic2 = fxAdd2(i, i);
		      fprintf(stdout, "%f + %f : %f, %f diff = %d\n", toFloat(i), toFloat(i), toFloat(ic), toFloat(ic2), ic - ic2);
	      }
	      //fprintf(stdout, "%d + %d : %d\n", ia, ib, ic);
	      //fprintf(stdout, "%f + %f : %f\n", toFloat(ia), toFloat(ib), toFloat(ic));	
	      //fprintf(stdout, "%f + %f : %f\n", toFloat(ia), toFloat(ib), toFloat(ic));
      }
      ```