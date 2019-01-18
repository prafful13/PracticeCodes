/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0,d;
        ListNode *ans = l1, *prev, *e = l2;
        while(l1!=NULL || l2!=NULL) {
            if(l1!=NULL && l2!=NULL) {
                d = c + l1->val + l2->val;
                c = d/10;
                d %= 10;
                l1->val = d;
                prev = l1;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1!=NULL)   {
                d = c + l1->val;
                c = d/10;
                d %= 10;
                cout<<d;
                l1->val = d;
                prev = l1;
                l1 = l1->next;
            }
            else    {
                prev->next = l2;
                l1 = l2;
                l2 = NULL;
            }
        }
        if(c!=0)    {
            prev->next = e;
            e->val = c;
            e->next = NULL;
        }
        return ans;
    }
};
