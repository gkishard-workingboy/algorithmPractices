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
 *		有一个整数类型数组arr和一个大小为w的窗口从数组的最左边滑到最右边，窗口每次向右边滑一个位置。
 *      如果数组长度为n，窗口大小为w，则一共产生n-w+1个窗口的最大值。
 *      请实现一个函数： 输入整型数组arr与窗口大小w     输出一个长度为n-w+1的数组res，res[i]表示每一种窗口下的最大值。
**/

void genMaxWindowArray(vector<int>& arr, int w, vector<int>& res){
    deque<int> dq;
    int n = arr.size();
    for (int i = 0; i < n; ++i){
        while (!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();
        dq.push_back(i);
        if (dq.front() <= (i - w))
            dq.pop_front();
        if (i >= (w - 1))
            res.push_back(arr[dq.front()]);
    }
}

int main(void){
    vector<int> test = {4, 3, 5, 4, 3, 3, 6, 7};
    vector<int> res;
    genMaxWindowArray(test, 3, res);
    for (auto& i : res)
        printf("%d,", i);

    return 0;
}
