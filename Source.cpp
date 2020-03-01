#include <iostream>
#include <time.h>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T>
class Sort {
public:
	Sort() {}
	void swap(T* a, T* b);
	void BubbleSort(T A[], int n);
	void SelectionSort(T A[], int n);
	void InsertionSort(T A[], int n);
	int Partition(T A[], int l, int h) {
		T pivot = A[l];
		int i = l - 1, j = h + 1;
		do {
			do { j--; } while (A[j] > pivot);
			do { i++; } while (A[i] < pivot);
			if (i < j)
				swap(&A[i], &A[j]);
		} while (i < j);
		swap(&A[l], &A[j]);
		return j;
	}
	void QuickSort(T A[], int l, int h);
	void Merge(T A[], int l, int mid, int h);
	void MergeSort(T A[], int l, int h);
	T findMax(T A[], int n);
	void countSort(T arr[], int n, int exp);
	void radixsort(T arr[], int n);
	void Display(T A[], int n);
	void ReverseDisplay(T A[], int n);
};

template <class T>
void Sort<T>::swap(T* a, T* b) {
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <class T>
void Sort<T>::BubbleSort(T A[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (A[j] > A[j + 1])
				swap(&A[j], &A[j + 1]);
		}
	}
}

template <class T>
void Sort<T>::SelectionSort(T A[], int n) {
	int MAX = NULL;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++) {
			if (A[j] < A[MAX]) {
				MAX = j;
			}
		}
		swap(&A[i], &A[MAX]);
	}
}

template <class T>
void Sort<T>::InsertionSort(T A[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		T x = A[i];
		while (j > -1 && A[j] > x) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
	}
}

//quicksort
/*template <class T>
T Sort<T>:: Partition(T A[], int l, int h) {
	T pivot = A[l];
	int i = l, j=h;
	do {
		do { i++; } while (A[i] <= pivot);
		do { j--; } while (A[j] > pivot);
		if (i < j)
			swap(&A[i], &A[j]);
	} while (i < j);
	swap(&A[l], &A[j]);
	return j;
}*/

template <class T>
void Sort<T>::QuickSort(T A[], int l, int h) {
	int j;
	if (l < h) {
		j = Partition(A, l, h);
		QuickSort(A, l, j);
		QuickSort(A, j + 1, h);
	}
}

template <class T>
void Sort<T>::Merge(T A[], int l, int mid, int h)
{
	int i = l, j = mid + 1, k = l;
	T B[100];
	while (i <= mid && j <= h)
	{
		if (A[i] < A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}
	for (; i <= mid; i++)
		B[k++] = A[i];
	for (; j <= h; j++)
		B[k++] = A[j];
	for (i = l; i <= h; i++)
		A[i] = B[i];
}

template <class T>
void Sort<T>::MergeSort(T A[], int l, int h)
{
	int mid;
	if (l < h)
	{
		mid = (l + h) / 2;
		MergeSort(A, l, mid);
		MergeSort(A, mid + 1, h);
		Merge(A, l, mid, h);
	}
}

template <class T>
T Sort<T>::findMax(T A[], int n) {
	T max = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] > max) {
			max = A[i];
		}
	}
	return max;
}

