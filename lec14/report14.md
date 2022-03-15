## report14

### 이론

  * POSIX
    * digital 회사의 과정: digital -> dec -> digital -> compacq -> hp
    * digital에서 pdp 7이라는 컴퓨터를 발명
    * pdp 11에서 c언어 개발
    * AT&T의 Bell Lab에서 UNIX 개발
    * Unix is registerd trademark. -> 소스를 닫아버림
    * 캘리포니아 주립 버클리대학 bsd를 개발했으며, 이는 ios의 기반이 됨.
    * free software, GNU 개발 (GNU is Not Unix)
    * 리누즈 토팔즈가 GNU를 기반으로 Linux 개발
    * bsd, mac os, gnu, linux는 모두 unix 기반이지만 명령어에 약간의 차이가 존재함
    * POSIX(Portable Operating System Interface)는 이러한 다른 운영체제 간 호환성을 위한 표준

  * Buffer
    * Input buffer: stdin(0>) / Output buffer: stdout(1>), stderr(2>)
    * Buffer는 FIFO 형태이다.
    * Buffer mode
      1. buffer full
         - 버퍼가 꽉 찼을 경우 처리
      2. line by line
         - 한 줄씩 처리
         - default
      3. character by character (buffer X, zero-buffer)
         - 한 글자씩 처리
    * `stdbuf`: 리눅스에서의 표준 버퍼 명령어 (프로그램 외부에서 버퍼 크기 지정)
      * -i,--input=MODE: input stream buffering
      * -o,--output=MODE: output stream buffering
      * -e,--error=MODE: error stream buffering
      * MODE가 L일 때는 line buffered, 0일 때는 unbuffered이다. 또한 KB, K, MB, M 등으로 설정이 가능하다.

      e.g) `stdbuf -output=0`
    * `flush`: buffer를 지우는 명령어
    * I/O의 overhead가 크기 때문에 buffer의 크기를 늘려주면 성능이 향상된다.
    * Buffer = Stream(c++)
    * `int setvbuf(FILE *restrict stream, char *restrict buf, int mode, size_t size);`: 버퍼의 크기를 조정하는 함수 (프로그램 내부에서 버퍼 크기 지정)
      - _IONBF: Unbuffered
      - _IOLBF: Line buffered
      - _IOFBF: Fully buffered

      e.g) 
      ```c
      // 메인에서 한 번만 실행해주면 됨
      char bufff[10];
      setvbuf(stdout, bufff, _IOFBF, 10);
      ```
    * `int fflush(FILE *stream);`: buffer를 flush하는 함수

      e.g) `fflush(stdout);`
    
    * `scanf`와 `printf`를 사용할 때에는 변수의 데이터 타입과 포멧의 데이터 타입이 일치해야 한다.

      e.g)
      ```c
      #include <stdio.h>

      int main()
      {
	      char      a;
	      short     b;
	      int       c;
	      long long d;

	      scanf("%hhd %hd %d %lld", &a, &b, &c, &d); // char:hhd / short:hd / int:d / long long:lld
	      printf("%hhd %hd %d %lld\n", a, b, c, d);
      }
      ```
  * Synchronous VS Asynchronous
    * Synchronous: thread가 종료되고 나서 다른 thread를 실행하는 방식
    * Asynchronous: 새로운 프로세스를 만들어 다른 thread를 할당받음
      
      -> thread끼리 공유하는 자원에 동기화 문제를 발생시킬 수 있음 (예: 두 은행에서 한 계좌로 동시에 입금과 출금)

      -> **Mutex**(Mutual Exclusion)을 통해 한 스레드가 자원을 사용하는 동안 다른 스레드가 자원에 접근하지 못하도록 함.

