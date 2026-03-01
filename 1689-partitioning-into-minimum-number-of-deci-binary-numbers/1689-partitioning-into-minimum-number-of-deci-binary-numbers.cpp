class Solution {
public:
    int minPartitions(string n) {
       
        int x=0;
        for(char ch:n){
            if(ch-'0'>x){
                x=ch-'0';
            }
        }
        return x;
    }
};