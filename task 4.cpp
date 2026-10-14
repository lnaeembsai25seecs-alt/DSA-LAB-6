#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;


const int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };


bool isValid(int x, int y, int N, const vector<vector<int>>& board) {
	return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}


int getDegree(int x, int y, int N, const vector<vector<int>>& board) {
	int count = 0;
	for (int i = 0; i < 8; i++) {
		if (isValid(x + dx[i], y + dy[i], N, board)) {
			count++;
		}
	}
	return count;
}

struct MoveOption {
	int moveIdx;
	int degree;
};


bool solveKnightTour(int row, int col, int moveNumber, int N, vector<vector<int>>& board) {
	
	if (moveNumber == N * N) {
		return true;
	}

	
	vector<MoveOption> candidates;
	for (int i = 0; i < 8; i++) {
		int nextX = row + dx[i];
		int nextY = col + dy[i];
		if (isValid(nextX, nextY, N, board)) {
			int deg = getDegree(nextX, nextY, N, board);
			candidates.push_back({ i, deg });
		}
	}

	
	sort(candidates.begin(), candidates.end(), [](const MoveOption& a, const MoveOption& b) {
		return a.degree < b.degree;
	});

	// Try candidate moves in sorted heuristic order
	for (const auto& cand : candidates) {
		int nextX = row + dx[cand.moveIdx];
		int nextY = col + dy[cand.moveIdx];

		board[nextX][nextY] = moveNumber + 1; // Make move

		if (solveKnightTour(nextX, nextY, moveNumber + 1, N, board)) {
			return true;
		}

		board[nextX][nextY] = -1; // Backtrack
	}

	return false;
}

int main() {
	int N, startX, startY;
	cout << "Enter Board Size N: ";
	cin >> N;
	cout << "Enter Starting Row (0 to " << N - 1 << ") and Column (0 to " << N - 1 << "): ";
	cin >> startX >> startY;

	if (startX < 0 || startX >= N || startY < 0 || startY >= N) {
		cout << "Invalid starting position!" << endl;
		return 1;
	}

	vector<vector<int>> board(N, vector<int>(N, -1));
	board[startX][startY] = 1; // Mark initial position

	if (solveKnightTour(startX, startY, 1, N, board)) {
		cout << "\nKnight's Tour found:\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << setw(4) << board[i][j];
			}
			cout << "\n";
		}
	}
	else {
		cout << "No valid Knight's Tour exists starting from (" << startX << ", " << startY << ")." << endl;
	}

	return 0;
}