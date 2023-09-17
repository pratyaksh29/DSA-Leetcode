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
    int count = 0;
    unordered_map<long,long>mp; //sum,count

    void pathcalc(TreeNode* root, int targetSum, long runningSum){ 
        if(root==NULL){
            return;
        }
        runningSum += root->val;
        if(runningSum==targetSum){
            count++;
        }
        if(mp.find(runningSum-targetSum)!=mp.end()){
            count+=mp[runningSum-targetSum]; //got stuck here
        }
        mp[runningSum]++;
        pathcalc(root->right,targetSum,runningSum);
        pathcalc(root->left,targetSum,runningSum);
        mp[runningSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        pathcalc(root,targetSum,0);
        return count;
    }
};