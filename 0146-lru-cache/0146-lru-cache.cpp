class Node{
    public:
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        prev=NULL;
        next=NULL;
    }
};

class LRUCache {
public:
unordered_map<int,Node*>mp;
int capacity;
Node *head;
Node *tail;

void *addnode(Node* newnode){
         Node *temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
       temp->prev=newnode;
    return newnode;

}
void deletenode(Node *deletenode){
    Node *prev=deletenode->prev;
    Node *next=deletenode->next;
    prev->next=next;
    next->prev=prev;
}
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        //     auto it=mp[key];
        //    int x=it->val;
        //    mp.erase(key);
        //    deletenode(it);
        //    Node *temp=addnode(it);
        //     mp[key]=temp;
        Node *node=mp[key];
        int val=node->val;
        deletenode(node);
        addnode(node);
        mp[key]=head->next;
           return val;
        
            }
    
    void put(int key, int val) {
            if(mp.find(key)!=mp.end()){
                 auto it=mp[key]; 
                 mp.erase(key); 
                 deletenode(it);
            }


         if((int)mp.size()==capacity){
            Node *vec=tail->prev;
            mp.erase(vec->key);
            deletenode(vec);
         }
            // if(mp.find(key)!=mp.end()){
            //      auto it=mp[key]; 
            //      mp.erase(key); 
            //      deletenode(it);
            // }
            Node *newNode=new Node(key,val);
            addnode(newNode);
            mp[key]=newNode;  
          return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */