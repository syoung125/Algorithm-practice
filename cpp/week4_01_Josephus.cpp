#include <iostream>
#include <list>
using namespace std;

int n, k;
list<int> List;

void printList() {
	list<int>::iterator iter;
	for (iter = List.begin(); iter != List.end(); iter++)
		cout << *iter << ' ';

	cout << endl;
}


list<int>::iterator kill(list<int>::iterator turn) {
	list<int>::iterator nextTurn;
	nextTurn = turn;		

	for (int i = 0; i < k; i++) {
		// p=lt.end() ---> p는 lt의 끝을 표식하는 반복자 -->근데 이게 계쏙 안됨...왜??
		// 그래서 list의 마지막 원소 List.back() 사용
		if (*nextTurn != List.back()) nextTurn++;
		else nextTurn = List.begin();

		if (*turn == *nextTurn) i--;
	}
	
	turn = List.erase(turn);
	return nextTurn; 
}


int main() {
	int C; // C: 테스트 케이스 수
	cin >> C;
	while (C-- > 0) {
		cin >> n >> k;
		List.clear();
		for (int i = 0; i < n; i++) {
			List.push_back(i+1);
		}

		list<int>::iterator turn = List.begin();
		while (List.size() > 2) {
			turn = kill(turn);
		}
		printList();
	}
	return 0;
}