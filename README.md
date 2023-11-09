🧐 CPP 문법 익히기 
======
<a href="https://accessible-capricorn-be7.notion.site/CPP-03d7c74bf1484b6aacc3fd2bfa329894?pvs=4" target="_blank"><img src="https://img.shields.io/badge/Notion-444444?style=for-the-badge&logo=notion&logoColor=FFFFFF"/></a>
---
목차
--


🎯 00
--
- cpp 의 기본적인 사용법을 익힌다.
- namespace, class, memeber fuction, stdio stream, initialization list, static, const 등에 대한 개념과 사용하는 법을 익힌다.

🎯 01
--
- 동적할당, 레퍼런스, 멤버함수포인터, 스위치에 대해 살펴본다.
- Memory allocation, pointers to members, references, switch statement
  
> 1. new 와 delete 를 사용한 동적할당을 접하고 정적할당과 정적할당의 소멸자가 불러오는 시점을 확인 할 수 있다.
> 2. new[] 와 delete[] 를 사용하여 배열 동적할당을 접한다.
> 3. pointer포인터와 reference참조자를 사용하고 차이를 알아본다.
> 4. reference 참조자의 쓰임을 확인하고 생성자에 초기화리스트를 사용해보자.
> 5. 파일을 읽고 문자열을 대치시키고 새로운 파일을 만들어 저장하는 것을 알아본다.
> 6. 멤버 함수 포인터를 알고 함수포인터 배열을 사용해보자.
> 7. 스위치문 사용과 break 가용 시점에 따른 실행도 확인해보자.


🎯 02
--
- 임시 다형성(함수 오버로딩), 연산자 오버로딩, 정식 클래스 형식을 공부하고 사용해본다.
- Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form

> 1. orthodox canonical form 에 맞추어 class를 만들어보자.
> 2. float 와 int 사이의 변환을 부동소수점 클래스를 만들어서 해결하자.
> 3. 멤버함수로 연산자 오버로딩 추가하기 + 정적맴버함수 min, max 작성해보자.
> 4. 다각형 외부, 내부 판별을 구현해본다. (bsp, stands for Binary space partitioning)

🎯 03
--
- 상속!에 대해 공부하고 상속관계의 클래스를 만들어본다.
- Inheritance

> 1. 기초(부모) 클래스를 작성한다.
> 2. 기초(부모) 클래스를 상속받는 파생(자식)클래스를 작성한다.
> 3. 기초(부모) 클래스를 상속받는 새로운(앞의 파생클래스와 다른 기능을 하는) 파생(자식)클래스를 작성한다. 
> 4. 다중상속을 받는 클래스를 만들어 본다.

🎯 04
--
- 서브타입 다형성(오버라이딩), 추상 클래스, 인터페이스
- Subtype polymorphism, abstract classes, interfaces

> 1. 다형성의 개념을 안다.
> 2. 포인터 멤버 변수와 얕은 복사, 깊은 복사에 대해 공부한다.
> 3. 추상클래스, 순수 가상 함수를 공부하고 사용한다.

🎯 05
--
- 반복 및 예외처리
- Repetition and Exceptions

> 1. try-catch 문을 사용한 예외처리 방법에 대해 공부한다.
> 2. 클래스 멤버 함수 내에서 try-catch 문을 사용해 본다.
> 3. 추상클래스의 가상 소멸자에 대해 공부한다.


🎯 06
-- 
- 캐스트, 형변환 연산자
- C++ casts

> 1. const_cast
> 2. static_cast
> 3. interpret_cast
> 4. dynamic_cast
> 5. 직렬화란 ?
>   >   구조가 있는 객체의 내용물을 바이트 배열로 저장하는 것
>   >   직렬화는 객체를 파일의 형태 등으로 저장하거나, 통신하기 쉬운 포맷으로 변환하는 과정

🎯 07
--
- 템플릿 !
- templates

> 1. 함수 템플릿 이해하기
> 2. 함수 템프릿 Iter 만들기
> 3. 클래스 템플릿 Array 만들기

🎯 08
--
- STL 사용하기
- #include <algorithm>, templated container, iter .. extra..

> 1. STL과 컨테이너에 대해 이해한다.
> 2. 컨테이너를 사용한 클래스를 만들어 본다.
> 3. 컨테이너를 사용해서, not iterable 한 std::stack을 iterable 하도록  MutantStack 클래스를 만들어 보자.

🎯 09
--
- STL 
- STL 활용과 Merge-insertion sort ([Ford-Jonson algorithm](https://en.wikipedia.org/wiki/Merge-insertion_sort))

> Merge sort와 Insertion sort 에 대해 이해하고
> Merge-insertion sort를 하는 클래스를 STL 을 활용하여 만든다.
