class LFUCache {
public:
int capacity,minfreq;
unordered_map<int,pair<int,int>>keytovalue; //key val freq
unordered_map<int,list<int>>freqtokey;
unordered_map<int,list<int>::iterator>keytoiter;
    LFUCache(int capacity) {
        this->capacity=capacity;
        minfreq=0;
    }
    
    int get(int key) {
        if(keytovalue.find(key)==keytovalue.end())return -1;
        // uske corresponding key aur value nikalenge
        auto [val,freq]=keytovalue[key];
        auto it=keytoiter[key];
        freqtokey[freq].erase(it);
        keytovalue.erase(key);
        if(freqtokey[freq].size()==0){
            freqtokey.erase(freq);
            if(minfreq==freq){
                minfreq++;
            }
           
        }
        freqtokey[freq+1].push_front(key);
        keytoiter[key]=freqtokey[freq+1].begin();
        keytovalue[key]={val,freq+1};
        return val;
    }
    
    void put(int key, int value) {
        if(capacity==0)return ;
        if(keytovalue.find(key)!=keytovalue.end()){
            keytovalue[key].first=value;
             get(key);
             return ;
        }
        if(keytovalue.size()==capacity){
             int keytoremove=freqtokey[minfreq].back();
             freqtokey[minfreq].pop_back();
             if(freqtokey[minfreq].size()==0)freqtokey.erase(minfreq);
             keytoiter.erase(keytoremove);
             keytovalue.erase(keytoremove);
        }
        keytovalue[key]={value,1};
        freqtokey[1].push_front(key);
        keytoiter[key]=freqtokey[1].begin();

        minfreq=1;
        return ;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */