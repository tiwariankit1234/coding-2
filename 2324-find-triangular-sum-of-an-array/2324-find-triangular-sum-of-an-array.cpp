class Solution {
public:
// void print(queue<int>q){
//       while(q.size()){
//         cout<<q.front()<<" ";
//         q.pop();
//       }
//       return ;
// }

    int triangularSum(vector<int>& nums) {
            queue<int>q;
            int n=nums.size();
            for(auto it:nums){
                q.push(it);
            }
            while(q.size()>1){
                int x=q.size();
                cout<<x<<endl;
                queue<int>newqueue;
                for(int i=0;i<(x-1);i++){
                int top=q.front();
                q.pop();
                if(q.size()){
                   newqueue.push((top+q.front())%10);
                }

                }
                q=newqueue;

              
              


            }
            return (q.front())%10;
    }
};