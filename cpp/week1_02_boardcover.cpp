/*
알고리즘 스터디 1주차 문제 2 - 게임판 덮기
*/

#include <iostream>
using namespace std;

int H=0, W=0;
int board[22][22];	//테두리 검정색으로
int block[4][2][2] = {
	{{-1,1}, {0,1}},
	{{1,0}, {0,1}},
	{{0,1}, {1,1}},
	{{1,0}, {1,1}}
}; // 0: white, 1: black

int emptyCount = 0; // 빈칸 수
int Count = 0;	// 빈칸 채운수
int way = 0;	// 방법 수
void game();

void print()
{
	for (int i = 0; i <= H+1; i++)
	{
		for (int j = 0; j <= W+1; j++)
			cout << board[i][j];
		cout << endl;
	}
	cout << endl;
}

int main() {
	int C;
	cin >> C;
	for (int tc = 0; tc < C; tc++) {
		way = 0;
		emptyCount = 0;
		Count = 0;
		cin >> H >> W;
		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 22; j++) {
				board[i][j] = 1;
			}
		}
		for (int h = 1; h <= H; h++) {
			for (int w = 1; w <= W; w++) {
				char temp;
				cin >> temp;
				if (temp == '.') {
					board[h][w] = 0;
					emptyCount++;
				}
			}
		}
		if (emptyCount % 3 != 0) {
			cout << way << endl;
			continue;
		}
		else {
			game();
			cout << way << endl;
		}

	}

	return 0;
}

void game() {
	int h = 1, w = 1;
	bool flag = false;

	// 비어있는 칸 탐색 (테두리는 벽으로 막음 -> 1부터 시작)
	for (h = 1; h <= H; h++) {
		for (w = 1; w <= W; w++) {
			// 비어있으면
			if (board[h][w] == 0) {
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	// 다채웠으면
	if (emptyCount == Count) way++;
	if (!flag) return;

	for (int i = 0; i < 4; i++) {
		//(board[여기가 y좌표][여기가 x좌표])
		int sum = board[h + block[i][0][1]][w + block[i][0][0]] + board[h + block[i][1][1]][w + block[i][1][0]];
		if (sum == 0) {
			// 블럭 넣을 수 있음
			board[h][w] = 1;
			board[h + block[i][0][1]][w + block[i][0][0]] = 1;
			board[h + block[i][1][1]][w + block[i][1][0]] = 1;
			Count += 3;
			game();
			board[h][w] = 0;
			board[h + block[i][0][1]][w + block[i][0][0]] = 0;
			board[h + block[i][1][1]][w + block[i][1][0]] = 0;
			Count -= 3;
		}

	}

}