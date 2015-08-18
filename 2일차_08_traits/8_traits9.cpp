#include <iostream>
#include <type_traits>
using namespace std;


// traits 종류
// 1. T의 속성 질의

template<typename T> void foo(const T& a) {
	if (is_array<T>::value)
		cout << "배열. 크기는" << extent<T, 1>::value << endl;
}

// 2. T타입의 변형
template<typename T> void goo(const T& a) {
	typename remove_pointer<T>::type n;
	cout << typeid(n).name() << endl;
}

int main() {
	int x[10][20];
	foo(x);
	
	int n; 
	goo(&n);
}