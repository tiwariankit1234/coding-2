class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s2.size()-s1.size();
        int n=s2.size();
        // cout<<n<<endl;
        
        // cout<<s1.size()<<endl;

        // unordered_map<char,int>mp1,mp2;

       vector<int>arr1(26);
    


       for(int i=0;i<s1.size();i++){
         int index=s1[i]-'a';
         arr1[index]++;
       }

     

          string newstring="";
        for(int i=0;i<=k;i++){
              
               vector<int>arr2(26);
               int count=0;
            for(int j=i;j<n;j++){
                count++;
                if(count>(s1.size()))break;
                 arr2[s2[j]-'a']++;
                //   if(arr1==arr2){
                //     // cout<<i<<" "<<j<<endl;
                //     return true;

                //   }
                  
            }
                if(arr1==arr2){
                    // cout<<i<<" "<<j<<endl;
                    return true;
        }
    } 
        return false;
    }
};