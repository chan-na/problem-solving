# map

## 생성자

### 기본 생성자

```C++
std::map<std::string, int> simpleScoreMap;

std::pair<std::string, int> student1("Coco", 10);

std::cout << student1.first << std::endl;   // Coco
std::cout << student1.second << std::endl;  // 10

simpleScoreMap.insert(student1);
simpleScoreMap.insert(std::pair<std::string, int>("Mocha", 100));
```

- std::map은 키, 밸류 페어를 std::pair형태로 저장하도록 구현되어있다.
- 키에 접근하려면 first, 밸류에 접근하려면 second 멤버변수를 사용한다.

## 사용하는 멤버 함수

### insert() - 새 요소 삽입하기

> std::pair<iterator, bool> insert(const value_type& value)

```C++
// <itertator, true>를 반환
simpleScoreMap.insert(std::pair<std::string, int>("Mocha", 100));

// <iterator, false>를 반환
simpleScoreMap.insert(std::pair<std::string, int>("Mocha", 0));
```

- **새로운 요소**를 std::map에 삽입한다.
- iterator와 bool값을 페어로 반환한다.
  - iterator는 새로 추가된 요소를 가리킨다.
  - bool값은 삽입 결과를 알려준다. 삽입이 실패(이미 같은 키를 가지는 요소가 존재)하면 false를 반환한다.
- **키를 중복으로 삽입할 수 없다.**

### operator[] - 요소에 접근하기

> mapped_type& operator[](const Key& key)

```C++
simpleScoreMap["Nana"];         // 새 요소 삽입. 대응하는 value는 0으로.
simpleScoreMap["Coco"] = 10;    // 새 요소를 삽입한다.
simpleScoreMap["Coco"] = 50;    // "Coco" 키를 가지는 요소의 value를 덮어쓴다.
```

- 인덱스로 입력한 key에 대응하는 value를 참조로 반환한다.
- 해당 key값을 가지는 요소가 존재하지 않으면 자동으로 새요소를 삽입한다.
  - 삽입시에 value는 기본값으로 초기화해준다.
- 존재하지 않을 경우 자동으로 요소를 생성하기 때문에 이 방법을 검색을 위해서 사용하면 안된다.
  - 검색을 하려면 find()를 사용한다.

### fine() - 요소 찾기

```C++
std::map<std::string, int> simpleScoreMap;
simpleScoreMap.insert(std::pair<std::string, int>("Mocha", 100));

std::map<std::string, int>::iterator it = simpleScoreMap.find("Mocha");
if(it != simpleScoreMap.end())  // 존재하면(검색에 성공하면)
{
    it->second = 80;
}
```

- 맵안에서 해당 key를 가지는 요소를 찾으면, 해당 요소를 가리키는 이터레이터를 반환한다.
- 찾지 몬한다면 맵의 끝을 가리키는 iterator를 반환한다.

### swap() - 두 맵 교환하기

```C++
std::map<std::string, int> map1;
map1["aaa"] = 10;
map1["bbb"] = 20;
// map 1: (aaa, 10) (bbb, 20)

std::map<std::string, int> map2;
map2["bbb"] = 30;
map2["ccc"] = 40;
// map 2: (bbb, 30) (ccc, 40)

map1.swap(map2);
// map 1: (bbb, 30) (ccc, 40)
// map 2: (aaa, 10) (bbb, 20)
```

### clear() - 맵에서 모든 요소 제거하기

```C++
ma1.clear();
```

### erase() - 요소 제거하기

##### 특정 위치의 요소 제거하기

> void erase(iterator position)

- find()를 시용해서 요소의 위치를 찾고, erase를 통해서 제거한다.

##### 특정 키를 가지는 요소 제거하기

> size_type erase(const key_type& key)

- 자동으로 해당 키를 가지는 요소를 찾아서 제거해준다.
  - 존재할경우 제거, 존재하지 않으면 아무일도 하지 않음.
- 좀더 보편적인 방식일듯

##### 특정 범위의 요소 제거하기

> void erase(iterator first, iterator last)

## map 순회하기

### iterator 사용하기

```C++
	std::map<std::string, int> map1;
	map1["ccc"] = 30;
	map1["aaa"] = 10;
	map1["bbb"] = 20;

	for (std::map<std::string, int>::iterator it = map1.begin(); it != map1.end(); ++it)
	{
		std::cout << "Key : " << it->first << "  Value : " << it->second << std::endl;
	}
```

- key를 기준으로 자동으로 정렬되기 때문에, aaa -> bbb -> ccc 순으로 순회한다.
