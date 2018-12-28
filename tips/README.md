# 알고리즘 문제풀이 팁 정리

## 문자 입력받을때 주의할 점

### 공백문자 입력

- %d로 정수 입력을 받는다면 공백문자를 무시하지만, %c로 입력 받았을때 공백문자를 하나의 캐릭터로 입력받는다는것을 기억해야한다.
- %d로 정수 입력을 받은 후, 화이트 스페이스 이후에 오는 %c입력을 받는다면 %c는 화이트 스페이스를 입력으로 받을것이다.
- scanf(" %c", &c); 처럼, %c 앞에 공백을 둠으로써 화이트 스페이스를 무시할 수 있다.

### 문자가 ASCII범위 0~127이 아닐때.

- you should use scanf("%u") to read an unsigned int and scanf("%hhu") to read an unsigned char.

## 문자열 입력받을 때 주의할 점

- scanf("%s");는 공백문자가 오면 입력을 종료한다. 그러므로 공백문자가 포함된 한 줄을 입력받기 위해서는 fgets()함수를 사용하는것이 좋다.
- fgets() 함수는 \n가 나올때까지 입력을 받고, \n도 입력에 포함한다.
- fgets() 를 호출하기 이전 라인에서, scanf("%d");와 같이 입력을 받으면, 그라인의 \n이 버퍼에 남아있게 되고, 호줄된 fgets()함수에서는 \n하나만을 문자열로 입력받게 된다. scanf("%d "); 형식을 사용하여 화이트스페이스를 없애줄 필요가 있다.

## memset을 이용한 초기화

- [참고링크](https://twpower.github.io/79-usage-of-memset-function)

> void \* memset ( void \* ptr, int value, size_t num );
>
> - ptr : 채우고자 하는 메모리의 시작 포인터(시작 주소)
> - value : 메모리에 채우고자하는 값. int형이지만 내부에서는 unsigned char(1 byte)로 변환되어서 저장된다.
> - num : 채우고자 하는 바이트의 수. 즉, 채우고자 하는 메모리의 크기

- string.h, cstring 헤더에 정의되어 있다.
- memset함수는 어떤 메모리의 시작점부터 연속된 범위를 어떤 값으로(바이트 단위) 모두 지정하고 싶을 때 사용하는 함수이다.
- 대체로 memset함수는 특정 범위에 있는 연속된 메모리에 값을 지정하고 싶을 때 사용하는데 for문보다 더 빠른 속도가 나올수가 있다.
- 여기서 나올수가 있다라고 표현한 이유는 컴파일러 그리고 컴퓨터 아키텍처에 따라서 다르기 때문이다. 컴파일러가 자동으로 최적화를 해줌으로써 for loop을 통해서 초기화 하는것과 memset을 통해 초기화를 하는것의 어셈블리 코드가 같게 나오는 경우가 있다.

### 0으로 초기화와 -1으로 초기화 둘다 가능하다

- [참고링크](https://stackoverflow.com/questions/7202411/why-does-memsetarr-1-sizeofarr-sizeofint-not-clear-an-integer-array-t)

```C
int arr[10];

// int형 0으로 초기화 가능
// if you set all the bytes to 0, the value will be zero
memset(arr, 0, sizeof(arr));

// int형 -1으로 초기화 가능
// -1 is 0xff (=255) in int8_t and 0xffffffff in int32_t
memset(arr, -1, sizeof(arr));
```

## 알고리즘 수행 시간 어림하기

- 요즘의 컴퓨터는 대략 1억(10^8)번의 연산까지는 몇 초 안에 해낸다. 이 사실에 입각하여 알고리즘이 시간내에 작동할지를 판단해보자.
- 예를들어 입력 n의 최대크기가 10^5이고 현재 만든 알고리즘의 시간 복잡도가 O(n^2)이라면, 10^10번의 연산인 필요하고 이것은 알고리즘이 돌아가는데 수백초의 시간이 걸린다는 것이다.
- 시간 복잡도 만큼이나 문제에 나온 입력 범위가 중요하다. 입력범위가 매우 작다면 안좋은 시간복잡도를 가지는 알고리즘도 시간 안에 문제를 푸는 알고리즘일 수 있다.
