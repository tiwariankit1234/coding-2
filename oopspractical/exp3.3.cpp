#include <iostream>
using namespace std;
class Distance {
private:
    int feet;
    float inches;
public:
    void getDist(){
        cout << "Enter feet: ";
    cin >> feet;
    cout << "Enter inches: ";
    cin >> inches;
    }


    void add(const Distance& d) {
    feet += d.feet;
    inches += d.inches;
    while (inches >= 12.0) {
        inches -= 12.0;
        feet++;
    }
}
   
    void divideBy(int divisor){
    feet /= divisor;
    inches /= divisor;
    while (inches < 0) {
        inches += 12.0;
        feet--;
    }
    }

    void showDist(){
        cout<<feet<<"feet"<<" "<<inches<<"inches"<<endl;
    }
};




int main() {
     int MAX_DISTANCES = 100;
    Distance distances[MAX_DISTANCES];
    int count;
    cout << "Enter the number of distances (up to 100): ";
    cin >> count;
    if (count > 0 && count <= MAX_DISTANCES) {
        for (int i = 0; i < count; ++i) {
            cout << "Enter distance " << i + 1 << ":\n";
            distances[i].getDist();
        }
        Distance average;
        for (int i = 0; i < count; ++i) {
            average.add(distances[i]);
        }

        cout<<"\n average sum:\n";
        average.showDist();
    
cout<<endl;
        average.divideBy(count);

        cout << "\nAverage distance:\n";
        average.showDist();
    } else {
        cout << "Invalid number of distances. Please enter a number between 1 and 100." << endl;
    }
    return 0;
}
