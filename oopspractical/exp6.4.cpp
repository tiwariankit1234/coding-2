#include <iostream>
#include <unordered_set>

class Set {
private:
    std::unordered_set<int> elements;

public:
    void addElement(int element) {
        elements.insert(element);
    }

    void listElements() const {
        for (int element : elements) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    Set intersection(const Set& other) const {
       Set result;
       for(int element:elements){
        if(other.elements.find(element)!=other.elements.end()){
      
            
            result.addElement(element);
       }
          return result;
        }
        
    

    Set unionSet(const Set& other) const {
        Set result = *this;
        for (int element : other.elements) {
            result.addElement(element);
        }
        return result;
    };
};

int main() {
    Set a1, b2;
    a1.addElement(12);
    a1.addElement(23);
    a1.addElement(35);
    a1.addElement(44);

    b2.addElement(23);
    b2.addElement(35);
    b2.addElement(19);

    Set intersectionSet = a1.intersection(b2);
    std::cout << "Intersection of a1 and b2: ";
    intersectionSet.listElements();

    Set unionSet = a1.unionSet(b2);
    std::cout << "Union of a1 and b2: ";
    unionSet.listElements();

    return 0;
}
