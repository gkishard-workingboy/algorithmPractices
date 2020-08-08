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

using namespace std;

/**
 * @author
 * @date 2020-08-08
 * @description
 *		给定一个不含有重复值的数组arr，找到每一个i位置左边和右边离i位置最近且值比arr[i]小的位置。返回所有位置相应的信息
**/

void findClosestIndex(vector<int>& arr, vector<vector<int> >& result){
    // N.B. this function cannot process array having repetitive numerics.
    stack<int> s;
    int n = arr.size();
    int left, right;
    for (int i = 0; i < n; ++i){
        while (!s.empty() && arr[s.top()] > arr[i]){
            right = s.top();
            result[right][1] = i;
            s.pop();
        }
        if (s.empty())
            left = -1;
        else
            left = s.top();
        // cout << i << " " ;
        s.push(i);
        result[i][0] = left;
        // cout << n << " " ;
    }
    while (!s.empty()){
        result[s.top()][1] = -1;
        s.pop();
    }
}

void findClosestIndexUpgraded(vector<int>& arr, vector<vector<int> >& result){
// N.B. This function can be used both in array with and without repetitive numerics.
    stack<vector<int> > s;
    vector<int> v;
    int n = arr.size();
    for (int i = 0; i < n; ++i){
        while (!s.empty() && arr[s.top().back()] > arr[i]){
            for (const auto& right : s.top())
                result[right][1] = i; 
            s.pop();
        }
        if (s.empty()){
            v.push_back(i);
            s.push(v);
            result[i][0] = -1;
        }else if (arr[s.top().back()] == arr[i]){
            result[i][0] = s.top().back();
            s.top().push_back(i);
        }else{
            result[i][0] = s.top().back();
            v.push_back(i);
            s.push(v);
        }
        v.clear();
    }
    while (!s.empty()){
        for (const auto& item: s.top())
            result[item][1] = -1;
        s.pop();
    }
}

int main(void){
    vector<int> test = {3, 4, 1, 5, 6, 2, 7};
    vector<vector<int> > res(test.size(), vector<int>(2));
    findClosestIndex(test, res);
    for (auto& i : res)
        printf("(%d, %d)\n", i[0], i[1]);
    cout << "-------------------------------------------------------------------" << endl;
    vector<int> test2 = {3, 1, 3, 4, 3, 5, 3, 2, 2};
    vector<vector<int> > res2(test2.size(), vector<int>(2));
    findClosestIndexUpgraded(test2, res2);
    for (auto& i : res2)
        printf("(%d, %d)\n", i[0], i[1]);
    return 0;
}
