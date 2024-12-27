#include <iostream>
#include <string>

using namespace std;

// 총합
int getSum(int arr[], int size);
// 평균
double getAvg(int arr[], int size);
// 정렬(1 = 오름차순, 0 = 내림차순)  
void sort(int arr[], int size, int type);
// 퀵정렬 로직 함수
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main() {
	const int MAX_SIZE = 5;
	int numArr[MAX_SIZE];

	cout << "숫자 5개를 입력하세요(정수형) : ";
	
	for (int i = 1; i <= 5; i++) {
		cin >> numArr[i - 1];

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');

			cout << "잘못된 입력입니다. 숫자만 입력하세요." << endl;
			cout << "숫자 5개를 입력하세요: ";

			i--;
		} else {
			cout << "입력한 숫자: ";
			for (int j = 0; j <= sizeof(numArr) / sizeof(int); j++) {
				if (j >= i)
					continue;
				cout << numArr[j] << " ";
			}
			cout << endl;
		}
	}

	sort(numArr, MAX_SIZE, 1);
	sort(numArr, MAX_SIZE, 0);

	cout << "총합: " << getSum(numArr, sizeof(numArr) / sizeof(int)) << endl;
	cout << "평균: " << getAvg(numArr, sizeof(numArr) / sizeof(int)) << endl;

	return 0;
}

void sort(int arr[], int size, int type) {
	quickSort(arr, 0, size - 1);

	switch (type) {
	case 1:
		cout << "오름차순 정렬 후 배열: ";
		for (int j = 0; j < size; j++) {
			cout << arr[j] << " ";
		}
		cout << endl;

		break;
	case 0:
		cout << "내림차순 정렬 후 배열: ";
		for (int j = 0; j < size; j++) {
			cout << arr[size - 1 - j] << " ";
		}
		cout << endl;

		break;
	}
}

int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++; 
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[high]);
	return i + 1;
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int getSum(int arr[], int size) {
	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}

	return sum;
}

double getAvg(int arr[], int size) {
	return getSum(arr, size) / size;
}