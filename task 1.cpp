#include <iostream>
#include <vector>

using namespace std;

void inputIDs(vector<int>& arr, int n) {
	arr.resize(n);
	cout << "Enter " << n << " student IDs: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}


int linearSearch(const vector<int>& arr, int n, int target) {
	if (n <= 0 || arr.empty()) {
		return -1; // Handle empty array
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] == target) {
			return i; 
		}
	}
	return -1; // Target not found
}

// Displays the search result
void displayResult(int index) {
	if (index != -1) {
		cout << "Index " << index << endl;
	}
	else {
		cout << "Not found" << endl;
	}
}

int main() {
	int n, target;
	cout << "Enter number of student IDs: ";
	cin >> n;

	vector<int> arr;
	if (n > 0) {
		inputIDs(arr, n);
	}

	cout << "Enter target ID to search: ";
	cin >> target;

	int result = linearSearch(arr, n, target);
	displayResult(result);

	return 0;
}