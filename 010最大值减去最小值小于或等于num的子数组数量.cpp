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
 * @author
 * @date 2020-08-09
 * @description
 *     给定数组arr和整数num，共返回有多少个子数组满足如下情况：
 *     max(arr[i..j]) - min(arr[i..j]) <= num
 *     请实现O(N)的算法
 **/

int getNumOfSubarrayWithRangeBelow(vector<int>& arr, int num){
    int n = arr.size();//给定数组的大小
    deque<int> qmax(1);//最大值窗口结构
    deque<int> qmin(1);//最小值窗口结构
    int res = 0;//结果数
    for (int i = 0, j = 1; i < n; ++i){
        while (!qmax.empty() && qmax.front() < i)
            qmax.pop_front();
        while (!qmin.empty() && qmin.front() < i)
            qmin.pop_front();
        while (arr[qmax.front()] - arr[qmin.front()] <= num && j < n){
            while (!qmax.empty() && arr[qmax.front()] <= arr[j])
                qmax.pop_back();
            qmax.push_back(j);
            while (!qmin.empty() && arr[qmin.front()] >= arr[j])
                qmin.pop_back();
            qmin.push_back(j);
            ++j;
        }
        if (arr[qmax.front()] - arr[qmin.front()] <= num && j == n){
			res += (1 + j - i) * (j - i) / 2;
			break;
        }else
			res += j - i - 1;
    }
    return res;
}

int main(void){
    vector<int> arr = {1, 2, 3, 4};
    cout << "result: " << getNumOfSubarrayWithRangeBelow(arr, 2);

    return 0;
}
