class MyCalendar {
public:

   set<pair<int,int>>s;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int,int>newEvent={start,end};

        auto nextevent=s.lower_bound(newEvent);
        if(nextevent!=s.end() and nextevent->first<end)
        return false;
         
         if(nextevent!=s.begin()){
            auto prevEvent=prev(nextevent);
             
            if(prevEvent->second>start)
            return false;

         }

        s.insert(newEvent);

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */