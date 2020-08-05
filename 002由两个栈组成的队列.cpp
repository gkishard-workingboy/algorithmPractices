#include<stack>
#include<iostream>

using namespace std;

/**
 * @author GK
 * @time 2020/8/4
 * @function 编写一个类，用两个栈实现队列，支持队列基本操作 add poll peek
 */
class DuoStackQueue{
		stack<int> sin;
		stack<int> sout;
	public:
		void add(int);
		int poll();
		int peek();
//		DuoStackQueue():{}
};

void DuoStackQueue::add(int input){
//	if (inflag){
//		sin.clear();
//		for (int i = sout.size(); i > 0; --i){
//			sin.push(sout.top());
//			sout.pop();
//		}
//		inflag = false;
//	}
	sin.push(input);
//	if (!outflag)
//		outflag = true;
	return;
}


int DuoStackQueue::poll(){
//	if (outflag){
//		sout.clear();
//		for (int i = sin.size(); i > 0; --i){
//			sout.push(sin.top());
//			sin.pop();
//		}
//		outflag = false;
//	}
	if (sout.empty()){
		if (sin.empty())
			return -1;
		for (int i = sin.size(); i > 0; --i){
			sout.push(sin.top());
			sin.pop();
		}
	}
	int value = sout.top();
	sout.pop();
//	if out
	return value;
}


int DuoStackQueue::peek(){
	if (sout.empty()){
		if (sin.empty())
			return -1;
		for (int i = sin.size(); i > 0; --i){
			sout.push(sin.top());
			sin.pop();
		}
	}
	return sout.top();
}


int main(void){
	DuoStackQueue dsq;
	dsq.add(1);
	cout << dsq.peek() << endl;
	dsq.add(2);
	dsq.add(3);
	dsq.add(4);
	dsq.add(5);
	dsq.add(6);

	for (int i = 6; i > 0; --i)
		cout << dsq.poll() << "\t" << dsq.peek() << endl;

	return 0;
}
