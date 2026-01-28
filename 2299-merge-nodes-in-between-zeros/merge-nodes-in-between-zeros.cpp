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
    ListNode* mergeNodes(ListNode* head) {
        if(!head)  return nullptr;
        ListNode* slow=head, *fast=head->next, *temp=nullptr;
        int sum = 0;
        while(fast){
            if(fast->val != 0) sum += fast->val;
            else{
                slow->val = sum;
                temp = slow;
                slow = slow->next;
                sum = 0;
            }
            fast = fast->next;
        } 
        temp->next = nullptr;

        ListNode* lastNode = slow;
        while(lastNode){
            ListNode* nxt = lastNode->next;
            delete lastNode;
            lastNode = nxt;
        }
        return head;
    }
};