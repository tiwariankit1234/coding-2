class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // first construct original set
        // then comapare this set while iterating if it does not contain break
        // increase count
        int n=words.size();
        unordered_set<char>original(allowed.begin(),allowed.end());
       
        int count=0;
        
        for(auto string:words){
            bool flag=true;
                for(int j=0;j<string.size();j++){
                    if(!(original.contains(string[j]))){
                        flag=false;
                        break;
                    }
                }
                if(flag)count++;
                
        }
          return count;
    }
};