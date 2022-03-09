/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };



/*
Node *removeTheLoop(Node* head){
    //find and then remove 
    cout<<"EnteredCRemovethekLoop"<<endl;
   Node* slow=head;Node* fast=head;
    while(slow!=fast){
        fast=fast->next;
        if(fast->next!=NULL) fast=fast->next;
        slow=slow->next;
    }
    cout<<"End of first loop in RemovethekLoop"<<endl;
    slow=head;
    while(slow!=fast){
        slow=slow->next;fast=fast->next;
    }
     cout<<"End of II loop in RemovethekLoop"<<endl;
    Node* intersect=slow;Node* temp=slow;
    while(temp->next !=intersect) temp=temp->next;
    temp->next=NULL;
     cout<<"End of Last loop in RemovethekLoop"<<endl;
    return head;
}
*************************************************/
Node* findFloyedLoop(Node *head){
    if(head==NULL) return NULL;
    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL) fast=fast->next;
        slow=slow->next;
        if(slow==fast) return slow;
    }
    return NULL;
}
bool checkLoop(Node* head){
    //cout<<"EnteredCheckLoop"<<endl;
    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL && fast!=NULL){
        if(slow=fast) return true;
        fast=fast->next;
        if(fast!=NULL) fast=fast->next;
        slow=slow->next;
    }
    //cout<<"ExitedCheckLoop";
    return false;
}
Node* StartOfLoop(Node *head){
  if(head==NULL) return NULL;
  Node* intersect=findFloyedLoop(head);
  if(intersect==NULL) return NULL;
  Node* slow=head;
  while(slow!=intersect){
      slow=slow->next;
      intersect=intersect->next;
  }
    return slow;
}
Node *removeLoop(Node *head)
{
    // Write your code here.1. check if loop is there->find and remove
   if(head==NULL) return NULL;
    
   if(!checkLoop(head)){return head;}
   else { Node* inter=StartOfLoop(head);
    if(inter==NULL) return head;
    
    Node* temp=inter;
    while(temp->next !=inter) temp=temp->next;
    temp->next=NULL;
    
    return head;
     } 
}
