class Solution {
public:
string f(int n){
    if(n==1)return "1";
string t=f(n-1);
string newstring="";
int k=t.size();
int i=0;
while(i<k){
    int j=i;
    char ch=t[i];
    while(j<k and t[j]==ch){
        j++;
    }
  
    newstring+=to_string(j-i);
    newstring+=ch;
  
    i=j;
}

return newstring;
}
    string countAndSay(int n) {
        return f(n);
    }
};