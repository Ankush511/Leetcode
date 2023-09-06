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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int cnt = 0;

        while(curr){
            curr = curr->next;
            cnt++;
        }

        int size = cnt / k;
        int extra = cnt % k;

        vector<ListNode*> result(k, NULL);
        curr = head;
        ListNode* prev = NULL;

        for(int i=0; i<k; i++){
            result[i] = curr;

            for(int j=0; j<size + (extra > 0? 1 : 0); j++){
                prev = curr;
                curr = curr->next;
            }

            if(prev != NULL){
                prev->next = NULL;
            } 
            extra--;
        }

        return result;
    }
};