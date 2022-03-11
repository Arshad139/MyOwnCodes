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
Node * uniqueSortedList(Node * head) {
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
