class Solution {
public:
    int maxBottlesDrunk(int x, int y) {
        int drinkbottle=x;
        while(x>=y){
          x=x-y+1;
          drinkbottle++;
          y++;
        }
        return drinkbottle;
    }
};