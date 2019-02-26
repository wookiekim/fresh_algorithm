#include <iostream>

using namespace std;


void print_arr(int a[], int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}
void conquer(int a[], int left, int mid, int right, int size) {
	int i = left, j = mid + 1, k = left;
	int *temp = new int[size];
	while (i <= mid & j <= right) {
		if (a[i] <= a[j]) {
			temp[k] = a[i];
			i++;
		}
		else {
			temp[k] = a[j];
			j++;
		}
		k++;
	}

	if (i > mid) {
		for (int p = j; p <= right; p++) {
			temp[k] = a[p];
			k++;
		}
	}
	else {
		for (int p = i; p <= mid; p++) {
			temp[k] = a[p];
			k++;
		}
	}

	for (int q = left; q <= right; q++) {
		a[q] = temp[q];
	}


}
void divide(int a[], int leftmost, int rightmost, int size) {
	if (leftmost < rightmost) { // at least two elements are in the array so that it needs to be splited.
		int mid = (leftmost + rightmost) / 2; 

		divide(a, leftmost, mid, size);//if leftmost == mid, then it returns right away while doing nothing.
		divide(a, mid + 1, rightmost, size);//same here

		conquer(a, leftmost, mid, rightmost, size);	//So the array that has only one element "starts" to call this function.
	}
}

int main(void) {
	int size = 0;
	cout << "How many numbers do you want to sort? ";
	cin >> size;

	int *a = new int[size];

	cout << "Put the numbers: ";
	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}
	print_arr(a, size);
	divide(a, 0, size - 1, size);
	print_arr(a, size);

	system("PAUSE");
	return 0;
}

