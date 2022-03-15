## Lecture 06

### 이론
  * Pointer / Address
    * Pointer basic
        * `&val` : Address of val
        * `*ptr` : Value in address val
        * increment
            * `int *a;` : a++ increment by 4
            * `long long *b;` : b++ increment by 8
            * `void *c;` : c++ increment by 1
    
    * int an_array[] vs int *a_pointer
        * `int an_array[32];`
            * 스텍에 32개의 integer를 위한 공간을 확보
            * an_array가 포인터임을 선언하고 새로 할당된 공간을 가르키도록 포인터를 binding
        * `int *a_pointer;`
            * just pointer
            * a_pointer = malloc(32*4);

    * Noun-Adjective Form
        * `int const`
            A constant integer
        * `int const *`
            A (variable) pointer to a constant integer
        * `int * const`
            A constant pointer to a (variable) integer
        * `int * const *`
            A pointer to a constant pointer to an integer
        * `int contst **`
            A pointer to a pointer to a constant integer
        * `int const * consst *`
            A pointer to a constant pointer to a constant integer
        
### vi editor

* Normal mode
  |key|설명|
  |--|--------------------------|
  |dw|현재 커서위치 한 단어 삭제|
  |zz|현재 커서위치를 화면의 가운데로 보이도록 위치 이동|


