class Solution {
public: 

    // ye function ne boundary ke bahar to nhi h hu, ye check kr rha 
    // hai aur kuchh nhi
    // dekho bhai matrix jnha tak hogi
    // vnhi tak ghumoge ne, bas..\U0001f57a
    bool isPossible(int x,int y,int row,int col){
        if(x>=0 && x<row && y>=0 && y<col) return true;
        
        return false;
    } 

    // everyone be like 
    // chal chal aage badh..ye to
    // aata hai hme \U0001f602\U0001f602\U0001f602\U0001f602\U0001f602
    bool isPrime(int n){
        if(n<2) return false;
        
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        
        return true;
    }
    
    int mostFrequentPrime(vector<vector<int>>& mat) {
        // arey prime number puchcha tha n frequent to 
        // freq to chaiye hi...
        // kya bolti hai public \U0001f914
        unordered_map<int,int> pf; 
        
        int row=mat.size(); 
        int col=mat[0].size(); 


        // graph kiya hoga to ye to kiya hi hoga
        // 8 direction me move krne ke liye
        // ek aur simple tarika hota hai
        // janana hai to btana, bta dunga
        int d1[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int d2[8] = {-1, 0, 1, -1, 1, -1, 0, 1};


        // simple matrix ko traverse karenge
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                for(int k=0;k<8;k++){
                    
                    // us index ka digit le liya
                    int digit = mat[i][j];

                    // ye direction ke liye hai 
                    // har direction me move krnke ke liye
                    // suppose ye left me le jayega
                    // phir aage ke liye niche loop hai n...
                    int x = i+d1[k];
                    int y = j+d2[k];

                    // possible function boundary check krne ke liye
                    while(isPossible(x,y,row,col)){

                        // num =ber bna rhe prime check kr rhe 
                        // freq nikal rhe
                        // simple
                        digit = digit*10+mat[x][y];
                        if(digit>10 && isPrime(digit)){
                            pf[digit]++;
                        }
                        // us point se har jagah dekhne ke liye
                        x+=d1[k];
                        y+=d2[k];
                    }

                }
            }
        }


        // ynha to bas answer nikal rhe
        // maximum occuring ka
        int mxf=0; 
        int mxp=-1; 
        for(auto it:pf){
            int p=it.first; 
            int freq=it.second; 
            
            if(freq> mxf || (freq==mxf && p>mxp)){
                mxf=freq;
                mxp=p;
            }
        }
        
        return mxp;
        
    }
};