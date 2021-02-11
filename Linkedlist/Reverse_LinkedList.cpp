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


==================================================================================================================================================================
        
ListNode* reverseList(ListNode* head) {
     
        
        ListNode* p = NULL;
        ListNode* q = head;
        
        while(q != NULL)
        {
            ListNode* temp = q->next;
            q->next = p;
            p = q;//for next onr this is the previous node 
            q = temp;//This is the new node 
            
        }
        
        return p;//At lat this will be in the last node as its q willl be NULL
        
        
    }

=================================================================================================================================================================
    
