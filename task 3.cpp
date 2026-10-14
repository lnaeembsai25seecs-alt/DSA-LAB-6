#include <iostream>
#include <vector>

using namespace std;

// Merges two sorted subarrays arr[left..mid] and arr[mid+1..right]
void merge(vector<int>& arr, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	// Create temporary arrays to hold left and right halves
	vector<int> L(n1);
	vector<int> R(n2);

	for (int i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = arr[mid + 1 + j];
	}

	int i = 0;    // Initial index of first subarray (L)
	int j = 0;    // Initial index of second subarray (R)
	int k = left; // Initial index of merged subarray (arr)

	// Merge temporary arrays back into arr[left..right]
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy any remaining elements of L[]
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy any remaining elements of R[]
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// Recursively divides and sorts the array
void mergeSort(vector<int>& arr, int left, int right) {
	// Base case: range contains 0 or 1 element
	if (left >= right) {
		return;
	}

	int mid = left + (right - left) / 2;

	// Recursively sort first and second halves
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);

	// Merge the sorted halves
	merge(arr, left, mid, right);
}

// Displays the array before and after sorting
void displayArray(const vector<int>& arr) {
	cout << "[";
	for (size_t i = 0; i < arr.size(); i++) {
		cout << arr[i] << (i + 1 < arr.size() ? ", " : "");
	}
	cout << "]" << endl;
}

int main() {
	int n;
	cout << "Enter the number of student marks (n): ";
	cin >> n;

	vector<int> marks;

	if (n > 0) {
		marks.resize(n);
		cout << "Enter " << n << " student marks: ";
		for (int i = 0; i < n; i++) {
			cin >> marks[i];
		}
	}

	cout << "\nBefore Sorting: ";
	displayArray(marks);

	// Perform merge sort if there are 2 or more elements
	if (n > 1) {
		mergeSort(marks, 0, n - 1);
	}

	cout << "After Sorting:  ";
	displayArray(marks);

	return 0;
}