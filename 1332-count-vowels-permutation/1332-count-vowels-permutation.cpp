int mod=1e9+7;
class Solution {
public:
int dp[30][2*(int)1e4];
int f(char ch,int length,int n){
    // cout<<ch<<" "<<length<<endl;
    if(length==n){
    return 1;
    }
      if(dp[ch-'a'][length]!=-1)return dp[ch-'a'][length];
    int count=0;
    if(ch=='a'){
      count=(count%mod+f('e',length+1,n)%mod)%mod;
    }
    else if(ch=='e'){
        count=(count%mod+f('a',length+1,n)%mod)%mod;
        count=(count%mod+f('i',length+1,n)%mod)%mod;
    }
    else if(ch=='i'){
        for(char x='a';x<='z';x++){
            if(x!='i' and (x=='e')||(x=='o')||(x=='u')||(x=='a'))
            count=(count%mod+f(x,length+1,n)%mod)%mod;
        }
    }
    else if(ch=='o'){
        count=(count%mod+f('i',length+1,n)%mod)%mod;
        count=(count%mod+f('u',length+1,n)%mod)%mod;
    }
    else if(ch=='u'){
        count=(count%mod+f('a',length+1,n)%mod)%mod;
    }
    return dp[ch-'a'][length]=count;
}
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        int way=(f('a',1,n)%mod+f('e',1,n)%mod)%mod;
        way=(way%mod+f('i',1,n)%mod)%mod;
        way=(way%mod+f('o',1,n)%mod)%mod;
        way=(way%mod+f('u',1,n)%mod)%mod;

        return way;
    }
};