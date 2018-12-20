# UVa 12356 Army buddies

- 가장 먼저 brute force로 풀었으나 시간초과.
- 각 군인들이 옆에 살아있는 군인을 buddy로 가지고 있는것이 linked-list형태이기 때문에 linked-list를 시도해 보려고 했으나, 군인 L부터 군인 R까지 사망하였다는 리포트가 왔을때, 군인 L의 왼쪽 buddy와 군인 R의 오른쪽 buddy를 알기 위해서는 군인L과 군인R에 접근하여야하고, linked-list에서는 O(n)에 접근을 하기 때문에 기존의 풀이와 속도가 다르지 않을것이라고 예상했다.
- linked-list형태로 구성하되, 배열을 사용하여 접근도 O(1)에 할 수 있도록 만들었다. i번째 군인의 leftBuddy를 저장하는 leftBuddies배열과 rightBuddy를 저장하는 rightBuddies배열을 사용했다. leftBuddy가 존재하지 않을때 0을 기록, rightBuddy가 존재하지 않을때 - 군인이 1에서 S번까지 있으므로 - S + 1을 기록함으로써 경계값을 처리했다.
