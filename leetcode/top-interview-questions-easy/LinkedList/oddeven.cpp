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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd, *even, *odd_head, *even_head;
        if(head == NULL || head->next == NULL || head->next->next == NULL)  return head;
        odd = odd_head = head;
        even = even_head = head->next;
        odd->next = even->next;
        odd = odd->next;
        int i=0;
        while(odd->next!=NULL)    {
            cout<<"hey";
            cout<<odd->val<<" "<<even->val;
            even->next = odd->next;
            even = even->next;
            odd->next = even->next;
            if(odd->next)   odd = odd->next;
            else break;
        }
        cout<<"lol";
        odd->next = even_head;
        even->next = NULL;
        return odd_head;
    }
};
