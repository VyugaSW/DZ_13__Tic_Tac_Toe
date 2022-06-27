#include <iostream>
#include <Windows.h>

using namespace std;
char board[3][3];
char t;

void FillTheBoard(char(*board)[3]);
void DrawTheBoard(char(*board)[3]);
void Player1Step(char(*board)[3]);
void Player2Step(char(*board)[3]);
bool WinCheck(char(*board)[3], int P);
void ProccesPlaying(char(*board)[3]);

int main()
{
	cout << "Wish to start? (y/n)\n";
	cin >> t;
	FillTheBoard(board);
	ProccesPlaying(board);
}
//The procession of the game
void ProccesPlaying(char(*board)[3]) {
	while (t == 'y') {
		DrawTheBoard(board);
		Player1Step(board);
		system("cls");
		if (WinCheck(board, 1)) { // Player 1
			system("cls");
			cout << "\n\t\tPlayer 1 have winned!\n\n";
			break;			
		}
		system("cls");
		DrawTheBoard(board);
		Player2Step(board);
		system("cls");
		if (WinCheck(board, 2)) { // Player 1
			system("cls");
			cout << "\n\t\tPlayer 2 have winned!\n\n";
			break;			
		}
	}
	if (t == 'y') {
		cout << "Do you want to continue? (y/n)\n"; cin >> t;
		if (t == 'y') {
			system("cls");
			ProccesPlaying(board);
		}
	}
}
//Actions with the board
void FillTheBoard(char(*board)[3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = '#';
		}
	}
}
void DrawTheBoard(char(*board)[3]) {
	cout << "   0   1   2\n";
	cout << "  --- --- --- \n";
	for (int i = 0; i < 3; i++) {
		cout << i << "| ";
		for (int j = 0; j < 3; j++) {
			cout << board[i][j] << " | ";
		}
		cout << endl;
		cout << "  ------------";
		cout << endl;
	}
}
//Players moves
void Player1Step(char(*board)[3]) {
	int x, y;
	cout << "Step of Player 1:\n\n";
	cout << "Enter x - "; cin >> x;
	cout << "Enter y - "; cin >> y;
	if (board[y][x] == '#') {
		board[y][x] = '0';
	}
	else {
		cout << "Wrong!, Please try one more time:\n\n";
		system("cls");
		DrawTheBoard(board);
		Player1Step(board);
	}
}
void Player2Step(char(*board)[3]) {
	int x, y;
	cout << "Step of Player 2:\n\n";
	cout << "Enter x - "; cin >> x;
	cout << "Enter y - "; cin >> y;
	if (board[y][x] == '#') {
		board[y][x] = 'X';
	}
	else {
		system("cls");
		DrawTheBoard(board);
		cout << "Wrong!, Please try one more time:\n\n";
		Player2Step(board);
	}
}
//Check the winner
bool WinCheck(char(*board)[3], int P) {
	if (P == 1) {
		if (board[0][0] == '0' and board[1][1] == '0' and board[2][2] == '0')
			return true;
		else if (board[0][2] == '0' and board[1][1] == '0' and board[2][0] == '0')
			return true;

		else if (board[0][0] == '0' and board[0][1] == '0' and board[0][2] == '0')
			return true;
		else if (board[1][0] == '0' and board[1][1] == '0' and board[1][2] == '0')
			return true;
		else if (board[2][0] == '0' and board[2][1] == '0' and board[2][2] == '0')
			return true;

		else if (board[0][0] == '0' and board[1][0] == '0' and board[2][0] == '0')
			return true;
		else if (board[0][1] == '0' and board[1][1] == '0' and board[2][1] == '0')
			return true;
		else if (board[0][2] == '0' and board[1][2] == '0' and board[2][2] == '0')
			return true;
		else return false;
	}
	else if (P == 2) {
		if (board[0][0] == '0' and board[1][1] == '0' and board[2][2] == '0')
			return true;
		else if (board[0][2] == '0' and board[1][1] == '0' and board[2][0] == '0')
			return true;

		else if (board[0][0] == '0' and board[0][1] == '0' and board[0][2] == '0')
			return true;
		else if (board[1][0] == '0' and board[1][1] == '0' and board[1][2] == '0')
			return true;
		else if (board[2][0] == '0' and board[2][1] == '0' and board[2][2] == '0')
			return true;

		else if (board[0][0] == '0' and board[1][0] == '0' and board[2][0] == '0')
			return true;
		else if (board[0][1] == '0' and board[1][1] == '0' and board[2][1] == '0')
			return true;
		else if (board[0][2] == '0' and board[1][2] == '0' and board[2][2] == '0')
			return true;
		else return false;
	}
}
