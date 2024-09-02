#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        if(s.size()<=2){
            cout<<"NO"<<endl;
            continue;
        }
        string t="";
        if(s[0]=='1' and s[1]=='0'){
        for(int i=2;i<=n-1;i++){
             t+=s[i];
        } 
        int x=stoi(t);
      if(x>=2 and s[2]!='0')cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
} 

                                                            //7

