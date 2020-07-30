/*
알고리즘 스터디 4주차 문제 2 - 짝이 맞지 않는 괄호
*/

#include <iostream>
#include <stack>
using namespace std;

string bStr;

int main() {
	int C;
	cin >> C;
	while (C-- > 0) {
		cin >> bStr;
		stack<char> s;

		bool isSuccess = true;
		for (int i = 0; i < bStr.size(); i++) {
			switch (bStr[i]) {
			case '(':
				s.push(')');
				break;
			case '{':
				s.push('}');
				break;
			case '[':
				s.push(']');
				break;
			case ')':
			case '}':
			case ']':
				if (!s.empty() && (bStr[i] == s.top())) s.pop();
				else isSuccess = false;
				break;
			default:
				break;
			}
			if (!isSuccess) break;
		}

		if (isSuccess && s.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}