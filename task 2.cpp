#include <iostream>
#include <vector>

using namespace std;

// Reads the registration numbers in ascending order
void inputSortedIDs(vector<int>& arr, int n) {
	arr.resize(n);
	cout << "Enter " << n << " sorted student IDs: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

// Checks whether the input is sorted in non-decreasing order
bool isSorted(const vector<int>& arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

int binarySearch(const vector<int>& arr, int low, int high, int target) {
	while (low <= high) {
		
		int mid = low + (high - low) / 2;

		if (arr[mid] == target) {
			return mid; // Target found
		}
		else if (arr[mid] > target) {
			high = mid - 1; 
		}
		else {
			low = mid + 1; 
		}
	}
	return -1; // Target absent
}

int main() {
	int n, target;
	cout << "Enter number of student IDs: ";
	cin >> n;

	vector<int> arr;
	if (n > 0) {
		inputSortedIDs(arr, n);
		if (!isSorted(arr, n)) {
			cout << "Error: Provided array is not sorted in non-decreasing order!" << endl;
			return 1;
		}
	}

	cout << "Enter target ID to search: ";
	cin >> target;

	int result = binarySearch(arr, 0, n - 1, target);
	if (result != -1) {
		cout << "Index " << result << endl;
	}
	else {
		cout << "Not found" << endl;
	}

	return 0;
}