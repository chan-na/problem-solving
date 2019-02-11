# 978 Lemmings Battle!

## 문제 풀이

- 간단한 시뮬레이션 문제
- 가장 강한 lemming을 순서대로 뽑아야함
  - 1. lemming들을 배열에 넣어놓고 정렬한후 뽑아간다.
  - 2. priority queue를 사용한다.
- 전투를 마친 후 살아남을 lemming은 다시 army로 돌아가고 그다음 배틀에서 가장 강한 lemming을 순서대로 또 뽑아야 한다.
  - 배틀 한번 할때마다 정렬을 하는것 보다는 priority queue를 쓰는게 낫다. 전투에 참여하지 않은 lemming들이 priority queue에 들어가있는 상태에서 살아남은 lemming을 넣으면서 insertion sort를 하게 되는데, 이것은 배열에서 다시 정렬하는것보다는 빠를것이다.
  - 배열에 넣어서 정렬하나, priority queue에 하나씩 집어넣어서 정렬하나 둘 다 시간복잡도는 O(n\*log(n))이겠지만, 배열에 넣어서 다시 정렬을 하면 전체에 대해서 정렬을 하는것이라서 실제 연산 횟수가 더 많아진다. 반면에 priority queue를 사용한 삽입 정렬은 이미 정렬된 부분들을 활용하게 되므로 실제 연산횟수는 줄어들게 된다.
