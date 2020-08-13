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
 * @date 2020-08-1 
 * @description
 *     打印两个有序链表的头指针head1和head2，打印两个链表的公共部分
 **/

class Node
{
public:
    int val;
    Node* next;  
    Node():val(0),next(nullptr){}
    Node(int v,Node* n):val(v),next(n){};
};

void printCommonPart(Node* a,Node* b){
    if (a==nullptr || b==nullptr)
        return;
    if (a->val > b->val)
        printCommonPart(a, b->next);
    else if (a->val < b->val)
        printCommonPart(a->next, b);
    else{
        printf(" %d", a->val);
        printCommonPart(a->next, b->next);
    }
}


int main(void){
    Node *first = new Node(0, nullptr), *second = new Node(0, nullptr);
    Node *f = first, *s = second;
    for (int i = 1; i <= 10; ++i){
        if (!(i & 1)){
            s->next = new Node(i, nullptr);
            s = s->next;
        }
        f->next = new Node(i, nullptr);
        f = f->next;
    }
    printCommonPart(first, second);
    return 0;
}