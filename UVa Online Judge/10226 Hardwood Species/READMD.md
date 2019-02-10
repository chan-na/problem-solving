# 10226 Hardwood Species

## GNU C++ 컴파일러에서 getline의 동작

### 내 실행환경 g++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0

- getline()이 뉴라인 캐릭터를 인풋에 포함시키다.
- getline은 delimiter를 스트림에서 버리지만 delimiter는 입력값으로 사용하지 않는다고 알고있었다. 그리고 비주얼 스튜디오 컴파일러에서는 실제로 그렇다.
- 그래서 뉴라인 캐릭터가 인풋에 포함되는 문제 때문에 WA가 난줄알고 string에 pop_back() 함수가 존재하기 때문에, 이 함수를 사용해서 new line캐릭터를 제거했다.
  - 그러나 이 문제가 아니었음

### UVa 실행환경 C++11 5.3.0 - GNU C++ Compiler with options: -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE

- getline()은 내가 알던대로 delimiter를 인풋에 포함하지 않도록 잘 동작한다.

## WA의 이유

### 가장 마지막의 input이 \n으로 끊나지 않고 EOF로 끝날수도 있다.

- 마지막 인풋값이 EOF로 끝날경우와 마지막 인풋값이 \n후에 EOF로 끝나는경우 둘다를 처리할수 있도록 짜야한다.
