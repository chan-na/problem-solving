# 11581 Grid Successors

## 어려운 해석

- 셀에 0또는 1이 들어있는 3x3 그리드 g가 있다.
- 그리드를 변형시키는 함수 f가 있고, f(g)는 아래와 같이 정의된다
  - f(g)의 각 셀에는 인접한 셀의 값을 더한후 modulo 2 연산을 한 값이 들어간다.
  - 인접한 셀은 같은 면을 공유하는 셀이다.
  - 더할 때 자기 자신은 제외이다.
- 임의의 그리드 h에 대해서 함수 k.g(h)는 아래와 같이 정의된다.
  - h = f^i(h)를 만족시키는 i 중 가장큰 인덱스의 숫자.
  - i는 infinite일 수 있다.
- 최종적으로 우리가 구해야 하는것은, 주어진 그리드 g에 대해서 k.g(f^i(g))가 finite인 최대 i를 찾는것이다.

## 사실은 간단

- 주어진 그리드 g에 대해서 f^0(g), f^1(g), ... f^j(g), ... 을 구하다가 어떤 f^i(g)가 이전에 이미 구했던 f^j(g)와 같아질때 종료한다.
- 그렇다면 f^j(g)부터 f&i(g)까지는 k.g(h)함수의 h에 집어넣어서 돌렸을때, infinite가 나온다. loop가 있으므로 가장 큰 인덱스의 숫자를 구할수가 없는것이다.
- 그러므로 j - 1, 루프가 시작되는 인덱스의 바로 이전 인덱스가 finite인 것중 최대의 인덱스이다.