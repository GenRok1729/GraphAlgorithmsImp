ListNode* reverseList(ListNode* head) {
        
        ListNode *p,*q;
        
        if(head == NULL)
            return NULL;
        
        p = head;
        q = head-> next;
        
        if(q == NULL)
            return p;
        
        q = reverseList(q);
        
        
        p->next->next = p;
        p -> next = NULL;
        
        
        return q;
        
        
        
        
    }
    
