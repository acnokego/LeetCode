/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
/*
 * Complexity: O(n)
 * Space: O(n)
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<int, RandomListNode*>random_link;
        if(head == NULL) return NULL;
        RandomListNode* curr;
        RandomListNode* new_head;
        RandomListNode* next;
        RandomListNode* random;
        curr = new RandomListNode(head -> label);
        random_link.insert({head -> label, curr});
        new_head = curr;
        while(curr != NULL){
            if(head -> next){
                if(random_link.find(head -> next -> label) != random_link.end()){
                    next = random_link[head -> next -> label];
                }
                else{
                    next = new RandomListNode(head -> next -> label);
                    random_link.insert({head->next->label, next});
                }
                curr -> next = next;
            }
            if(head -> random){
                if(random_link.find(head -> random -> label) != random_link.end()){
                    random = random_link[head -> random -> label];
                }
                else{ 
                    random = new RandomListNode(head -> random -> label);
                    random_link.insert({head->random->label, random});
                }
                curr -> random = random;  
            }
            head = head -> next;
            curr = curr -> next;
        }
        return new_head;
    }
};
