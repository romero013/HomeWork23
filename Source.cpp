#include <iostream>
using namespace std;

template <typename T> void showArray(T arr[], int length);
template <typename T> void threeMax(T& a, T& b, T& c);
template <typename T> T& showRef(T arr[], int length);
template <typename T> void zero(T arr1[], int length1, T arr2[], int length2);

int main() {
	setlocale(LC_ALL, "Russian");

	// ������ 1
	int n, m, a;
	cout << "������ 1.\n������� ��� �����: ";
	cin >> n >> m >> a;
	threeMax(n, m, a);
	cout << n << " " << m << " " << a << "\n\n";

	// ������ 2
	cout << "������ 2.\n����������� ������:\n";
	const int L = 5;
	int z2[L] = { 2, 4, 8, -5, 9 };
	showArray(z2, L);
	cout << "������ ������������� ������� ������� = " << showRef(z2, L) << ".\n\n";

	// ������ 3
	cout << "������ 3.\n������ 1:\n";
	const int b = 5;
	const int c = 5;
	int z31[b] = { 2, 3, 6, 1, 7 };
	int z32[c] = { 3, 7, 9, 4, 3 };
	showArray(z31, b);
	cout << "������ 2:\n";
	showArray(z32, c);
	zero(z31, b, z32, c);
	cout << "������ 2 ����� ������ �������:\n";
	showArray(z32, c);
	cout << endl;

	return 0;
}
// ������ 1
template <typename T> void threeMax(T& a, T& b, T& c) {
	if (a > b && a > c) {
		b = a;
		c = a;
	}
	else if (b > a && b > c) {
		a = b;
		c = b;
	}
	else {
		a = c;
		b = c;
	}
}
// ������ 2
template <typename T> T& showRef(T arr[], int length) {
	for (int i = 0; i < length; i++)
		if (arr[i] < 0)
			return arr[i];
	return arr[0];
}
// ������ 3
template <typename T> void zero(T arr1[], int length1, T arr2[], int length2) {
	for (int i = 0; i < length1; i++)
		for (int j = 0; j < length2; j++)
			if (*(arr2 + j) == *(arr1 + i))
				*(arr2 + j) = 0;
}
// ����� �������
template <typename T> void showArray(T arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}