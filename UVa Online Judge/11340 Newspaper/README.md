# UVa 11340 Newspaper

- 문자를 입력받을때 공백문자와 \n에 신경을 써야한다.
- 문자가 ASCII 코드라고 생각해서 0 ~ 127범위로 가정하고 문제를 풀었으나 WA가 나왔다. 왜인지는 모르겠지만 음수값 캐릭터가 들어있다는듯.
- 각 캐릭터에 +128을 해주면서 음수값들까지 포함하여 -128 ~ 127 범위로 문제를 풀었더니 AC받음.
