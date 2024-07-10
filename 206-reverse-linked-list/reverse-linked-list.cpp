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
    ListNode* reverseList(ListNode* head) {
        ListNode* prevnode = NULL;
        while(head){
            ListNode* nextnode = head->next;
            head->next = prevnode;
            prevnode = head;
            head = nextnode;
        }
        return prevnode;
        
    }
};