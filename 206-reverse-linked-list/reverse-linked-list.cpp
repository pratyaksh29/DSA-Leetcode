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
    bool isPalindrome(ListNode* head) {
        // Edge case: if the list is empty or has only one node, it is a palindrome
        if (!head || !head->next) return true;

        // Step 1: Reverse the entire list
        ListNode* reversedHead = reverseList(head);

        // Step 2: Compare the original list with the reversed list
        ListNode* original = head;
        ListNode* reversed = reversedHead;
        while (original && reversed) {
            if (original->val != reversed->val) {
                return false;
            }
            original = original->next;
            reversed = reversed->next;
        }
        
        return true;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};
