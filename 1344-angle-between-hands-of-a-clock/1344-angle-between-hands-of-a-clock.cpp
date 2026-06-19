class Solution {
public:
    double angleClock(int h, int min) {
        double minutes=min;
        double hour=h;
        double minutesdegree=minutes*6;
         double hoursdegree=hour*30;
         hoursdegree+=((minutes)/60)*30;
         cout<<hoursdegree<<" "<<minutesdegree<<endl;
         if(hoursdegree-360.00000>=0.00000){
            hoursdegree=hoursdegree-360.00000;
         }
         double  x=abs(hoursdegree-minutesdegree);
         if(x>=180.00000){
            x=360.00000-x;
         }
         return x;
    }
};