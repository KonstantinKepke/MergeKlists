// Merge k sorted list.cpp 
//
//You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//
//Merge all the linked - lists into one sorted linked - list and return it.

#include <iostream>
#include <vector>
#include <set>


using namespace std;
// specified list structure
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// for initialize input lists
ListNode* addlistnodefront(ListNode* list, int a) {
    ListNode* head = new ListNode;
    head->val = a;
    head->next = list;
    return head;
}

// for debug
void PrintList(ListNode* l) {
    if (l == NULL) {
        cout << "NUll List" << endl;
        return;
    }
    while (l->next != NULL) {
        cout << " i = " << l->val;
        l = l->next;
    }
    cout << " i = " << l->val << endl;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = NULL;
        ListNode* tmp = NULL;
        multiset<int> rList;
        if (lists.size() == 0) return NULL;
        for (auto it = lists.begin(); it < lists.end(); it++) {
            if (res != NULL) {
                while (res->next != NULL) {
                    rList.insert(res->val);
                    res = res->next;
                }
                rList.insert(res->val);
                res = it[i];
            }
        }
        if (rList.size()==0)return NULL;

        res = new ListNode;
        tmp = res;
        ListNode* pred = res;
        for (auto item : rList)
        {
            tmp->val = item;
            tmp->next = new ListNode;
            pred = tmp;
            tmp = tmp->next;
        }
        delete tmp;
        pred->next = NULL;
        PrintList(res);
        return res;
    }
};

int main()
{
    vector<ListNode*> lists;// = { {1, 2, 3,4}, {1, 2, 4} };
    
    ListNode* l= NULL; 
    ListNode* l2 = NULL;
    ListNode* l3 = NULL;
    ListNode* ptrL;
    
    int arr[4] = {1, 4, 8, 12};
    // 
    for (int i = 0; i <= 3; i++) {
        l = addlistnodefront(l, arr[3 - i]);
    //    l2 = addlistnodefront(l2, arr[3 - i] + 1);
    //    l3 = addlistnodefront(l3, arr[3 - i] + 2);
    }
    //PrintList(l);
    //PrintList(l2);
    //PrintList(l3);
    //
    //lists.push_back(l);
    //lists.push_back(l2);
    //lists.push_back(l3);

    //int arr = {1, 4, 8, 12};
    //l = addlistnodefront(l, arr[3 - i]);
    //    l2 = addlistnodefront(l2, arr[3 - i] + 1);
    //    l3 = addlistnodefront(l3, arr[3 - i] + 2);
    //}
    //PrintList(l);
    //PrintList(l2);
    //PrintList(l3);
    //
    lists.push_back(l);
    lists.push_back(NULL);
    //lists.push_back(l2);
    //lists.push_back(l3);

    Solution S;

    ptrL = S.mergeKLists(lists);
    PrintList(ptrL);

    std::cout << "End!\n";
}
