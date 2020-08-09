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
 *		给定一个整型矩阵map，其中的值只有0和1两种，求其中全是1的所有矩形区域中，最大的矩形区域为1的数量
**/

int getBiggestSubarraySize(vector<vector<int> >& map){
    int n = map.size(), m = map.front().size();
    vector<int> height(m);//高度数组：存放每一层的，相应列的高度
    stack<list<int> > monoStack;//单调栈：判断一个高度左右最近的点的索引，以此来计算对应的面积。
    list<int> temp;//链表数据暂存，方便存入单调栈
    vector<pair<int, int> > res(m);//单调栈得出的结果
    int size = 0;//返回值，保存最大的面积
    int area = 0;//面积，计算当前的面积
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (map[i][j] == 1)
                ++height[j];
            else
                height[j] = 0;
        }
        for (int j = 0; j < m; ++j){
            while (!monoStack.empty() && height[monoStack.top().back()] > height[j]){
                for (const auto& item : monoStack.top())
                    res[item].second = j;
                monoStack.pop();
            }
            if (monoStack.empty()){
                res[j] = make_pair(-1, 0);
                temp.push_back(j);
                monoStack.push(temp);
            }else if (height[monoStack.top().back()] == height[j]){
                res[j] = make_pair(res[monoStack.top().front()].first, 0);
                monoStack.top().push_back(j);
            }else {
                res[j] = make_pair(monoStack.top().back(), 0);
                temp.push_back(j);
                monoStack.push(temp);
            }
            temp.clear();
        }
        while (!monoStack.empty()){
            for (auto& item : monoStack.top())
                res[item].second = m;
            monoStack.pop();
        }
        for (int i = 0; i < m; ++i){
            if (height[i]){
                area = (res[i].second - res[i].first - 1) * height[i];
                size = size < area ? area : size;
            }
        }
    }
    return size;
}

int main(void){
    vector<vector<int> > map = {{1, 0, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 0}, {1, 0, 1, 1}};
    int k = getBiggestSubarraySize(map);
    cout << k << endl;

    return 0;
}