class LRUCache {
public:
  int cap=0;
  list<pair<int,int>>dl;
  unordered_map<int,list<pair<int,int>>::iterator>mp;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        auto it=mp[key];
        int x=it->second;
        dl.push_front({key,x});
        dl.erase(it);
        mp[key]=dl.begin();
        return x;
    }
    
    void put(int key, int value) {
        
       if(mp.find(key)!=mp.end()){
         auto it=mp[key];
        dl.erase(it);
       }
       else if((int)mp.size()==cap){
         auto it=prev(dl.end());
         mp.erase(it->first);
         dl.erase(it);
       }
        dl.push_front({key,value});
        mp[key]=dl.begin();
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */