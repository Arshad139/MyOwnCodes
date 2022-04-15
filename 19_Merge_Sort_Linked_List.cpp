/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };https://leetcode.com/problems/merge-two-sorted-lists/submissions/
 */
class Solution {
private:
    ListNode* Half(ListNode* head){ 
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast->next!=NULL) fast=fast->next;
             }
        return slow;
    }
    
     ListNode* solve(ListNode* &list1, ListNode* &list2){
        ListNode* curr1=list1;
        ListNode* next1=curr1->next;
        ListNode* curr2=list2;
        ListNode* next2=list2->next;
        
        while(next1!=NULL && curr2!=NULL){
           if( (curr2 -> val >= curr1 -> val ) 
           && ( curr2 -> val <= next1 -> val)){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
        }
        else{
            curr1=next1;
            next1=next1->next;
        }
        }
      
        if(next1==NULL) curr1->next=curr2;
        return list1;
    }
    
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        if(list1->val<=list2->val) return solve(list1,list2);
        else return solve(list2,list1);
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* first=head;
        ListNode* slow=Half(head);
        ListNode* second=slow->next;
        slow->next=NULL;
        
       first=sortList(first);
       second=sortList(second);
        
        return merge(first,second);
        
        
    }
};
