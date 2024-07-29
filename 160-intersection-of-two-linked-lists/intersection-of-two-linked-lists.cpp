/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getDifference(ListNode *head1,ListNode *head2) {
        int len1 = 0,len2 = 0;
            while(head1 != NULL || head2 != NULL) {
                if(head1 != NULL) {
                    len1++; head1 = head1->next;
                }
                if(head2 != NULL) {
                    len2++; head2 = head2->next;
                }
                
            }
            return len1-len2;//if difference is neg-> length of list2 > length of list1 else vice-versa
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int diff = getDifference(headA,headB);
        if(diff < 0){
            swap(headA,headB);//now headA is bigger
            diff = abs(diff);
        }
        while(diff--){
            headA=headA->next;
        }
        while(headA && headB){
            if(headA==headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;

    
    }
};