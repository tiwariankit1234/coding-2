

class Solution {

public:



    int f(int i,bool flag,int budget,vector<pair<int,int>>&temp,vector<vector<array<int,2>>>&dp){

        if(i==temp.size())return 0;

        if(budget<0)return 0;

         if(dp[i][budget][flag]!=-1)return dp[i][budget][flag];

        int count=0;

        if(flag==false and budget-temp[i].second>=0){

            // int k=budget,x=0;

            // while(k-temp[i].second>=0){

            //     x++;

            //     k=k-temp[i].second;

            //     count=max(count,x+f(i+1,k,temp));

            // }

             int k=budget;

             count=max(count,1+temp[i].first+f(i,true,budget-temp[i].second,temp,dp));

        } 

        else if(flag==true and budget-temp[i].second>=0){

            count=max(count,1+f(i,true,budget-temp[i].second,temp,dp));

        }

        count=max(count,f(i+1,false,budget,temp,dp));

        return dp[i][budget][flag]=count;

    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        vector<pair<int, int>> temp;
        // budget1=budget+1;
        // items1=items.size()+1;
        // flag1=2;

       vector<vector<array<int,2>>>dp(items.size()+1,vector<array<int,2>>(budget+1,{-1,-1}));
       

        // for(int i=0;i<items.size();i++){

        //     for(int j=0;j<=budget;j++){

        //         for(int k=0;k<2;k++){

        //             dp[i][j][k]=false;

        //         }

        //     }

        // }

        for (int i = 0; i < items.size(); i++) {

            int factor = items[i][0], price = items[i][1];

            int count = 0;

            for (int j = 0; j < items.size(); j++) {

                if (j != i) {

                    int factorj = items[j][0], price = items[j][1];



                    if (j != i and factorj % factor == 0) {

                        count++;

                    }

                }

            }

            temp.push_back({count , price});

        }

        int ans = f(0,false, budget, temp,dp);

        return ans;

    }

};