template <class T>
void Sort<T>::countSort(T arr[], int n, int exp)
{
	T output[n];
	int i;
	T count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

template <class T>
void Sort<T>::radixsort(T arr[], int n)
{
	T m = findMax(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

template <class T>
void Sort<T>::Display(T A[], int n) {
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}

template <class T>
void Sort<T>::ReverseDisplay(T A[], int n) {
	for (int i = n - 1; i >= 0; i--) {
		cout << A[i] << " ";
	}
	cout << endl;
}
template <class T>
void ALL(Sort<T>* a, T B[], int choice2) {
	T* A = new T[choice2];
	for (int i = 0; i < choice2; i++)
		A[i] = B[i];
	clock_t startTime = clock(); //starts clock
	a->BubbleSort(A, choice2);
	cout << "Total Time taken by Bubble sort is: " << double(clock() - startTime) / CLOCKS_PER_SEC << endl;
	cout << "Sorted array:" << endl;
	a->Display(A, choice2);
	cout << "===============================================" << endl;
	for (int i = 0; i < choice2; i++)
		A[i] = B[i];
	startTime = clock(); //starts clock
	a->InsertionSort(A, choice2);
	cout << "Total Time taken by Insertion sort is: " << double(clock() - startTime) / CLOCKS_PER_SEC << endl;
	cout << "Sorted array:" << endl;
	a->Display(A, choice2);
	cout << "===============================================" << endl;
	for (int i = 0; i < choice2; i++)
		A[i] = B[i];
	startTime = clock(); //starts clock
	a->SelectionSort(A, choice2);
	cout << "Total Time taken by Selection sort is: " << double(clock() - startTime) / CLOCKS_PER_SEC << endl;
	cout << "Sorted array:" << endl;
	a->Display(A, choice2);
	cout << "===============================================" << endl;
	for (int i = 0; i < choice2; i++)
		A[i] = B[i];
	startTime = clock(); //starts clock
	a->MergeSort(A, 0, choice2 - 1);
	cout << "Total Time taken by Merge sort is: " << double(clock() - startTime) / CLOCKS_PER_SEC << endl;
	cout << "Sorted array:" << endl;
	a->Display(A, choice2);
	cout << "===============================================" << endl;
	for (int i = 0; i < choice2; i++)
		A[i] = B[i];
	startTime = clock(); //starts clock
	a->QuickSort(A, 0, choice2 - 1);
	cout << "Total Time taken by Quick sort is: " << double(clock() - startTime) / CLOCKS_PER_SEC << endl;
	cout << "Sorted array:" << endl;
	a->Display(A, choice2);
	cout << "===============================================" << endl;
}
template <class T>
void prompting2(Sort<T>* a, int choice1) {
	int choice2, choice3;
	T* B;
	cout << "How many elements you want to sort?" << endl;
	cin >> choice2;
	cout << "Enter the elements you want to sort" << endl;
	B = new T[choice2];
	for (int i = 0; i < choice2; i++)
		cin >> B[i];
	printf("Which type of sorting you want to perform?\n(1.bubble sort 2.Insertion sort 3.selection sort, 4.merge sort, 5.Quick sort, 6.Radix sort 7.All of them)\n");
	cin >> choice3;
	switch (choice3) {
	case 1:
		a->BubbleSort(B, choice2);
		break;
	case 2:
		a->InsertionSort(B, choice2);
		break;
	case 3:
		a->SelectionSort(B, choice2);
		break;
	case 4:
		a->MergeSort(B, 0, choice2 - 1);
		break;
	case 5:
		a->QuickSort(B, 0, choice2 - 1);
	case 7:
		ALL(a, B, choice2);
		break;
	}
	//if (choice3 == 6)
		//a->RadixSort(B, choice2);

	cout << "Do you want to sort in Ascending or Descending(1.Ascending 2.Descending)" << endl;
	cin >> choice3;
	if (choice3 == 1)
		a->Display(B, choice2); //display the sorted elements in ascending order
	else if (choice3 == 2)
		a->ReverseDisplay(B, choice2);// would display the sorted elements in descending order


}
void prompting() {
	int choice1, choice2, choice3, choice4;
	Sort<long>* a = new Sort<long>();
	Sort<float>* b = new Sort<float>();
	Sort<string>* c = new Sort<string>();
	cout << "Which data type you want to perform sorting on(1.long,2.float,3.strings)?" << endl;
	cin >> choice1;
	switch (choice1) {
	case 1:
		prompting2(a, choice1);
		break;
	case 2:
		prompting2(b, choice1);
		break;
	case 3:
		prompting2(c, choice1);
		break;
	default:
		cout << "Incorrect choice! try again" << endl;
		cin >> choice1;
		break;
	}
}

int main() {
	prompting();
}
