/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
 * Complexity: O(n*lg(k))
 * Space: O(k)
 */
class Solution {
public:
    static bool cmp (pair<int, int> p1, pair<int, int>p2){
        return p1.first > p2.first;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp) >min_heap(&cmp);
        for(int i = 0; i < lists.size(); ++i){
            if(lists[i]){
                min_heap.push(make_pair(lists[i] -> val, i));
                lists[i] = lists[i] -> next;
            }
        }
        ListNode* prev = NULL;
        while(min_heap.size()){
            pair<int, int> min = min_heap.top();
            ListNode* n = new ListNode(min.first);
            if(!head){
                head = n;
                prev = n;
            }
            else{
                prev -> next = n;
                prev = n;
            }
            min_heap.pop();           
            if(lists[min.second] != NULL){
                min_heap.push(make_pair(lists[min.second] -> val, min.second));
                lists[min.second] = lists[min.second] -> next;
            }
        }
        return head;
    }
};
