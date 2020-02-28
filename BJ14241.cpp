#include <iostream>
#include <algorithm>	// to use sort() library
using namespace std;

/*
Link(슬라임 합치기)
: https://www.acmicpc.net/problem/14241
*/

int main() {
	int n, score = 0; // n: number of slime, score: total score
	cin >> n;
	int* arr = new int[n];
	//cout << "The number of slimes : " + n << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, greater<int>());	// greater -> descending order sort
	int add;
	for (int i = 1; i < n; i++) {
		//cout << arr[i];
		if (i == 1) {
			score += arr[i-1] * arr[i];
			add = arr[i-1] + arr[i];
		}
		else {
			score += add * arr[i];
			add += arr[i];
		}
	}
	cout << score << endl;
}