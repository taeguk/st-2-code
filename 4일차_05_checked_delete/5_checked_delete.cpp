#include <iostream>
using namespace std;

class Test; // 클래스 전방선언 - 완전한 선언이 없이도 포인터 변수를 사용할 수 있다.

Test* p; // incomplete objecct(불완전한 객체)
		// 전방선언만 있는 타입의 포인터 delete 하면 소멸자를 호출하지 못한다.

// ~ 죽음
// checked delete - boost 팀이 최초로 만든 개념.
void foo(Test* pt) {
	enum { type_must_be_complete = sizeof(Test) }; // 불완전 객체의 크기를 구할 수 없다.
	delete pt;
}

class Test {
public:
	Test() {
		cout << "생성자" << endl;
	}
	~Test() {
		cout << "소멸자" << endl;
	}
};

// ~ 컴파일되고 실행됨
//void foo(Test* pt) {
//	sizeof(Test); // 불완전 객체의 크기를 구할 수 없다.
//	delete pt;
//}

int main() {
	Test* p = new Test;
	foo(p);
}