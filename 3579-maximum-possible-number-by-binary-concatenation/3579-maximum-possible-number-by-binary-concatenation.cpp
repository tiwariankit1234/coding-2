class Solution {
public:

int stringtonum(string s){
    int decimalNumber=0;
  for (int i = 0; i < s.length(); ++i) {
        if (s[s.size() - i - 1] == '1') {
            decimalNumber += pow(2, i);
        }
    }
return decimalNumber;
}

 string f(int n){
    string s="";

    while(n>0){
        if(n%2)
        s+="1";
        else
        s+="0";

        n=n/2;
    }
        reverse(s.begin(),s.end());
    return s;
 }

    int maxGoodNumber(vector<int>& nums) {
        int n=nums.size();

        vector<string>numstostring(n);

        for(int i=0;i<n;i++){
         numstostring[i]=f(nums[i]);
        }

        // for(auto it:numstostring)
        // cout<<it<<" ";

        int maxans=0;
     
        // cout<<stringtonum(numstostring[0])<<" "<<stringtonum(numstostring[1])<<" "<<stringtonum(numstostring[2])<<endl;

        int ans1=stringtonum(numstostring[0]+numstostring[1]+numstostring[2]);

        maxans=max(ans1,maxans);

        int ans2=stringtonum(numstostring[0]+numstostring[2]+numstostring[1]);
          maxans=max(ans2,maxans);

         int ans3=stringtonum(numstostring[1]+numstostring[0]+numstostring[2]);
                maxans=max(ans3,maxans);


           int ans4=stringtonum(numstostring[1]+numstostring[2]+numstostring[0]);
                     maxans=max(ans4,maxans);

           int ans5=stringtonum(numstostring[2]+numstostring[0]+numstostring[1]);
                maxans=max(ans5,maxans);

           int ans6=stringtonum(numstostring[2]+numstostring[1]+numstostring[0]);
           maxans=max(ans6,maxans);

           return maxans;
    }
};