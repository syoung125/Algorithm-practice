/*
알고리즘 스터디 4주차 문제 3 - 외계 신호 분석
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int K, N;

// 원래는 배열 A를 초기화 하는 코드를 넣어서 vector<int> signals에 값들을 다 초기화 하여 저장했는데
// 런타임 오류 --> 굳이 그 값들을 저장할 필요가 없었음
int findPartialSequence() {
	queue<int> subSeq;
	int subSum = 0;
	int count = 0;
	int signal = 0;

	long long int Ai_1 = 1983;
	long long int pow2_32 = pow(2, 32);

	for (int i = 0; i < N; i++) {
		signal = Ai_1 % 10000 + 1;
		Ai_1 = ((long long int)Ai_1 * 214013 + 2531011) % pow2_32;

		subSeq.push(signal);
		subSum += signal;

		while (!subSeq.empty() && subSum > K) {
			subSum -= subSeq.front();
			subSeq.pop();
		}

		if (subSum == K) count++;
	}

	return count;
}


int main() {
	int C;
	cin >> C;
	while (C-- > 0) {
		cin >> K >> N;
		cout << findPartialSequence() <<endl;
	}
	return 0;
}