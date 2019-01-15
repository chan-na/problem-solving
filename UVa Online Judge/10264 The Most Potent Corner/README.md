# 10264 The Most Potent Corner

## N차원 unit cube

- 각 차원의 좌표를 0 또는 1로 표현한다.
  - 비트가 켜졌는지 안켜졌는지를 통해 각 corner를 표현할 수 있다.
- N차원 unit cube의
  - corner 수 : 2^N
  - 각 corner가 가지는 neighbour 수 : N
  - edge 수 : N \* 2^(N-1)
- 어떤 corner의 neighbour는?
  - 한 좌표값을 제외한 모든 좌표가 같은 corner이다.
  - 예를들어 (0, 1, 0)의 neighbour는 (0, 1, 1), (0, 0, 0), (1, 1, 0)이다.
  - 그러므로 bitwise XOR 연산을 통해 특정 corner의 neighbour를 쉽게 만들수 있다.
    - 0과 XOR하면 그대로 유지되고 1과 XOR하면 비트가 반전되는 특성을 이용

## 틀린 이유

```C++
#define CORNER_MAX (1 << 15)    // 14차원일 경우 14면 충분하지만 15로 해야 AC

int weights[CORNER_MAX];
int potencies[CORNER_MAX];
```

- 문제에서 N차원 unit cube(1 < N < 15)라고 나와있어서, 14차원이 최대라고 생각하고 범위를 잡았다.
- 그런데 문제가 틀렸다고 나와서 15차원이 최대라고 범위를 잡았더니 AC가 나온다. 왜이런지 모르겠음
