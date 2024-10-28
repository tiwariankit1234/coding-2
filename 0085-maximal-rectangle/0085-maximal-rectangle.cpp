class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        int maxarea=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                  int minwidth=cols;
                if(matrix[i][j]=='1'){
                    int length=0;
                   
                    for(int k=i;k<rows;k++){
                        if(matrix[k][j]=='0'){
                        break;
                        } 
                           length++;
                             
                           int width=0;   
                          for(int l=j;l<cols;l++){
                            if(matrix[k][l]=='1')
                            width++;
                            else{
                               break; 
                            }
                          }
                          minwidth=min(width,minwidth);

                         int area=minwidth*length;
                        // cout<<area<<" "<<i<<" "<<j<<" "<<endl;
                        maxarea=max(area,maxarea);
                        

                        
                    }
                }
            }
        }
        return maxarea;
    }
};