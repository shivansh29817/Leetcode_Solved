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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(nums.size() == 0 || !head) return head;
        unordered_set<int> st(nums.begin(),nums.end());
        ListNode* newHead = NULL;
        ListNode* t = head;
        ListNode* t2 = NULL;
        while(t){
            if(!st.contains(t->val)){
                ListNode* dummy = new ListNode(t->val);
                if(newHead == NULL){
                    newHead = dummy;
                    t2 = dummy;
                }else{
                    t2->next = dummy;
                    t2 = t2->next;

                }
                
            }
            t = t->next;

        }
        return newHead;
    }
};