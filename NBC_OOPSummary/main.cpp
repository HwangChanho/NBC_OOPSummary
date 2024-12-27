#include <iostream>
#include <string>

using namespace std;

// ����
int getSum(int arr[], int size);
// ���
double getAvg(int arr[], int size);
// ����(1 = ��������, 0 = ��������)  
void sort(int arr[], int size, int type);
// ������ ���� �Լ�
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main() {
	const int MAX_SIZE = 5;
	int numArr[MAX_SIZE];

	cout << "���� 5���� �Է��ϼ���(������) : ";
	
	for (int i = 1; i <= 5; i++) {
		cin >> numArr[i - 1];

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');

			cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է��ϼ���." << endl;
			cout << "���� 5���� �Է��ϼ���: ";

			i--;
		} else {
			cout << "�Է��� ����: ";
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

	cout << "����: " << getSum(numArr, sizeof(numArr) / sizeof(int)) << endl;
	cout << "���: " << getAvg(numArr, sizeof(numArr) / sizeof(int)) << endl;

	return 0;
}

void sort(int arr[], int size, int type) {
	quickSort(arr, 0, size - 1);

	switch (type) {
	case 1:
		cout << "�������� ���� �� �迭: ";
		for (int j = 0; j < size; j++) {
			cout << arr[j] << " ";
		}
		cout << endl;

		break;
	case 0:
		cout << "�������� ���� �� �迭: ";
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