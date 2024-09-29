class MyCalendarTwo {
public:
 vector<pair<int,int>>singlelist,doublelist;
    MyCalendarTwo() {
        
    }
       bool check(int start1,int end1,int start,int end){
        return (max(start,start1)<min(end1,end)); //  overlapping condition
    }
    
    bool book(int start, int end) {
     
     // check with double list 
     
       
            for(auto it:doublelist){
                int start1=it.first;
                int end1=it.second;
                if(check(start1,end1,start,end)){
                    return false;
                }
    }
    
    // check it forms any overlap region with single list
                for(auto it:singlelist){
                int start1=it.first;
                int end1=it.second;
                if(check(start1,end1,start,end)){
                    int x=max(start,start1);
                    int y=min(end,end1);
                    doublelist.push_back({x,y});
            
                }
            } 

            singlelist.push_back({start,end});
            return true;

    }  
              


};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */