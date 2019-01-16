# 11926 Multitasking

- [x .. y] 가 나왔을때 x<= i < y 인 i 인덱스에 표시함으로써 [2 .. 5][5 .. 6] 은 안겹쳐야 하는 문제를 해결
  - start < end가 보장되기 때문에 이렇기 할 수 있음
- repetition task의 경우. 최종적으로 start는 백만 이하이지만 end는 백만 이상일 경우가 생기는데, 이때 [start .. 백만]까지를 표시해줘야한다.
