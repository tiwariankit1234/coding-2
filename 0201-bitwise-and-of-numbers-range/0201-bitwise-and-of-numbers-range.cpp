#define ll long long
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int n=32,ans1=0,ans2=0;
        
            if(left==right)return left;
        for(int i=1;i<=n;i++){
          ll x=pow(2,i);
           
            if(x>left){
           ans1=i-1;
             break;
           }

        }
         for(int i=1;i<=n;i++){
          ll x=pow(2,i);
         
          if(x>right){
           ans2=i-1;
             break;
           }

        }    
        cout<<ans1<<" "<<ans2<<endl;
             ll ans3=left;
        if(ans1==ans2){

      
        for(ll i=left+1;i<=right;i++){
        ans3=ans3&i;
        
        }  
         
    }

    else 
    return 0;

    return ans3;
    }
};