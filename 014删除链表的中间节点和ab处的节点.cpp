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
 * @date 2020-08-13 
 * @description
 *     给定链表的头结点head，实现删除链表中间节点的函数
 *     进阶：给定链表头节点head、整数a和b，实现删除位于a/b处节点的函数。
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

//直接上进阶版
void removeNodeConcerningAB(Node *head, int a, int b){
    if (a == 0 || b == 0) return;
    int n = 0;
    for (Node *cur = head; cur != nullptr; cur = cur->next)
        n++;
    int r = ceil(n * 1.0 * a / b);
    int cnt = 2;
    for (Node *cur = head;; ++cnt, cur = cur->next)
        if (cnt == r){
            Node *temp = cur->next;
            cur->next = temp->next;
            free(temp);
            break;
        }
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
    Node* slist = new Node();
    Node* s = slist;
    for (int i = 1; i <= 10; ++i){
        s->next = new Node(i, nullptr);
        s = s->next;
    }
    printList(slist);
    removeNodeConcerningAB(slist, 3, 11);
    printList(slist);
    return 0;
}