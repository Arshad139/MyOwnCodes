Class Solution{
  private:
   void/Node* insertAtTail(Node* &head,Node* &tail,int val){
        Node* temp=new Node(val);
        if(head==NULL){
            head=temp;
            tail=temp;
          //  return tail;
        }
        else{
            tail->next=temp;
            tail=temp;
          //  return tail;
        }
    }
public:
    Node *copyList(Node *head)
    {
        Node* ansHead=NULL;
        Node* ansTail=NULL;
        Node* temp=head;
      //1. Insert nodes in the ans Linked list using & depending just on the next pointer.
         while(temp!=NULL){
             insertAtTail(ansHead, ansTail, temp->data);
             temp=temp->next;
             //c++;
         }
      //2. Creating a hash table using unordered map to create a mapping from original linked list to ans Linked List.
         temp=head;
         Node* temp1=ansHead;
         unordered_map<Node*,Node*> hash;
         while(temp1!=NULL && temp!=NULL){
             hash[temp]=temp1;
              temp=temp->next;
             temp1=temp1->next;
             
         }
      //3. Traverse again and see if original node's arb pointer has a non NULL value and if yes, point the arb pointer of the ansLL to the hash value for the orignial node's arb pointed node.
         temp=head;
         temp1=ansHead;
         while(temp1!=NULL && temp!=NULL){
             if(temp->arb!=NULL) temp1->arb=hash[temp->arb];
             temp=temp->next;
             temp1=temp1->next;
         }
         return ansHead;
         
    }
   Node* WithoutHashmap(Node* head){
   
   }
  
};
