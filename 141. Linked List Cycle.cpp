/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Approach - 1

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;

        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};


// Approach - 2

class Solution {
public:
    bool hasCycle(ListNode *head) {

        unordered_map<ListNode*, bool> table;
        ListNode* temp = head;

        while (temp!=NULL){
            // check if temp already exists in hashtable
            if(table.count(temp) != 0){
                return true;
            }
            // insert the hashtable
            table[temp] = true;
            temp = temp->next;
        }
        return false;
    }
};