### 실습

  * Synchronization
    * 아래와 같은 내용으로 `threadtest.c`파일을 생성한 후 컴파일 및 실행한다.(`-lpthread`옵션 추가 필요)
      ```c
      #include <stdio.h>
      #include <sys/types.h>
      #include <unistd.h>
      #include <stdlib.h>
      #include <pthread.h>

      int bbb = 0; 

      void fn_s()
      {
          static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
          static int a = 0; 
          printf("<= %d %d =>", a++, bbb++);
          fflush(stdout);
      }

      void *run (void *arg)
      {
          printf("Hello world of POSXI threads.%d\n", (int) pthread_self() );
          for (int i = 0; i < 100; i++)
	      {
		      usleep(10000); 
		      fn_s(); 
	      }
         return 0;
      }

      int main()
      {
	      pthread_t thread1;
          int result1;

	      pthread_create(&thread1, NULL, run, NULL );
	      pthread_join(thread1, (void **) &result1);

	      printf("\nThread return %d at the end\n", result1);
      }
      ```
      결과: thread가 종료되고 printf문이 출력된다.
      ```
      $ a.out
      Hello world of POSXI threads.-556345600
      <= 0 0 =><= 1 1 =><= 2 2 =><= 3 3 =><= 4 4 =><= 5 5 =><= 6 6 =><= 7 7 =><= 8 8 =><= 9 9 =><= 10 10 =><= 11 11 =><= 12 12 =><= 13 13 =><= 14 14 => ... <= 99 99 =>
      Thread return 0 at the end
      ```
  * Asynchronous execution
    * 아래와 같은 내용으로 `threadtest.c`파일을 수정한 후 컴파일 및 실행한다.(`-lpthread`옵션 추가 필요)
      ```c
      #include <stdio.h>
      #include <sys/types.h>
      #include <unistd.h>
      #include <stdlib.h>
      #include <pthread.h>

      int bbb = 0; 

      void fn_s()
      {
          static int a = 0; 
          printf("<= %d %d =>", a++, bbb++);
          fflush(stdout);
      }

      void *run (void *arg)
      {
          printf("Hello world of POSXI threads.%d\n", (int) pthread_self() );
          for (int i = 0; i < 100; i++)
	      {
		      usleep(10000); 
		      fn_s(); 
	      }
         return 0;
      }

      int main()
      {
	      pthread_t thread1;
          int result1;

	      pthread_create(&thread1, NULL, run, NULL );
          printf("JUST AFTER THR Create\n");
          run((void *) 0);
	      pthread_join(thread1, (void **) &result1);

	      printf("\nThread return %d at the end\n", result1);
      }
      ```
      결과: 199까지 출력되지만 반복문의 횟수를 급격히 증가시키면 실행시킬 때마다 마지막에 출력되는 숫자가 다르다.
      ```
      $ a.out
      JUST AFTER THR create
      Hello world of POSXI threads.1466042176
      Hello world of POSXI threads.1457563392
      <= 0 0 =><= 1 1 =><= 2 2 =><= 3 3 =><= 4 4 =><= 5 5 =><= 6 6 =><= 7 7 =><= 8 8 =><= 9 9 =><= 10 10 =><= 11 11 =><= 12 12 =><= 13 13 =><= 14 14 => ... <= 199 199 =>
      Thread return 0 at the end
      ```
    
  * Mutex
    * 아래와 같은 내용으로 `threadtest.c`파일을 수정한 후 컴파일 및 실행한다.(`-lpthread`옵션 추가 필요)
      ```c
      #include <stdio.h>
      #include <sys/types.h>
      #include <unistd.h>
      #include <stdlib.h>
      #include <pthread.h>

      int bbb = 0; 

      void fn_s()
      {
          static int a = 0; 
          printf("<= %d %d =>", a, bbb);
          pthread_mutex_lock(&mutex);
	      a++; bbb++;
    	  pthread_mutex_unlock(&mutex);
      }

      void *run (void *arg)
      {
          printf("Hello world of POSXI threads.%d\n", (int) pthread_self() );
          for (int i = 0; i < 100; i++)
	      {
		      usleep(10000); 
		      fn_s(); 
	      }
         return 0;
      }

      int main()
      {
	      pthread_t thread1, thread2, thread3;
          int result1, result2, result3;

	      pthread_create(&thread1, NULL, run, NULL );
          pthread_create(&thread2, NULL, run, NULL );
          pthread_create(&thread3, NULL, run, NULL );
          printf("JUST AFTER THR Create\n");
          run((void *) 0);
	      pthread_join(thread1, (void **) &result1);
          pthread_join(thread2, (void **) &result2);
          pthread_join(thread3, (void **) &result3);

	      printf("\nThread return %d at the end\n", result1);
      }
      ```
      결과: 모든 thread가 순서대로 실행되어 399까지 출력된다.
      ```
      $ a.out
      Hello world of POSXI threads.2117785344
      Hello world of POSXI threads.2109392640
      Hello world of POSXI threads.2126264128
      Hello world of POSXI threads.2100999936
      <= 0 0 =><= 0 0 =><= 2 2 =><= 3 3 =><= 4 4 =><= 5 5 =><= 6 6 =><= 7 7 =><= 8 8 =>...
      <=399 399=>
      Thread return 0 at the end
      ```
