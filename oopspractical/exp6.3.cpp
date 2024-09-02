#include <iostream >
using namespace std;
class Array {
private:
int len;
int* data;
void extendArray() {
int* x = new int[len + 1];
for (int i = 0; i < len; ++i) {
x[i] = data[i];}
data = x;
len++;  }
void contractArray() {
if (len > 0) {
len--;
int* x = new int[len];
for (int i = 0; i < len; ++i) {
x[i] = data[i]; }
delete[] data;
data = x;        }}
public:
Array() : len(0), data() {}
Array(const Array& other) : len(other.len), data(new int[other.len]){
for (int i = 0; i < len; ++i) {
data[i] = other.data[i];      }}
bool append(int value) {
extendArray();
data[length - 1] = value;
return true;    }
bool chop() {
if (len > 0) {
contractArray();
return true;        }
return false;     }
void print() const {
for (int i = 0; i < len; ++i) {
cout << data[i] << " ";      }
cout <<endl;   }};
int main() {
    Array arr;
    arr.append(10);
    arr.append(20);
    arr.append(30);
    arr.append(45);
    arr.append(54);
    arr.print(); 
    arr.chop();
    arr.chop();
    arr.chop();
    arr.chop();
    arr.print(); 
    
}
