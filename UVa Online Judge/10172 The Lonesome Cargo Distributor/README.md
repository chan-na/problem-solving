# 10172 The Lonesome Cargo Distributor

- 문제가 길지만 읽어보면, 각 스테이션의 platform은 cargo를 queue형태로 보관하고, carrier는 cargo를 stack형태로 보관한다는것이 나와있다. 즉 어떤 자료구조를 택해야하는지가 그대로 나와있다.
  - 나는 둘다 deque을 사용해서 구현하였다. deque에는 clear() 함수가 있어서 초기화하기가 간편했기 때문이다.
- 문제에 나와있는 방식 그대로 시뮬레이션을 하면되는 문제인데, 생각보다 코드가 복잡하다.
