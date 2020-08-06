#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <random>
#include <cmath>
#include <chrono>
#include <ctime>

using namespace std;

/**
 * @author
 * @date 2020-08-06
 * @function
 *		Tower of Hanoi
 * 		游戏规则： 现在限制不能直接从最左侧移动到最右侧，也不能反过来，而是必须经过中间。
 *		求当塔有n层的时候，打印最优移动过程和最优移动总步数。
**/

static vector<string> label = {"left", "mid", "right"};
enum operation{
		LM = 0,
		RM = 1,
		MR = 2,
		ML = 3
	};
void moveHanoi(int, int, int, int&);
void moveHanoi(vector<stack<int> >&, operation);
int movable(vector<stack<int> >&, operation);

// 1. recursive implementation
void recHanoi(int n) {
	if (n < 1)
		return;
    int steps = 0;
    cout << endl << "Recursive implementation:" << endl;
    moveHanoi(0, 2, n-1, steps);
    printf("Move %d from %s to %s\n", n, label[0].c_str(), label[1].c_str());
    ++steps;
    moveHanoi(2, 0, n-1, steps);
    printf("Move %d from %s to %s\n", n, label[1].c_str(), label[2].c_str());
    ++steps;
    moveHanoi(0, 2, n-1, steps);
    printf("It will move %d steps\n",steps);
}

void moveHanoi(int from, int to, int n, int& steps) {
    if(n < 2) {
        printf("Move %d from %s to %s\n", n, label[from].c_str(), label[1].c_str());
        printf("Move %d from %s to %s\n", n, label[1].c_str(), label[to].c_str());
        steps +=2;
        return;
    }
    moveHanoi(from, to, n-1, steps);
    printf("Move %d from %s to %s\n", n, label[from].c_str(), label[1].c_str());
    ++steps;
    moveHanoi(to, from, n-1, steps);
    printf("Move %d from %s to %s\n", n, label[1].c_str(), label[to].c_str());
    ++steps;
    moveHanoi(from, to, n-1, steps);
}


// 2. non-recursive implementation
void stackHanoi(int n) {
	if (n < 1)
		return;
    cout << endl << "Non-recursive implementation:" << endl;
	vector<stack<int> > hanoi(3);
	stack<int>& left = hanoi[0];
	stack<int>& mid = hanoi[1];
	stack<int>& right = hanoi[2];

	for (int _ = n; _ > 0; --_)
		left.push(_);

	operation last = LM;
	operation cur;
	moveHanoi(hanoi, last);
	int steps = 1;
    while (right.size() != n){
		for (int _ = 0; _ < 4; ++_)
			if ((int)(_ ^ last) != 3 && movable(hanoi, (operation)_))
				cur = (operation)_;
		int a = cur ^ last;
        moveHanoi(hanoi, cur);
        ++steps;
        last = cur;
    }
	printf("It will move %d steps\n",steps);
}

int movable(vector<stack<int> >& _, operation type){
	int from, to;
	switch (type){
		case LM:
			from = 0, to = 1;
			break;
		case RM:
			from = 2, to = 1;
			break;
		case MR:
			from = 1, to = 2;
			break;
		case ML:
			from = 1, to = 0;
			break;
		default:
			return 0;
	}
	if(_[from].empty())
		return 0;
	else if(_[to].empty())
		return 1;
	else
		return _[from].top() < _[to].top();
}

void moveHanoi(vector<stack<int> >& _, operation type){
	int from, to;
	switch (type){
		case LM:
			from = 0, to = 1;
			break;
		case RM:
			from = 2, to = 1;
			break;
		case MR:
			from = 1, to = 2;
			break;
		case ML:
			from = 1, to = 0;
			break;
		default:
			return;
	}
    int k = _[from].top();
    _[to].push(k);
    _[from].pop();
    printf("Move %d from %s to %s\n", k, label[from].c_str(), label[to].c_str());
}


int main(void) {
    // 1
    recHanoi(3);
	// 2
	stackHanoi(3);

    return 0;
}
