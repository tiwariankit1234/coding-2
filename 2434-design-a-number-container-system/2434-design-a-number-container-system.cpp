class NumberContainers {
public:
unordered_map<int,int>mp;
unordered_map<int,set<int>>smallestidx;
    NumberContainers() {
        
    }
    
    void change(int idx, int number) {
        // pehla case us index par number already hain
        if(mp.find(idx)!=mp.end()){
            int num=mp[idx];
           
            smallestidx[num].erase(idx);
            if(smallestidx[num].empty())
            smallestidx.erase(num);

              mp[idx]=number;
              smallestidx[number].insert(idx);
            //   cout<<num<<" "<<idx<<" "<<number<<endl;
            //   cout<<" true"<<endl;
              return ;
        }
        else{
            mp[idx]=number;
            smallestidx[number].insert(idx);
        }
        // for(auto it:mp)
        // cout<<it.first<<" "<<it.second<<" ";
          
        //   cout<<endl;
        // for(auto it:smallestidx){
        //     cout<<it.first<<" ";
        //     auto pq=it.second;
        //     for(auto k:pq){
        //         cout<<k<<" ";
        //     }
        // }

        // cout<<endl;
        
    }
    
    int find(int number) {
        if(smallestidx.find(number)==smallestidx.end())
        return -1;
        else{
      
        return *(smallestidx[number].begin());
        }
        // auto it=smallestidx[number];
        // return *(it.begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */