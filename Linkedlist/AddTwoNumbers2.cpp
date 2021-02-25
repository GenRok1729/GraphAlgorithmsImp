/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverselist(ListNode* head) {
       
        
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* p = reverselist(head->next); //3 //head is 4
        head->next->next = head;
        head -> next = NULL;
        
        return p; //3 //head is 2//https://www.youtube.com/watch?v=MRe3UsRadKw
        
    }
    
    ListNode* addTwoNumbers(ListNode* ln1, ListNode* ln2) {
        
        ListNode* l1 = reverselist(ln1);
        ListNode* l2 = reverselist(ln2);
        
    ListNode preHead(0), *p = &preHead;//To CREATE dUMMY POINTER FOR OUR PURPOSE 
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
        
    return reverselist(preHead.next);
        
        
    }
};
