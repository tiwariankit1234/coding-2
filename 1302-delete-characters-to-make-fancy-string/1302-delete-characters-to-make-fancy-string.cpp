class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        if(n<=2)return s;

        int count=0;
        string newstring="";

        for(int i=0;i<n;i++){
            count=1;
            for(int j=i+1;j<n;j++){
                if(s[j]==s[i]){
                  count++;
                }
                else{
                    break;
                }
            }
            if(count>=3){
                 newstring+=s[i];
                newstring+=s[i];
                // cout<<i<<" ";
                i=i+count-1;
                // cout<<count<<" ";
                // cout<<i<<" ";
                 
                //  cout<<endl;

            }
            else{
                newstring+=s[i];
            }
        }
        return newstring;
    }
};