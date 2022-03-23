/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/
#include<unordered_set>
Node * del_At_Pos(Node* &head, int pos)
{
   
    Node* curr=head;
    Node* prev=NULL;
    int cnt=1;
    while(cnt<pos){
        prev=curr;
        curr=curr->next;
        cnt++;
    }
    prev->next=curr->next;
  //  cout<<"deleted at pos-"<<cnt<<"  ";
    return head;
}
Node * uniqueUnSortedList(Node * head) {
    // Write your code here.
    if(head==NULL || head->next==NULL) return head;
    Node* temp=head;int pos=0;
    unordered_set<int> s;
    cout<<endl;
    while(temp!=NULL){
        pos++;
        if (s.count(temp->data)) {
           // cout<<pos<<"   ";
            head=del_At_Pos(head,pos);
            pos--;
        }
        else  {
        s.emplace(temp->data);//cout<<"element retained at  "<<pos;
        }
        temp=temp->next;
        //cout<<"     NextElementData"<<temp->data<<endl;
    }
    
    //cout<<endl<<"pos="<<pos<<endl;
    return head;
}
//--------The above first approach solved 90 percent of the test cases--------------------------------------

//--------Trying an optimised approach for the above first approach.
Node *removeDuplicates(Node *head)
{
       if(head==NULL || head->next==NULL) return head;
    Node* temp=head;
    Node* prev=NULL;
    unordered_set<int> s
    
    while(temp!=NULL){
       
        if (s.count(temp->data)) prev->next=temp->next;
       
        else  {
        s.emplace(temp->data);
        prev=temp;
        }
        
       temp=temp->next;
    }
    
    return head;
}
//--------The following is the approach for sorted linked list to remove the duplicates

Node * uniqueSortedList(Node * head) {
   if (head==NULL) return head;
    
   Node* curr=head;
   while(){
        if(curr->data==curr->next->data){
            Node* dup=curr->next;
            curr->next=curr->next->next;
            delete dup;
        }
       else curr=curr->next;
   }
    return head;
}

