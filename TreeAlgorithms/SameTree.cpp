bool isSameTree(TreeNode* root1, TreeNode* root2) {
        
        if(root1 == NULL and root2 == NULL)
            return true;
        if(root1 && root2 && root1->val == root2->val)
        {
            return isSameTree(root1->left,root2->left) && isSameTree(root1->right,root2->right);
        }
        
        return false;
    }
    
    
Time complexity : O(N), where N is a number of nodes in the tree, since one visits each node exactly once.
Space complexit : O(log(N)) in the best case of completely balanced tree , O(N) in the worst case of completely unbalanced tree, to keep a recursion stack.
