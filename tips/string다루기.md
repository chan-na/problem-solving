## int값을 string으로 바꾸는 법 - int값을 strnig에 concatenation하기

```C++
#include <string>

int num = 123;
string temp("");

// 컴파일 오류가 난다. string과 int형 + 정의되어있지 않다고
// 저번에는 동작을 하긴 했었는데... int형을 char형으로 바꿔서 추가해주는것 같았음
// temp = temp + num;

temp = temp + std::to_string(123);  // temp가 "123"이 된다.
```

- Java에서는 String과 숫자형을 같이 +연산하면 숫자형을 String으로 변환한뒤에 concatenation해준다.
- C++에서는 int형을 명시적으로 string형으로 바꾸어 준 다음에 concatenation해야한다.
- int형을 string형으로 바꿔주기 위해 std::to_string() 함수를 사용한다.
