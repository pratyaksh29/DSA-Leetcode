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
    void reverse(ListNode* temp){
        if(temp== NULL || temp->next==NULL) {
            return;
        }
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
    }


    ListNode* getknode(ListNode* temp, int k){
        while(temp!=NULL&& k--){
            temp=temp->next;
        }
        return temp;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
       
        while(temp!=NULL){
            ListNode* knode = getknode(temp,k-1);
            if(knode == NULL && prev!=NULL){
                prev->next = temp;
                break;
            }

            ListNode* next = knode->next;
            knode->next = NULL;
            reverse(temp);
            if(temp == head){ //this means it is your first kgroup
                head = knode;
            }
            else{
                prev->next = knode;
            }
            prev = temp;
            temp = next;
        }
        return head;

    }
};