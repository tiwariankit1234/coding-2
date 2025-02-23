class Solution {
public:

string l="";
int count=0;
void f(string s,int idx,int n,int m){
    if(s.size()==n){
      count++;
       if(count==m){
        l=s;
       }
        return ;
    }
       if(idx>=1){
        char previouschar=s[idx-1];
        for(char i='a';i<='c';i++){
            if(i!=previouschar){
                s+=i;
            f(s,idx+1,n,m);
            s.pop_back();
        }
       }
     }  
       else{
          for(char i='a';i<='c';i++){
            s+=i;
            f(s,idx+1,n,m);
           s.pop_back();
        }
       }
 
    return ;
}
    string getHappyString(int n, int k) {
         
        f("",0,n,k);
        
      
         
        return l;
    }
};