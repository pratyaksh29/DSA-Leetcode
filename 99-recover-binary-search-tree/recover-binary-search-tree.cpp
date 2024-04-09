class Solution {
private:
    TreeNode* first; // use this as temp
    TreeNode* last;
    TreeNode* prev;
    TreeNode* middle;

    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        inorder(root->left);

        if (prev != NULL && root->val < prev->val) { //MIDDLE PART IN INORDER TRAVERSAL
            if (first == NULL) { //if it is the first violation
                first = prev;
                middle = root;
            } else { //if it is the second violation
                last = root;
            }
        }
        prev = root; //make prev equal to root because u r gonna go to the next branch

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {

        inorder(root);

        if (first && last) {
            swap(first->val, last->val);
        } else if (first && middle) {
            swap(first->val, middle->val);
        }
    }
};
