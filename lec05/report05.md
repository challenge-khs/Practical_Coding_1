## Lecture 5

### 이론
  * Type
    * Unsigned & Signed
      * unsigned int와 signed int의 경우 저장된 데이터는 같으나 표현하는 방법이 다르다. (a.out 내용은 실습 참고)
        ```
        $ a.out
        -1
        Signed Integer : -1
        Unsigned Integer : 4294967295
        ```
      * C언어에서 unsigned int는 `%u`의 format을 갖는다.
      * signed int의 음수 값을 오른쪽 shift를 하게된다면 부호를 나타내는 1이 계속 shift되어 문제를 발생시킬 수 있다.
      * 연산자 우선순위
        |우선순위|연산자|결합방향|
        |--|--|--|
        |1|`x++` `x--` `()` `[]` `.` `->` `(자료형){값}`|->|
        |2|`++x` `--x` `+x` `-x` `!` `~` `(자료형)` `*x` `&x` `sizeof`|<-|
        |3|`*` `/` `%`|->|
        |4|`+` `-`|->|
        |5|`<<` `>>`|->|
        |6|`<` `<=` `>` `>=`|->|
        |7|`==` `!=`|->|
        |8|`&`|->|
        |9|`^`|->|
        |10|`|`|->|
        |11|`&&`|->|
        |12|`||`|->|
        |13|`? :`|<-|
        |14|`=` `+=` `-=` `*=` `/=` `%=` `<<=` `>>-` `&=` `^=` `|=`|<-|
        |15|`,`|->|


    * Three basic memory model in C
      * type 뒤에 표기하는 것을 추천 
      
        e.g) `int static a = 0`
      * Automatic
        * 아무것도 선언하지 않는다면 자동으로 automatic
        * 처음에 선언할 시 값이 assign 되어야 함
        * 범위를 벗어나면 값이 사라진다.
      * Static
        * 초기화를 필요로 하며, 초기화가 없다면 0이나 NULL로 할당한다.
        * 값이 사라지지 않는다.
        * 함수 내에 선언한 static 변수는 함수가 종료되어도 값을 유지한다.

      * Manual
        * 어떠한 메모리에 사용자가 직접 allocate
    
    * Const
      * ~~const 값은 메모리에 저장되지 않는다.~~
      * Read-only, 수정 불가
        

### linux command

  |command|설명|
  |--|--------------------------|
  |more|긴 파일을 읽는 데 사용|
  |less|파일을 읽는 데 사용, 아래서 위로 읽는 것도 가능|


### vi editor

* Normal mode
  |key|설명|
  |--|--------------------------|
  |~|소문자 대문자 전환|
  |y|줄 복사(숫자+y: 숫자만큼 줄 복사 / yy: 커서가 있는 줄 복사)|
  |p|버퍼에 저장된 값 붙여놓기|
  |d|삭제 및 버퍼에 저장(dd: 줄 삭제)|

### 실습
  
  * Unsigned & Signed
    1. 아래 내용과 같은 `hello.c` 파일을 생성한다.
        ```c
        #include <stdio.h>

        int main()
        {
          signed int in_a;
          unsigned int un_a;

          fscanf(stdin, "%d", &in_a);
          fprintf(stdout, "Signed Integer : %d\n", in_a);
          un_a = in_a;
          fprintf(stdout, "Unsigned Integer :  %u\n", un_a);
        }
        ```
    2. shell에 `cc hello.c` 입력
    3. shell에 `./a.out` 을 입력하고 임의의 숫자를 입력
    4. `hello.c`를 아래 내용으로 수정한다.
        ```c
        #include <stdio.h>
        
        int main()
        {
          signed int siA;
          unsigned int unA;
          signed int sumS;
          unsigned int sumU;
          
          signed short shortS;
          unsigned short ushortS;
          
          fscanf(stdin, "%d", &siA);
          fprintf(stdout, "Signed Integer : %d\n", siA); 
          unA = siA;
          fprintf(stdout, "Unsigned Integer : %u\n", unA); 
          fprintf(stdout, "Unsigned Integer %%d : %d\n", unA); 
          fprintf(stdout, "Signed Integer %%u : %u\n", siA); 
          
          sumS = siA + (signed int) unA;
          sumU = (unsigned int) siA + unA;
          fprintf(stdout, "sumS %%d : %d\n", sumS); 	
          fprintf(stdout, "sumS %%u : %u\n", sumS); 
          fprintf(stdout, "sumU %%d : %d\n", sumU); 
          fprintf(stdout, "sumU %%u : %u\n", sumU);
          
          shortS = (short) siA + (short) unA;
          ushortS = (unsigned short) siA + (unsigned short) unA;
          fprintf(stdout, "sumS %%d : %d\n", shortS); 
          fprintf(stdout, "sumS %%u : %u\n", shortS); 
          fprintf(stdout, "sumU %%d : %d\n", ushortS); 
          fprintf(stdout, "sumU %%u : %u\n", ushortS); 
          
          shortS = siA + unA;
          ushortS = siA + unA;
          fprintf(stdout, "sumS %%d : %d\n", shortS); 
          fprintf(stdout, "sumS %%u : %u\n", shortS); 
          fprintf(stdout, "sumU %%d : %d\n", ushortS); 
          fprintf(stdout, "sumU %%u : %u\n", ushortS); 
        }
        ```
    5. shell에 `cc hello.c` 입력
    6. shell에 `./a.out` 을 입력하고 임의의 숫자를 입력
        ```
        $ a.out
        -1
        Signed Integer : -1
        Unsigned Integer : 4294967295
        Unsigned Integer %d : -1
        Signed Integer %u : 4294967295
        sumS %d : -2
        sumS %u : 4294967294
        sumU %d : -2
        sumU %u : 4294967294
        sumS %d : -2
        sumS %u : 4294967294
        sumU %d : 65534
        sumU %u : 65534
        sumS %d : -2
        sumS %u : 4294967294
        sumU %d : 65534
        sumU %u : 65534
        ```
  
  * Count number of 1 (binary)
    1. 아래와 같은 내용으로 `count1.c` 파일 생성
        ```c
        #include <stdio.h>  
        #define VALUE_ONE 1

        int count_one(unsigned int a)
        {
	        int const con = 100;
	        int static numCalls = 0;
	        int i, count = 0;

	        while(a != 0)
	        {
		        count += a & 1;
		        a >>= 1;
		        // a는 unsigned int 여야함
	        }
          
            fprintf(stderr, "Call : %d\n", numCalls);
	        numCalls++;
	        return count;
        }

        int main()
        {
	        int i;
	        int in_a;
	        fscanf(stdin, "%u", &in_a);
	        fprintf(stdout, "%u \t : ", in_a);
	        for (i = 31; i >= 0; i--) 
	        {
		        fprintf(stdout, "%d", ((in_a >> i) & 1));
		        if(i%4 == 0)
			        fprintf(stdout, " ");
	        }
	        fprintf(stdout, ": %d \n", count_one(in_a));
            //count_one(in_a);  // 여러 번 호출하여 static 변수 numCalls 확인 가능
	        fprintf(stdout, ": %d \n", in_a);
        }
        ```
    2. `cc -o count1 count1.c`를 이용하여 실행파일 생성
    3. shell에 `count` 입력 후 임의의 숫자 입력
        ```
        $ count1
        -1
        Call : 0
        4294967295       : 1111 1111 1111 1111 1111 1111 1111 1111 : 32
        : -1
        ```