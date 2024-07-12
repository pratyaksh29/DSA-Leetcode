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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* leftprev = temp;
        ListNode* currnode = head;
        for(int i=0;i<left-1;i++){
            leftprev = currnode;
            currnode = currnode->next;
        }

        int index = right-left+1;
        ListNode* prev = NULL;
        while(index--){
            ListNode* next = currnode->next;
            currnode->next = prev;
            prev = currnode;
            currnode = next;
        }
        leftprev->next->next = currnode;
        leftprev->next = prev;



        return temp->next;
        
    }
};