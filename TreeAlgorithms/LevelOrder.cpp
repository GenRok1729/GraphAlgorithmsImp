
       if(root == NULL)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
                TreeNode* z = q.front();
                q.pop();
                if(z->left)
                    q.push(z->left);
                if(z->right)
                    q.push(z->right);
            
        }
        


//Simple level Order 

==================================================================================================================================================================

Level Order Traversal Printing each level seperately 

void lot(TreeNode* root,vector<int> &rsv) {
        
        if(root == NULL)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            
            for(int i = 0;i < s;i++)
            {
                TreeNode* z = q.front();
                q.pop();
                if(i == s-1)
                    rsv.push_back(z->val);
                if(z->left)
                    q.push(z->left);
                if(z->right)
                    q.push(z->right);
            }
        }
        
    }
=================================================================================================================================================================
