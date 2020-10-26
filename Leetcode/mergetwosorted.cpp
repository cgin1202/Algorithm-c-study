#include <malloc.h>

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        vector<int> answer;
        
        while(1){
            if(l1==nullptr && l2==nullptr)
                break;
            
            if(l1==nullptr){
                answer.push_back(l2->val);
                l2=l2->next;
            }
            else if(l2==nullptr){
                answer.push_back(l1->val);
                l1=l1->next;
            }else{
                
                if(l1->val<l2->val){
                    answer.push_back(l1->val);
                    l1=l1->next;
                }else{
                    answer.push_back(l2->val);
                    l2=l2->next;
                }
            }
        }
        
        int size=answer.size();
        ListNode* root=new ListNode(-1);
        ListNode* r=root;
        
        for(int i=0; i<answer.size(); i++){
            r->next=new ListNode(answer[i]);
            r=r->next;
        }
        
        return root->next;
    }
};