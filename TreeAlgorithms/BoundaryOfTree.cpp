/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: a TreeNode
     * @return: a list of integer
     */
     
     vector<int> v;
     
     
     void printbl(TreeNode* root)
     {
         if(root == NULL)
            return;
        if(root->left)
        {
            v.push_back(root->val);
            printbl(root->left);
        }
        if(root -> right)
        {
            
            v.push_back(root->val);
            printbl(root->right);
        }
        //Doing Nothing when we have reached leaf node like this
     }
     
     void printleaves(TreeNode* root)
     {
         if(root == NULL)
            return;
        
        printleaves(root->left);
        
        if((!(root->left)) && (!(root->right)))
        {
            v.push_back(root->val);
        }
        
        printleaves(root->right);
     }
     
     void printBR(TreeNode* root) 
    { 
        if (root == NULL) 
            return; 
      
        if (root->right) { 
            printBR(root->right); 
            v.push_back(root->val); 
        } 
        
        else if (root->left) { 
            printBR(root->left); 
            v.push_back(root->val); 
        } 
        // do nothing if it is a leaf node, this way we avoid 
        // duplicates in output 
    }
     
     
     void boundaryOfBinary(TreeNode* root)
     {
         if(root  == NULL)
            return;
         
         
         v.push_back(root->val);
         printbl(root->left);
         
         printleaves(root->left);
         printleaves(root->right);
         
         printBR(root->right);
         
         
     }
     
     
    vector<int> boundaryOfBinaryTree(TreeNode * root) {
        // write your code here
        v.clear();
        
        boundaryOfBinary(root);
        
        return v;
    }
};
