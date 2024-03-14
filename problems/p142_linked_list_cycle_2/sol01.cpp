/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        do {
            if (!fast || !fast->next) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
        } while(fast != slow);
        
        fast = head;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

int main()
{
    Solution s;
    {
        ListNode nodes[4] = {{3}, {2}, {0}, {-4}};
        nodes[0].next = &nodes[1];
        nodes[1].next = &nodes[2];
        nodes[2].next = &nodes[3];
        nodes[3].next = &nodes[1];
        ListNode* p = s.detectCycle(&nodes[0]);
        printf("the start point is %d\n", p == nullptr ? -1 : p->val);
    }
    return 0;
}