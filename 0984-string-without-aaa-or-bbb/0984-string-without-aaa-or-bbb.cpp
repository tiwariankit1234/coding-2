class Solution {
public:
    string strWithout3a3b(int freqa, int freqb) {
        string s="";
        priority_queue<pair<int,char>>pq;
        pq.push({freqa,'a'});
        pq.push({freqb,'b'});
        while(pq.size()){
            auto[freq1,ch1]=pq.top();
            pq.pop();
            int x=min(freq1,2);
            for(int i=1;i<=x;i++){
                s+=ch1;
            }
            
           int y=0;
             if(pq.size()>0){
              auto[freq2,ch2]=pq.top();
            pq.pop();
            if(freq1-freq2>=3){
                y=1;
            }
            else{
            y=min(freq2,2);
            }
            for(int i=1;i<=y;i++){
                s+=ch2;
            }
            freq2-=y;
            cout<<freq1<<" "<<ch1<<" "<<freq2<<" "<<ch2<<endl;
            if(freq2>0)pq.push({freq2,ch2});
             }
             freq1-=x;

             if(freq1>0)pq.push({freq1,ch1});
        }
        return s;
    }
};