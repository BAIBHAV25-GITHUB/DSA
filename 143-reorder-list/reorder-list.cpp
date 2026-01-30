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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while(second){
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        ListNode* firstHead = head;
        ListNode* secondHead = prev;
        while (secondHead) {
            ListNode* temp1 = firstHead->next;
            ListNode* temp2 = secondHead->next;
            firstHead->next = secondHead;
            secondHead->next = temp1;
            firstHead = temp1;
            secondHead = temp2;
        }
    }
};