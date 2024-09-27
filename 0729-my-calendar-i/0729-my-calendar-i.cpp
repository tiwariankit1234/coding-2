class MyCalendar {
public:
 vector<pair<int,int>>arr;
 int idx=0;

    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        //check for each interval
       
       
        //   cout<<k<<" "<<idx<<endl;
       
        for(int j=0;j<arr.size();j++){
         
            int s1=arr[j].first;
            int e1=arr[j].second;
            int s2=start;
            int e2=end;
            // cout<<s1<<" "<<e1<<" "<<s2<<" "<<e2<<" "<<endl;
            if((e2<=s1 || e1<=s2)){
              
            }
            else{
                //  cout<<s1<<" "<<e1<<" "<<s2<<" "<<e2<<" "<<endl;
                return false;
            }
        }
     
      arr.push_back({start,end});
       return true;


        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */