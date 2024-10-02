class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>copy(arr);
        // sort the copy array
        sort(copy.begin(),copy.end());

        int prevrank=1;
        int prevelement=copy[0];

        vector<int>rank(n);

         map<int,int>mp;
           mp.insert({prevelement,prevrank});

           int currentrank;

           for(int i=1;i<n;i++){
             int currentelement=copy[i];
             if(currentelement==prevelement){
                currentrank=prevrank;
                mp.insert({currentelement,currentrank});
             }

             else{
                currentrank=prevrank+1;
                mp.insert({currentelement,currentrank});
             }

             prevrank=currentrank;
             prevelement=currentelement;

           }

           for(int i=0;i<n;i++){
            int num=arr[i];
            rank[i]=mp[num];
           }
           return rank;
    }
};