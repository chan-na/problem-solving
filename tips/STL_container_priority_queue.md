# priority_queue

## 생성자

#### 기본 자료형

```C++
#include <queue>

std::priority_queue<int> pQ;    // max-heap
std::priority_queue<int, std::vector<int>, std::less<int>> pQ;      // max-heap
std::priority_queue<int, std::vector<int>, std::greater<int>> pQ;   // min-heap

std::priority_queue<pair<int, int>> pQ;  // max-heap
std::priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pQ;    // max-heap
std::priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQ; // min-heap
```

- priority queue를 기본으로 생성하면, comparison으로 less를 사용한다. **less이면 선형 자료구조에서는 오름차순으로 정렬되는 것인데, priority queue입장에서는 가장 큰값이 top에 있는 형태**이다. less인데 max heap으로 구현이되어서 헷갈린다.
- 기본자료형이나 pari<>형 같은 경우는 비교연산자를 기본으로 가지고있기 때문에 바로 priority_queue에 넣어주면 되지만, 사용자 정의 자료형의 경우 따로 comparison 함수를 넣어줘야한다.
- comparison함수를 넣어주기 위해서는 템플릿에 구현체 컨테이너도 명시해주어야 한다. priority_queue는 인터페이스일 뿐이기 때문에 empty(), size(), front(), push_back(), pop_back()을 가지고있는 컨테이너이기만 하면 구현체로 사용가능하다.

#### 사용자 정의 자료형

```C++
#include <queue>
#include <string>

struct MyDataType
{
    std::string name;
    int studentID;
};

class MyComparison
{
  public:
    bool operator()(const MyDataType &lhs, const MyDataType &rhs)
    {
        if (lhs.name == rhs.name)
        {
            return lhs.studentID > rhs.studentID;
        }
        return lhs.name > rhs.name;
    }
};

std::priority_queue<MyDataType, std::vector<MyDataType>, MyComparison> pQueue;
```

- [전체 예제 코드 링크](priority_queue.cpp)
- string과 int형 데이터를 가지고있는 자료형을, priority_queue에 넣어서 첫째로 string을 사전순으로 먼저나오는것을 top으로하고, string이 같으면 int값이 작은것을 top으로 하도록 구현한 예제이다.
- 여기서 MyComparison 클래스에 내가 priority_queue에 넣고싶은 자료형을 비교하는 operator()함수를 만들어 준다.
  - lhs > rhs으로 해야지만 min-heap으로 되니까 주의하자. 직관적이지가 않다.

## 사용하는 멤버 함수

#### empty()

- 컨테이너가 비어있는지 확인한다.
- 비어있으면 true, 비어있지않으면 false를 반환한다.

#### size()

- 컨테이너의 사이즈(들어있는 요소의 개수)를 반환한다.

#### top()

- top element에 접근한다. 접근만 할 뿐 pop()은 따로 해줘야하는것에 주의하자.

#### push()

- element를 추가한다.

#### pop()

- top에있는 element를 지운다.

## priority_queue clear 하기

- priority_queue를 vector를 통해 구현했다고 하더라도, priority_queue 인터페이스에서는 clear()를 지원하지않는다. vector에는 clear()가 있는데도 말이다. 그래서 다른 방법을 통해서 clear 해주어야 한다.

#### 컨테이너가 빌때까지 pop() 하기 - 느리다

```C++
while(!pQueue.empty())
{
    pQueue.pop();
}
```

- priority_queue에서 pop()을 하면 다시 heap을 재구성하는데 O(log(n))이 걸린다.
- 그렇다면 한개씩 pop()을 해서 컨테이너를 비운다면, O(log(n-1)) + O(log(n-2)) + ... + O(log(1)) 이 걸릴것이다.

#### swap() 을 사용한 방법 - 빠르다. 이것을 사용한다

```C++
priority_queue<int> pQueue;

// priority_queue를 사용하는 코드...

priority_queue<int>().swap(pQueue);
```

- 빈 priority_queue를 임시로 만들고, 그것과 swap해줌으로써 원래 사용하던 컨테이너를 clear 하는 방법이다.
- 임시로 만들어진 priority_queue가 삭제되면서 원래 가지고있던 데이터(swap을 통해 전달된 데이터)는 알아서 같이 제거된다.
- 확인해 본것은 아니지만, swap함수가 내부적으로 모든 element를 swap하지는 않을것이다. 단순히 heap의 root를 가리키는 포인터를 교환하고 size를 교환하는 정도일것이기 때문에 이 방식을 사용하면 O(1)에 clear가 가능하다고 볼 수 있다.
- swap을 하면 comparison function도 같이 교환되므로, 직접 구현한 comparison function을 사용했을때는 임시 priority_queue를 만들때도 같은 comparition function을 넣어줘야한다.
