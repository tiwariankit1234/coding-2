class Node{
    public:
    int val;
    Node* next=NULL;
    Node* prev=NULL;
       Node(int val, Node* next = NULL, Node* prev = NULL)
        : val(val), next(next), prev(prev) {}
};



class MyCircularDeque {
  int size;
  int capacity;
  Node* head;
  Node* rear;

public:


    MyCircularDeque(int k) {
        head=NULL;
        rear=NULL;

       size=0;
       capacity=k;
    }
    
    bool insertFront(int value) {
       
         if(size<capacity){
            if(head==NULL){
               head=new Node(value);
                rear=head;
                size++;
                return true;
            }

            else if(head!=NULL){
        Node *curr=new Node(value);
        curr->next=head;
        head->prev=curr;
    
        head=curr;
        size++;
          return true;
            }
         }

         return false;
       
    
    }
    
    bool insertLast(int value) {
        
         if(isFull())return false;

            if(head==NULL){
                head=new Node(value);
                rear=head;
             
        
            }
            else{
         Node *newNode=new Node(value);
         rear->next=newNode;
         newNode->prev=rear;
        //  newNode->next=NULL;
        
         rear=newNode;
       
         
          }
        
          size++;
    return true;
    }
    
    
    bool deleteFront() {
        if(size==1){
        head=NULL;
        rear=NULL;
        size--;
        return true;
    }
    else if(size>1){
         head=head->next;
         head->prev=NULL;
          size--;
          return true;
    }
    return false;
    }

    bool deleteLast() {
        if(size==1){
         head=NULL;
         rear=NULL;
         size--;
         return true;
        }
        else if(size>=1){
          rear=rear->prev;
          rear->next=NULL;
          size--;
           return true;
       }

         return false;
        }
       
    
    
    int getFront() {
         cout<<"1"<<endl;
        if(size>=1){
        return head->val;
        }
        else
        return -1;
    }
    
    int getRear() {
        if(size>=1){
        return rear->val;
        }
        else
        return -1;
    }
    
    bool isEmpty() {
        if(size>=1)
        return false;
        else
        return true;

    }
    
    bool isFull() {
        if(size==capacity)
        return true;
        else{
            return false;
        }
    }
};


/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(capacity);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */