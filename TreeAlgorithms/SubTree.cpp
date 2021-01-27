int  count = 0;
    bool isSameTree(TreeNode* root1,TreeNode* root2)
    {
               if(root1 == NULL and root2 == NULL)
                        return true;
        
        if(root1 && root2 && root1->val == root2->val)
        {
            count++;
            return isSameTree(root1->left,root2->left) && isSameTree(root1->right,root2->right);
        }
        
        return false;
        
    }
    
    
    //Vague Wriring of code should think much more 
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        //You missed of base conditions so pity of u mc
        if(s == NULL)
            return false;
        if(t == NULL)
            return true;
        
        count = 0;
        if(isSameTree(s,t))
        {
            cout << count << '\n';
            return true;
        }
        
        
        return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
