class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& py, vector<int>& tn) {
        sort(py.begin(),py.end());
        sort(tn.begin(),tn.end());
        int play_sz=py.size();
        int tra_sz=tn.size();
        
        int i=0,j=0,cnt=0;
         while(i<play_sz and j<tra_sz){
            if(py[i]<=tn[j]){
                cnt++;
                i++;
                j++;
            }
            else if(py[i]>tn[j]){
                j++;
            }
         }
        //  int cnt=0;
        //  for(auto it:mch){
        //     if(it==true)
        //     cnt++;
        //  }
         return cnt;
    }
};