### 실습

  * Alias
    *  `alias -p`를 통해 현재 alias 상태를 확인할 수 있다.
        ```
        $ alias -p
        alias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echoe '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'
        alias egrep='egrep --color=auto'
        alias fgrep='fgrep --color=auto'
        alias grep='grep --color=auto'
        alias h='history'
        alias l='ls -CF'
        alias la='ls -A'
        alias ll='ls -alF'
        alias ls='ls --color=auto'
        ```
    * `alias [alias 이름]='alias 할 내용`을 통해 새로운 alias 생성이 가능하다.
        ```
        $ alias cc='cc -Wall'
        $ alias -p
        alias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echoe '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'
        alias cc='cc -Wall'
        alias egrep='egrep --color=auto'
        alias fgrep='fgrep --color=auto'
        alias grep='grep --color=auto'
        alias h='history'
        alias l='ls -CF'
        alias la='ls -A'
        alias ll='ls -alF'
        alias ls='ls --color=auto'
        ```
    * `\[명령어]`를 사용하면 alias를 사용하지 않고 명령어를 실행한다.
        ```
        $ \ls
        a.out bin binary.c count1 count1.c hello.c
        ```
    * `unalias [alias 이름]`을 통해 alias를 삭제할 수 있다.
        ```
        $ unalias cc
        $ alias -p
        alias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echoe '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'
        alias egrep='egrep --color=auto'
        alias fgrep='fgrep --color=auto'
        alias grep='grep --color=auto'
        alias h='history'
        alias l='ls -CF'
        alias la='ls -A'
        alias ll='ls -alF'
        alias ls='ls --color=auto'
        ```
    * `.bashrc` 파일에서 alias의 내용을 수정할 수 있다.

  * Pointer / Address
    * `cc [컴파일 할 c파일] && a.out`을 통해 컴파일이 성공 시에 a.out을 실행하도록 할 수 있다.
    * `cc [컴파일 할 c파일] ; a.out`은 컴파일이 성공하지 않더라도 기존에 a.out이 있다면 실행한다.
    * `cc [컴파일 할 c파일] || echo "error"`를 통해 컴파일 오류시 error 메시지를 출력하도록 할 수 있다.
    * 아래의 코드를 실행하여 정수형 변수들의 값과 주소를 확인할 수 있다.
        ```c
        #include <stdio.h>

        int main()
        {
	        int a = 100;
	        int b = 200;
	        // int * == long long
	
	        fprintf(stdout, "%d : %lld %llx\n", a, &a, &a);
	        fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
	        *&b = 500;
	        fprintf(stdout, "%d : %lld %llx\n", *&b, &b, &b);
        }
        ```
        결과:
        ```
        100 : 140728219634992 7ffdd78a8d30
        200 : 140728219634996 7ffdd78a8d34
        500 : 140728219634996 7ffdd78a8d34
        ```
        b의 address는 변함이 없지만, value는 변했다.
    * 아래의 코드를 실행하여 포인터를 매개변수로 하는 함수의 기능을 확인할 수 있다.
        ```c
        #include <stdio.h>

        int add(int *a, int *b)
        {
	        return *a+*(a+2);
        }
	
        int main()
        {
	        int a = 100;
	        int b = 200;
	        int c = 999;
	        // int * == long long
	
            fprintf(stdout, "%d : %lld %llx\n", a, &a, &a);
	        fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
	        c = add(&a, &b);
	        fprintf(stdout, "%d : %lld %llx\n", c, &c, &c);
        }
        ```
        결과: 
        ```
        100 : 140733593713244 7fff17dc7a5c
        200 : 140733593713248 7fff17dc7a60
        1099 : 140733593713252 7fff17dc7a64
        ```
        add 함수를 통해 a와 a의 8바이트 뒤에 저장된 c의 값이 합쳐져 c에 저장되었다.

    * 아래의 코드를 실행하여 return이 void인 함수에서도 c의 값이 변하는 것을 확인할 수 있다.
        ```c
        #include <stdio.h>

        void add(int *a, int *b, int *c)
        {
	        *c = *a + *(a+1);
        }
	
        int main()
        {
	        int a = 100;
	        int b = 200;
	        long long c = 999;
	        // int * == long long
	
	        fprintf(stdout, "%d : %lld %llx\n", a, &a, &a);
	        fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
	        add(&a, &b, &c);
	        // c = a + b;
	        fprintf(stdout, "%d : %lld %llx\n", c, &c, &c);
	        fprintf(stdout, "%d : %lld %llx\n", c, (&c)+1, &c+1);
	        fprintf(stdout, "%d : %lld %llx\n", c, (&c)+2, &c+2);
        }
        ```
        결과:
        ```
        100 : 140729639384616 7ffe2c2a3628
        200 : 140729639384620 7ffe2c2a362c
        300 : 140729639384624 7ffe2c2a3630
        300 : 140729639384632 7ffe2c2a3638
        300 : 140729639384640 7ffe2c2a3640
        ```
    * 아래 코드를 실행하여 배열이 함수의 매개변수인 경우와 배열의 크기를 초과했을 때의 상황을 확인할 수 있다.
        ```c
        #include <stdio.h>

        int sumArray3(int *a, int sum)
        {
	        sum = *a;
	        a++;
	        sum += *a;
	        a++;
	        sum += *a;
	        fprintf(stdout, "%d : %lld %llx\n", sum, &sum, &sum);
	        return a[3];
        }
	
        int main()
        {
	        int a = 100;
	        int b = 200;
	        int c = 999;
	        int arr[4] = {100, 200, 300, 400};
	        int *parr;
	        parr = arr;
	        parr++;
	        fprintf(stdout, "%d : %lld %llx\n", *parr, parr, arr);

	        c = sumArray3(arr, b);	
	
	        fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
	        fprintf(stdout, "%d : %lld %llx\n", arr, arr, arr);
	        fprintf(stdout, "%d : %lld %llx\n", *arr, *arr, *arr);
	        fprintf(stdout, "%d : %lld %llx\n", &arr, &arr, &arr);
	        fprintf(stdout, "%d : %lld %llx\n", arr[2], &arr[2], &arr[2]);
	        fprintf(stdout, "%d : %lld %llx\n", arr[3], &arr[3], &arr[3]);
	        fprintf(stdout, "%d : %lld %llx\n", arr[4000], &arr[4000], &arr[4000]);
        }
        ```
        결과:
        ```
        200 : 140723815458772 7ffcd10827d0
        600 : 140723815458708 7ffcd1082794
        200 : 140723815458748 7ffcd10827bc
        -787994672 : 140723815458768 7ffcd10827d0
        100 : 100 64
        -787994672 : 140723815458768 7ffcd10827d0
        300 : 140723815458776 7ffcd10827d8
        400 : 140723815458780 7ffcd10827dc
        Segmentation fault (core dumped)
        ```







