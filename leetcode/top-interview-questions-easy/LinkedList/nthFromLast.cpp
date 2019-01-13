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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i=0;
        ListNode *node = head;
        while(node!=NULL)   {
            i++;
            node = node->next;
        }
        int x = i - n;
        node = head;
        if(x == 0)  {
            head = head->next;
            return head;
        }
        for(int j = 0; j < i; j++)  {
            if(j + 1 == x)  {
                node->next = node->next->next;
                break;
            }
            node = node->next;
        }
        return head;
    }
};
