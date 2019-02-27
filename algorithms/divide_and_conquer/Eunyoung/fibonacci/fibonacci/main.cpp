#include <iostream>
using namespace std;
int fibo_recur(int n);

int main(void) {
	int n = 0;
	while (1) {
		cout << "Which fibonacci number do you want to know? ";
		cin >> n;

		int result = fibo_recur(n);
		cout << "The result is " << result << endl;
	}

	return 0;
}

int fibo_recur(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return fibo_recur(n - 1) + fibo_recur(n - 2);
}