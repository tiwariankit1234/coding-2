class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // int n=arr.size();

        // if(n==0)return {};


        // vector<int>copy(arr);
        // sort the copy array
        // sort(copy.begin(),copy.end());

        // int prevrank=1;
        // int prevelement=copy[0];

        //  map<int,int>mp;
        //    mp.insert({prevelement,prevrank});

        //    int currentrank;

        //    for(int i=1;i<n;i++){
        //      int currentelement=copy[i];
        //      if(currentelement==prevelement){
        //         currentrank=prevrank;
        //         mp.insert({currentelement,currentrank});
        //      }

        //      else{
        //         currentrank=prevrank+1;
        //         mp.insert({currentelement,currentrank});
        //      }

        //      prevrank=currentrank;
        //      prevelement=currentelement;

        //    }

        //    for(int i=0;i<n;i++){
        //     int num=arr[i];
        //     arr[i]=mp[num];
        //    }
        //    return arr;


        //second approach
            
        //  int n=arr.size();   
        // unordered_map<int,int>mp;
        // set<int>s(arr.begin(),arr.end());

        //  int rank=1;
        // for(int num:s){
        //     mp.insert({num,rank});
        //     rank++;
        // }

        // for(int i=0;i<n;i++){
        //     int num=arr[i];
        //     arr[i]=mp[arr[i]];
        // }

        // return arr;

        // third approach

        map<int,vector<int>>mp;
        
        int n=arr.size();

        for(int i=0;i<n;i++){
            int num=arr[i];
            mp[num].push_back(i);
        }

        int rank=1;

        for(auto it:mp){
            for(auto index:it.second){
             arr[index]=rank;
            }

            rank++;
        }
        return arr;


    }
};