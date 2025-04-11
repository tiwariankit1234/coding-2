
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        bool valid=true;
        while(q.size()>0){  
            int n=q.size();
         
            for(int i=0;i<n;i++){
            TreeNode* temp=q.front();
            q.pop();
            if(!valid and temp)return false;
            if(!temp)valid=false;

            if(temp)q.push(temp->left);
            
            if(temp)q.push(temp->right);
            
        }  
 }  
    //   int currsize=1,prevsize=1;
    //    int n=ans.size();
    //    for(int i=1;i<(n-2);i++){
    //      int currsize=ans[i].size();
    //      cout<<currsize<<" "<<prevsize<<" "<<i<<endl;
    //      if(currsize!=(prevsize*2))return false;
    //      prevsize=currsize;
    //    }
    //    vector<int> lastlevel=ans[n-2];
    // //    for(auto it:lastlevel)
    // //    cout<<it<<" ";

    //    cout<<endl;
    //    for(int i=0;i<(lastlevel.size()-1);i++){
    //         if(lastlevel[i]==-1 and lastlevel[i+1]!=-1)
    //         return false;
    //         else if(i>0 and lastlevel[i-1]==-1 and lastlevel[i]!=-1 and lastlevel[i+1]==-1)
    //         return false;
    //    }
       return true;
    }
};