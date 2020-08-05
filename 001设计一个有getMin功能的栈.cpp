#include<stack>
#include<iostream>

using namespace std;

/**
 * @author GK
 * @time 2020/8/4
 * @function 实现一个具有getMin功能的栈
 *           要求pop,push,getMin的操作时间复杂度为 O(1)
**/
class MinStack{
       stack<int> datastack;
       stack<int> stackMin;

   public:
	   int push(int);
	   int pop();
	   int getMin();

};

int MinStack::push(int input){
			datastack.push(input);
			if (stackMin.empty() || stackMin.top() >= input)
				stackMin.push(input);
			return 0;
}

int MinStack::pop(){
	if (datastack.size() > 0){
		int value = datastack.top();
		datastack.pop();
		if (value == stackMin.top())
			stackMin.pop();
		return value;
	}
	else
		return -1;
}

int MinStack::getMin(){
	if (!datastack.empty())
		return stackMin.top();
	else
		return -1;
}



int main(void){
	MinStack ms;
	ms.push(12);
	ms.push(16);
	ms.push(12);
	ms.push(11);
	ms.push(6);
	ms.push(4);
	ms.push(7);
	ms.push(2);

	for (int i = 8; i > 0 ; --i){
		cout << "Pop:" << ms.pop() << "\tMin:" << ms.getMin() << endl; //注意 cout 是左结合，因此可以在cout输出语句中 “先”pop“后”getMin 但其实执行顺序恰恰相反。十分值得注意！！！
	}

    return 0;

}
