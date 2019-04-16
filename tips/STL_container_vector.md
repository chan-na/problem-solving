# vector

## 생성자

### 기본 생성자

```C++
std::vector<int> scores;    // 기본 자료형
std::vector<Cat> myCats;    // 개체
std::vector<Cat*> myCats;   // 개체에 대한 포인터
```

- 벡터는 비어있는 상태이다. 즉 capacity는 기본값, size는 0인 상태.
  - 여기서 capacity는 현재 벡터를 구성하고있는 배열의 크기(잡아놓은 메모리의 크기를 저장할 요소의 크기로 나눈값)
  - size는 현재 벡터에 들어있는 요소의 개수.

### 크기(size)를 지정하여 생성

```C++
std::vector<int> scores(10);
std::vector<Cat> myCats(4);
```

- size를 지정하는것이므로, 지정한 개수만큼 요소가 자동으로 생성된다.
- socres같은 경우는 기본 자료형인 int형이므로 모든 요소의 값이 0(모든 비트가 0)으로 초기화된다.
- MyCats의 경우 Cat클래스의 기본생성자를 자동으로 호출하여 요소들을 초기화한다. 해당 클래스가 기본생성자를 가지고 있지않으면 컴파일 에러가 난다.

### 크기와 초기값을 지정하여 생성

```C++
class Cat
{
public:
	Cat(int age)
		: mAge(age)
	{
	}
private:
	int mAge;
};

std::vector<int> scores(5, 100);    // 100 100 100 100 100
std::vector<Cat> myCats(5, Cat(3)); // age가 3인 Cat개체 5개를 저장
```

- 특정 크가와 초기값을 가지는 벡터를 생성할 수 있다.

## 사용하는 멤버 함수

### push_back() - 맨 뒤에 요소 추가

```C++
scores.push_back(30);
```

- 빈 공간이 있으면(size < capacity 이면) O(1)의 시간복잡도를 가진다.
- 빈 공간이 없다면(size == capacity 이면) 메모리 재할당 및 복사에 의한 오버헤드가 있다.

### pop_back() - 맨 뒤의 요소 제거

```C++
scores.pop_back();
```

- O(1)의 시간복잡도를 가진다.

### capcity() - 용량 확인하기

```C++
scores.capacity();
```

- 현재 벡터에 할당된 요소 공간 수. 즉 현재 잡혀있는 메모리를 반환한다.

### size() - 크기 확인하기

```C++
scores.size();
```

- 현재 벡터에 실제 들어있는 요소 수를 반환한다.

### reserve() - 용량 늘리기

```C++
scores.reserve(10);
```

- 용량이 증가해야하면, 새로운 메모리를 재할당후 기존 요소들을 복사한다.
- 현재 용량이 reserve()의 매개변수로 전달된 용량보다 크면 아무일도 일어나지 않는다. 즉 용량을 줄이지는 않는다.

### operator[]

```C++
scores[2] = 3;
std::cout << names[1] << std::endl;
```

- 지정된 위치의 요소를 참조로 반환한다.
- 참조로 반환하기 때문에 숫자 대입도 가능하다.

### insert() - 특정 위치에 요소 삽입

```C++
std::vector<int> scores;
scores.reserve(2);

scores.push_back(10);   // 10
scores.push_back(30);   // 10 30

std::vector<int>::iterator it = scores.begin();
++it;

it = scores.insert(it, 80);     // 10 80 30

std::cout << *it << std::endl;  // 80
```

- 특정 위치에 새로운 요소를 삽입하면 그 뒤의 모든 요소를 한칸씩 뒤로 밀어야한다. O(n)
- 위의 예제처럼 벡터가 꽉 찬 상태이면 재할당도 필요하다.
- 추가된 요소를 가리키는 iterator를 반환한다.

### erase() - 특정 위치에 있는 요소 삭제

```C++
std::vector<int> scores;
scores.reserve(3);

scores.push_back(10);   // 10
scores.push_back(30);   // 10 30
scores.push_back(17);   // 10 30 17

std::vector<int>::iterator it = scores.begin();
++it;

it = scores.erase(it);	// 10 17

std::cout << *it << std::endl;  // 17
```

- 삭제를 한 뒤, 배열의 빈구멍을 메우기 위해 복사가 일어난다. O(n)
- 만약 벡터에 저장된 요소들의 순서를 유지할 필요가 없다면, 가장 뒤의 요소를 빈구멍에 채우는 식으로 O(1)에 특정 위치에 있는 요소를 삭제하는 함수를 따로 만들어서 사용할 수도 있다.

### swap() - 두 벡터 교환하기

```C++
std::vector<int> scores;
scores.reserve(2);

scores.push_back(10);   // 10
scores.push_back(30);   // 10 30

std::vector<int> anotherScores(4, 100); // 100 100 100 100

scores.swap(anotherScores); // scores : 100 100 100 100
                            // anotherScores : 10 30
```

- 같은 자료형을 저장하는 두 벡터를 맞바꾼다.
- 벡터를 swap할때 모든 요소를 복사할 필요는 없다. 단순히 힙에 할당되어있는 배열의 메모리 주소를 교환하고 capacity와 size만 교환하면 된다.

### assign() - 요소 대입하기

```C++
std::vector<char> characters(3, 'b');   // b b b
characters.assign(5, 'a');              // a a a a a
```

- 원래 저장되어 있던 값은 없어지고, 지정된 개수로 지정된 값이 들어있는 벡터로 만들어준다.

### resize() - 벡터의 크기(size) 변경하기

- 새로 지정된 크기가 기존의 크기보다 작으면 초과분이 제거된다.
  - reserve()와는 다른부분.
- 새로 지정된 크기가 기존의 크기보다 크면, 초과분에 대해서는 기본값으로 초기화된다.
- 새로 지정된 크기가 기존의 용량(capacity)보다 크면, 물론 재할당이 일어난다.

### clear() - 벡터에서 모든 요소 제거하기

```C++
scores.clear();
```

- vector의 요소를 비운다.
- 크기(size)는 0이 되고 용량(capacity)는 변하지 않는다.

## vector 순회하기

### operator[] 사용

```C++
for(size_t i = 0; i < scores.size(); ++i)
{
    std::cout << scores[i] << " ";
}
```

- 배열처럼 인덱스를 통해 순회할수 있다.
- STL 컨테이너중 벡터에서만 가능한 방법이다.

### iterator 사용

```C++
for(std::vector<int>::iterator iter = scores.begin(); iter != scores.end(); ++iter)
{
    std::cout << *iter << " ";
}
```

- 모든 STL 컨테이너에서 동일하게 사용할 수 있는 방법이다.
- 이터레이터는 개념적으로 포인터와 같기 때문에 \*를 통해 역참조를 해서 요소에 접근할 수 있다.
