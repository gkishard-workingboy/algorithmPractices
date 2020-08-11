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
#include <deque>
#include <list>
#include <utility>

using namespace std;

/** 
 * @author GK
 * @date 2020-08-11
 * @description
 *     一个不含有负数的数组可以代表一圈环形山，每个位置的值代表山的高度。
 *     山峰A和B能够相互看见的条件为：
 *      1. 如果A和B是同一座山，认为不能相互看见。
 *      2. 如果A和B是不同的山，并且在环中相邻，认为可以相互看见。
 *      3. 如果A和B是不同的山，并且在环中不相邻，假设两座山的高度的最小值为min。如果A通过顺时针或逆时针的方向到达B的图中没有高度比min大的山峰，认为A和B可以相互看见。
 *      给定一个不含有负数且没有重复数组的arr，请返回有多少对山峰可以相互看见。
 *      进阶问题：给定一个不含有负数但可能有重复值的数组arr，返回有多少对山峰能够相互看见。
 *      要求：
 *          如果arr长度为N，没有重复值的情况下时间复杂度为O(1)，可能有重复值的情况下的时间复杂度为O(N)。
 **/

void printVector(vector<int>& arr){
    if (!arr.empty())
        for (auto& item : arr)
            cout << item << " " ;
    cout << endl;
}

struct Record{
    int value;
    int times;
    Record(int v):value(v),times(1){};
};
// 1.当数组中所有的数值都不一样那么可见山峰对的数量可以由简单公式得到。一座山：0 两座山：1 i座山：2i-3
// 2.当数组中有重复数值时，使用单调栈结构。
int findVisibleMountainPairs(vector<int>& mountains){
    int n = mountains.size(), res = 0;
    if (n < 3)
        return n == 1 ? 0 : 1;
    int maxindex = max_element(mountains.begin(), mountains.end()) - mountains.begin();
    stack<Record> monoStack;
    for (int i = 0; i < n; ++i){
        int cur = i + maxindex < n ? i + maxindex : (i + maxindex) % n;
        Record r(mountains[cur]);
        while (!monoStack.empty() && monoStack.top().value < r.value){
            int k = monoStack.top().times;
            res += k * (k + 3) / 2;
            monoStack.pop();
        }
        if (monoStack.empty() || monoStack.top().value > r.value)
            monoStack.push(r);
        else
            ++monoStack.top().times;
    }
    while (!monoStack.empty()){
        int k = monoStack.top().times;
        monoStack.pop();
        if (monoStack.size() > 1)
            res += k * (k + 3) / 2;
        else if (monoStack.size() == 1)
            if (monoStack.top().times > 1)
                res += k * (k + 3) / 2;
            else
                res += k * (k + 1) / 2;
        else 
            res += k * (k - 1) / 2;
    }
    return res;
}

int main(void){
    vector<int> mountains = {3, 2, 5, 4, 3, 5, 4, 2, 4, 4, 5};
    cout << "result: " << findVisibleMountainPairs(mountains) << endl;
    return 0;
}