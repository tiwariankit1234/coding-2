class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hbar, vector<int>& vbar) {
        sort(hbar.begin(),hbar.end());
        sort(vbar.begin(),vbar.end());
        int p=hbar.size()-1,q=vbar.size()-1;
        unordered_set<int>visitedx,visitedy;
        int maxarea=1,horizontal=0;
        while(q>=0){
            visitedx.insert(vbar[q]);
           
            int xright=0,xleft=0;
            for(int j=1;j<=101;j++){
                if(visitedx.find(vbar[q]+j)==visitedx.end()){
                    xright=vbar[q]+j;
                    break;
                }
            }
            for(int j=1;j<=101;j++){
                if(visitedx.find(vbar[q]-j)==visitedx.end()){
                    xleft=vbar[q]-j;
                    break;
                }
            }
             horizontal=max(horizontal,xright-xleft);
             q--;
        }
        int vertical=0;
          while(p>=0){
             visitedy.insert(hbar[p]);
             int yright=0,yleft=0;
              for(int j=1;j<=101;j++){
                if(visitedy.find(hbar[p]+j)==visitedy.end()){
                    yright=hbar[p]+j;
                    break;
                }
            }
            for(int j=1;j<=101;j++){
                if(visitedy.find(hbar[p]-j)==visitedy.end()){
                    yleft=hbar[p]-j;
                    break;
                }
            }
             vertical=max(vertical,yright-yleft);
            p--;
          }
         maxarea=max(maxarea,min(vertical,horizontal)*min(vertical,horizontal));
        return maxarea;
    }
};