#include <iostream>
using namespace std;


void swap(int** x, int** y)
{
	int temp;

	temp = **x;
	**x = **y;
	**y = temp;
}


int main() {
	int a = 5, b = 10;
	int* pa = &a;
	int* pb = &b;

	int** ppa = &pa;
	int** ppb = &pb;

	swap(&pa, &pb);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	return 0;
}
