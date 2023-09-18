/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findposition (vector<int> inorder, int root,unordered_map<int,int>& nodetoindex){
        for(int i =0;i<inorder.size();i++){
            nodetoindex[inorder[i]]=i;
        }
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &preorderindex,int inorderstart,int inorderend,unordered_map<int,int>& nodetoindex){ 
    //send preorderindex by reference as it changes every iteration
        if(preorder.size()<preorderindex || inorderend<inorderstart){ //edge cases
            return NULL;
        }
        int root= preorder[preorderindex++]; //the first element of the preorder index will be the root so store it and go to the next index in every recursive call
        TreeNode* node = new TreeNode(root); //create a new node using the root
        findposition(inorder,root,nodetoindex);
        int position = nodetoindex[root];


        //all elements on the left of inorder array will be node->left and all elements on right will be node->right so we will recursively call
        node->left = solve(preorder,inorder,preorderindex,inorderstart,position-1,nodetoindex); //solving for left hand side
        node->right = solve(preorder,inorder,preorderindex,position+1,inorderend,nodetoindex); //solving for right hand side
        return node;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderindex =0; //initializing preorderindex 
        unordered_map<int,int>nodetoindex;
        TreeNode* ans = solve(preorder,inorder,preorderindex,0,preorder.size()-1,nodetoindex); 
        return ans;
        
    }
};

