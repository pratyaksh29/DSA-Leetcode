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
    ListNode* makelist(vector<int>arr){
        if(arr.empty()){
            return NULL;
        }
        int n = arr.size();
        ListNode* node = new ListNode(arr[0]);
        ListNode* temp = node;
        for(int i =1;i<n;i++){
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return node;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        vector<int>arr;
        for(int i =0;i<n;i++){
            ListNode* temp = lists[i];
            while(temp!=NULL){
                arr.push_back(temp->val);
                temp=temp->next;
            }
        }
        sort(arr.begin(),arr.end());
        ListNode* ans = makelist(arr);
        return ans;
        
    }
};