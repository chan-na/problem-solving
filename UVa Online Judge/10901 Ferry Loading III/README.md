# 10901 Ferry Loading III

## Wrong Answer 이유

- 출력방식을 맞춰주지 않았다.
- 내가 푼 풀이에서는 차가 도착했을때 출력을 했는데 그러면 안된다.
- 차량이 입력에서 들어오는 순서대로, 언제 도착하는것인지를 출력해야한다. - 생각해보면 당연하다. 도착한 시간만 출력하므로 도착한 순서대로 출력을 하면 어떤 차가 도착했는지를 알수 없기 때문이다.

## 풀이

### 저장방법

- **입력에서 strictly none-decreasing order로 차량을 제시해준다**
- 입력된 차량은 통합차량큐에 일단 저장한다. 이곳에는 아직 도착하지 않은 차량들이 저장되어있다.
- 왼쪽 bank를 위한큐와 오른쪽 bank를 위한큐를 만들어서, 현재 시간에 bank에 도착한 차량을 관리한다.
- 답을 차량이 입력된 순서대로 출력해야한다. 그런데 도착한 순서는 뒤바뀔 수 있으므로 차량 입력순으로 도착 시간을 저장하는 벡터를 만들어서 한꺼번에 출력한다.

### 알고리즘

- 알고리즘 수행중, ferry의 적재 용량에 주의!

1. ferry에 타고있는 차가 있으면 다 내린다. 결과값을 배열에 저장한다.
2. 통합차량큐에서 현재시간에 도착한 차량이 있다면 알맞은 bank 큐에 집어넣는다.
3. 현재 ferry가 있는 bank에 도착한 차량이 있다면 ferry에 태운다. ferry는 강을 건넌다. 1번으로 돌아간다.
4. 현재 ferry가 있는 bank에 도착한 차량이 없고 반대편 bank에도 도착한 차량이 없을때, 통합차량큐에 아직 차가 남아있다면 통합차량큐의 첫번째 차량의 도착시간까지 대기한다. 1번으로 돌아간다.
5. 현재 ferry가 있는 bank에 도착한 차량이 없고 반대편 bank에도 도착한 차량이 없을때, 통합 차량큐에도 차가 남아있지 않다면, 알고리즘을 종료한다.

### 만족스럽지 못함

- 왼족 bank에 있을때와 오른쪽 bank에있을때를 따로 처리해줘야하고, 여러 조건이 많아서 코드가 복잡해졌다.
- 좀더 간략하게 짤 수 있는 방법이 없을지 알아봐야할듯.