# 11849 CD

- 중복되는 숫자가 있는지만 알면되는 엄청 간단한 문제이다. 그래서 알고리즘 수행 시간이 구현에 따라 어떻게 바뀌는지 실험해 보았다.

## version 1 : set, iostream 사용

- 1.030s
- iostream을 썼지만 ios::sync_with_stdio(false); cin.tie(NULL); 이 두 옵션을 주고, endl대신 '\n'을 사용했는데도 시간이 많이 걸렸다.

## version 2 : set, stdio 사용

- 1.000s
- 입출력은 병목이 아니었는듯 하다.
- 단순히 해당 숫자가 나왔는지 안나왔는지만 알면 되기 때문에, binary search tree로 구현된 set은 오버헤드가 있다. 키를 넣으면서 계속 정렬을 하기 때문이다. hash로 구현된 unordered_set으로 바꿔본다.

## version 3 : unordered_set, stdio 사용

- 0.350s
- 역시 정렬하는 부분이 병목이었다. 속도가 많이 빨라졌다.
- 인풋의 최대 개수가 10^6이기 때문에, 기본으로 unordered_set을 생성해서 알고리즘을 돌리다 보면 중간에 크기를 증가시키느라 메모리 재할당과 해제 때문에 시간이 걸릴것이라고 생각했다. 그래서 처음 시작할때 최대 개수만큼의 크기를 잡는것으로 바꿔본다.

## version 4 : unordered_set, reserve(10^6), stdio 사용

- 0.320s
- 약간의 속도 상승이 있었다.
