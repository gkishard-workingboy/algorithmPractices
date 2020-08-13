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
 * @date 2020-08-12 
 * @description
 *     分别实现两个函数，一个可以删除单链表中倒数第K个节点，另一个可以删除双链表中倒数第K个节点。
 *     要求: 如果链表长度为N，时间复杂度达到O(N),额外空间复杂度达到O(1)
 **/

class Node
{
public:
    int val;
    Node* next;
    Node* prev;  
    Node():val(0), next(nullptr), prev(nullptr){}
    Node(int v,Node* n):val(v), next(n), prev(nullptr){};
    Node(int v,Node* n, Node* p):val(v), next(n), prev(p){};
};

int removeKthLastSingleList(Node* node, int k){
    if (node == nullptr) return 0;
    int count = removeKthLastSingleList(node->next, k);
    if (count == k){
        Node* temp = node->next;
        node->next = temp->next;
        free(temp);
    }
    return  count + 1;
}

void removeKthLastDoubleList(Node* node, int k){
    while (node->next != nullptr)
        node = node->next;
    for (int i = 0; i < k; ++i){
        node = node->prev;
    }
    Node* temp = node->next;
    node->next = temp->next;
    node->next->prev = node;
    free(temp);
    return;
}

void printList(Node* node){
    if (node == nullptr) {
        cout << endl;    
        return;
    }
    cout << node->val << " ";
    printList(node->next);
}

int main(void){
    Node* slist = new Node(), *dlist = new Node();
    Node* s = slist, *d = dlist;
    for (int i = 1; i <= 10; ++i){
        s->next = new Node(i, nullptr);
        s = s->next;
        d->next = new Node(i, nullptr, d);
        d = d->next;
    }
    printList(slist);
    removeKthLastSingleList(slist, 5);
    printList(slist);
    cout << "---------------------------------------------------" << endl;
    printList(dlist);
    removeKthLastDoubleList(dlist, 5);
    printList(dlist);

    return 0;
}