/*
알고리즘 스터디 1주차 문제 1 - 소풍
*/

#include <iostream>
#include <vector>
using namespace std;

int n = 0, m = 0;	// n: 학생 수, m: 친구 쌍의 수
int way = 0; // 짝지을 수 있는 경우의 수

bool* nArr;
vector<int>* nVec;

void Pair(bool success);

int main() {
	int C; // C: 테스트 케이스 수
	int a, b;	// 순서 쌍
	int i, j;

	cin >> C;

	for (int test = 0; test < C; test++) {
		way = 0;
		cin >> n >> m;
		nArr = new bool[n];
		nVec = new vector<int>[n];

		for (i = 0; i < n; i++) {
			nArr[i] = false;
		}
		for (i = 0; i < m; i++) {
			cin >> a >> b;	// 순서쌍
			nVec[a].push_back(b);
			nVec[b].push_back(a);
		}
		
		Pair(true);
		cout << way << endl;
	}

	return 0;
}

void Pair(bool success) {
	if (!success) return;

	int node = -1;	// 짝없는 노드
	for (int i = 0; i < n; i++) {
		if (!nArr[i]) {
			node = i;
			break;
		}
	}

	if (node == -1) {
		way++;
		return;
	}
	
	for (int i = 0; i < nVec[node].size(); i++) {
		if (!nArr[nVec[node][i]]) {
			nArr[node] = true;
			nArr[nVec[node][i]] = true;

			Pair(true);

			nArr[node] = false;
			nArr[nVec[node][i]] = false;
		}
		// 실패한 경우
		else if (i == nVec[node].size() - 1) Pair(false);
	}

}