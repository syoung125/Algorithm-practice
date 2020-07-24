/*
알고리즘 스터디 3주차 문제 2 - JLIS
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, M; // A와 B의 길이
int A[100], B[100];
int cache[101][101];

int jlis(int aidx, int bidx, int num) {
	int& res = cache[aidx + 1][bidx + 1];
	if (res != -1) return res;

	res = 2;
	for (int i = aidx + 1; i < N; i++) {
		if ((aidx == -1 && bidx == -1) || num < A[i]) {
			res = max(res, jlis(i, bidx, A[i]) + 1);
		}
	}
	for (int i = bidx + 1; i < M; i++) {
		if ((aidx == -1 && bidx == -1) || num < B[i]) {
			res = max(res, jlis(aidx, i, B[i]) + 1);
		}
	}

	return res;
}

int main() {
	int C; // C: 테스트 케이스 수
	cin >> C;
	while (C-- > 0) {
		memset(cache, -1, sizeof(cache));
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> B[i];
		}

		cout << jlis(-1, -1, 0) - 2 << endl;
	}
	return 0;
}