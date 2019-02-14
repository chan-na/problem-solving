# 10954 Add All

## WA 이유

- 문제를 잘못 이해 했다.
- 숫자 n개의 sum을 구하는데, 그 중간 계산에서 만들어지는 임시결과들(두 숫자를 더한 값)의 합이 최소가 되도록 하는 문제이다.
- 예를들어 1, 2, 3, 4, 5의 합을 구한다고 하자. 일단 2개씩 더하는것이 규칙이므로 2개씩 더해야한다.
  - 1 + 2 = 3 이나오면 여기서 임시 결과인 3이 비용이 된다. 이 비용이 최소가 되야한다.
  - 그다음은 3(1 + 2), 3, 4, 5 이다. 여기서 다시 최소값인 3, 3 을뽑아서 3 + 3 = 6이므로 지금까지 총비용은 3 + 6 = 9;
  - 4, 5, 6 에서 4 + 5 = 9 이므로 지금까지 총비용은 18
  - 6, 9 에서 6 + 9 = 15 이므로 지금까지 총비용은 33이다.
- 이런식으로 숫자들의 집합에서 가장 작은 수 두개를 꺼내와서 더하고 다시 수집합에 집어넣는 형식이므로 priority queue가 자료구조로 알맞다.