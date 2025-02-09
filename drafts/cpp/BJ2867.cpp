#include <iostream>
#include <cmath>
using namespace std;

/*
2867 - 수열의 값 => 시간초과 => 다시
https://www.acmicpc.net/problem/2867
*/

int main() {
	int n, sum = 0; // sum: 수열의 값의 합
	cin >> n; // size of Sequence
	int* arr = new int[n];
	int MIN = 100000000, MAX = 0;
	int minIdx, maxIdx;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] < MIN) {
			MIN = arr[i];
			minIdx = i;
		}
		if (arr[i] > MAX) {
			MAX = arr[i];
			maxIdx = i;
		}
		// 두개 차 구하기
		if (i > 0) sum += abs(arr[i] - arr[i - 1]);
	}
	
	for (int i = 3; i <= n; i++) {
		for (int j = 0; j + i <= n; j++) {
			// index range : (j, j+i)
			if ((minIdx > j&& minIdx < (j + i)) && (maxIdx > j&& maxIdx < (j + i))) {
				sum += (MAX - MIN);
			}
			else if (minIdx > j&& minIdx < (j + i)) {
				//min = MIN, max 찾아야함
			}
			else if (maxIdx > j&& maxIdx < (j + i)) {
				//max = MAX, min 찾아야함
			}
			else {

			}
		}
	}

	cout << sum;
}