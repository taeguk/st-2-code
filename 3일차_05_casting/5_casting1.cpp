#include <iostream>
using namespace std;

// C casting의 문제점
// 대부분 성공한다 .. 그런데 .. 너무 위험하고 버그가 많아 진다.
// 

int main() {
//	int n = 01;
// 	double* p = &n; //? error. 서로 다른 타입의 주소는 암시적 변환이 안됨.
					// 단, C에서는 가능 ( 확장자 C일경우)

//	int n = 01;
//	double* p = (double*) &n; // 명시적 변환 - ok

//	*p = 3.4;

	const int c = 10;
	//int* p2 = &c; // error. 상수 주소는 비 상수 포인터에 담을 수 없다.
	int* p2 = (int*)&c;// 명시적 변환 - ok
	*p2 = 20;

	cout << c << endl;
}