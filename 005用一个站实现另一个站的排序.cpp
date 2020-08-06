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
 * @author GK
 * @date 2020-08-06
 * @function
 *   一个栈中元素的类型为整型，现在想将该栈从顶到底从大到小的顺序排序，只许申请一个栈。
 *   除此之外，可以申请新的变量，但不能申请额外的数据结构。
**/

void printStack(stack<int>* s){
    int n = s->size();
    vector<int> temp;
    for(int i = 0; i < n; ++i){
		printf("idx:%d  value:%d\n", i, s->top());
		temp.push_back(s->top());
		s->pop();
    }
    for(auto i = temp.rbegin(); i != temp.rend(); ++i)
		s->push(*i);
}

void sortStackByStack(stack<int>& s){
	stack<int> sup;
	while (!s.empty()){
		int cur  = s.top();
		s.pop();
		while(!sup.empty() && cur > sup.top()){
			s.push(sup.top());
			sup.pop();
		}
		sup.push(cur);
	}
	s.swap(sup);
}

int main(void){
	stack<int> s;
	default_random_engine e(time(0));
	uniform_int_distribution<unsigned> u(0,100);
	for (int _ = 0; _ < 10; ++_){
		s.push(u(e));
	}
	cout << "origin:" << endl;
	printStack(&s);
	sortStackByStack(s);
	cout << endl << "after:" << endl;
	printStack(&s);
    return 0;
}
