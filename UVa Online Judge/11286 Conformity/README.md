# 11286 Conformity

## 문제풀이

- 각 course combination에 대해 신청한 학생의 수를 세어놓는다.
  - map을 사용하면 편하다. map의 키값으로는 신청한 과목코드를 정렬한후 string으로 만든것을 사용한다. 학생마다 5가지의 과목을 신청하는데 과목코드가 정렬이 안된상태로 신청을하므로 정렬을 해줄 필요가 있다.
  - c++의 map은 tree map이다. 이 문제에서는 사실 키값이 정렬될필요가 없으므로 hash map인 unordered_map을 쓰는게 더 빠를것이다.
    - map으로는 0.090s, unordered_map으로는 0.080s가 나왔다. 큰 차이가 없는것을 보니 역시 시간잡아먹는건 출력부분인듯하다.
    - unordered_map을 쓰고 std::ios::sync_with_stdio(false); 옵션을 주니까 0.050s가 나왔다.
- 신청한 학생의수가 최대인 course combination을 찾고, 신청한 학생의 수를 출력한다
  - 여러 course combination이 동률로 최대값을 가지면, 학생수를 다 더해서 출력해야 한다.

## WA 이유

- string의 +연산자의 기본 동작을 잘못 알고 있었다.
- Java의경우 "" + 123 같이 스트링이 있을때 +연산자로 int형을 더하면 "123"이 만들어진다. 123을 string형으로 자동으로 변환한 뒤 concatenation을 해주는 것이다.
- C++에서는 string + 123을 하면, 123이 char형으로 인식되는듯 하다.

```C++
std::string temp("");
temp = temp + std::to_string(123);
```

- int형을 명시적으로 string형으로 바꿔주기 위해서 string헤더에 선언되어있는 to_string()함수를 사용했다.
