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
    struct compare{
    bool operator()(const ListNode* a,ListNode* b){
        return a->val>b->val;
    }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        for(int i =0;i<lists.size();i++) if(lists[i]!=NULL){ pq.push(lists[i]);}
        if(pq.empty()) return NULL;
        ListNode* ans(pq.top());
        if(pq.top()->next) pq.push(pq.top()->next);
        pq.pop();
        ListNode* head=ans;
        while(!pq.empty()){
            ListNode* current = pq.top();
            pq.pop();
            ans->next = current;
            //cout<<ans->val;
            ans=ans->next;
            if(current->next) pq.push(current->next);
        }
        ans->next=NULL;
        return head;
        
        
    }
};
