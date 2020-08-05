#include<stack>
#include<iostream>

using namespace std;

/**
 * @author GK
 * @time 2020/8/4
 * @function 一个栈依次压入1,2,3,4,5，那么从栈顶到栈底分别为5,4,3,2,1。将这个栈转置后，
 * 			 从栈顶到栈底为1,2,3,4,5,也就是实现栈中元素的逆序，但是只能用递归函数来实现，不能用其他数据结构。
**/

int getLastElement(stack<int> s){
	int value = s.top();
	s.pop();
	if (s.empty()){
		return value;
	}
	int last = getLastElement(s);
	s.push(value);
	return last;
}


void reverse(stack<int> s){
    int value = getLastElement(s);
    if (s.empty());
		s.push(value);
    reverse(s);
	s.push(value);
	return;
}


void printStack(stack<int> s){
	while (!s.empty()){
		cout << s.top() << ',';
		s.pop();
	}
	cout << endl;
}


int main(void){
	stack<int> s;
    for (int i = 10; i > 0; --i)
		s.push(i);
    printStack(s);
    reverse(s);
    printStack(s);
}
