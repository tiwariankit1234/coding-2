/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // create node between it 
     Node *temp=head;
     while(temp){
        Node* nextNode=temp->next;
        Node* copyNode=new Node(temp->val);
        temp->next=copyNode;
        copyNode->next=nextNode;
        temp=temp->next->next;
     }

     temp=head;

     while(temp){
        Node *nextNode=temp->next;
        Node *randomNode=temp->random;
        if(nextNode and randomNode)
        nextNode->random=randomNode->next;
        temp=temp->next->next;
     }

     temp=head;

     // connect dummyNode and node next 

     Node *dummyNode=new Node(-1);
     Node *copy=dummyNode;

     while(temp){
        copy->next=temp->next;
        temp->next=temp->next->next;
        copy=copy->next;
        temp=temp->next;
        
     }
      return dummyNode->next;
    

    }
};