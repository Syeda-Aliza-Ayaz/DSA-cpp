#include<iostream>
#include<stdexcept>
using namespace std;

template <typename T>

class vector{
    private:
        int vecSize;
        int vecCapacity;
        T* arr;

        void resize(){
            vecCapacity *= 2;
            T* newArr = new T[vecCapacity];
            for(int i = 0; i < vecSize; i++) { //copy elements
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }

    public:
        vector(){
            vecSize = 0;
            vecCapacity = 2;
            arr = new T[vecCapacity];
        }
        vector(int s){
            vecSize = s;
            vecCapacity = s * 2;
            arr = new T[vecCapacity];
            for(int i = 0; i < vecSize; i++){
                arr[i] = 0;
            }
        }
        vector(int s, int initial){
            vecSize = s;
            vecCapacity = s * 2;
            arr = new T[vecCapacity];
            for(int i = 0; i < vecSize; i++){
                arr[i] = initial;
            }
        }
        void push_back(T value){
            if(vecSize == vecCapacity){
                resize();
            }
            arr[vecSize] = value;
            vecSize++;
            return;
        }
        void pop_back(){
            vecSize--;
            return;
        }
        int size() const {
            return vecSize;
        }
        int capacity() const {
            return vecCapacity;
        }
        T front() const {
            return arr[0];
        }
        T back() const {
            return arr[vecSize - 1];
        }
        T at(int index) const {
            if(index >= 0 and index < vecSize)
                return arr[index];
            else
                throw invalid_argument("Index out of bound!");
        }
        void clear(){
            vecSize = 0;
            return;
        }
        bool empty() const {
            return vecSize == 0;
        }
        void insert(int index, T value){
            if(index < 0 || index >= vecSize){
                throw invalid_argument("Index out of bounds!");
                return;
            }
            if(vecSize == vecCapacity){
                resize();
            }
            for(int i = vecSize; i > index; i--){
                arr[i] = arr[i - 1];
            }
            arr[index] = value;
            vecSize++;
            return;
        }
        void erase(int index){
            if(index < 0 || index >= vecSize){
                throw invalid_argument("Index out of bounds!");
                return;
            }
            for(int i = index + 1; i < vecSize; i++){
                arr[i - 1] = arr[i];
            }
            vecSize--;
            return;
        }
        T* begin() const {
            return arr;
        }
        T* end() const {
            return &arr[vecSize];
        }
        vector& operator=(const vector& obj){
            if(this != &obj){
                delete[] arr;
                vecSize = obj.vecSize;
                vecCapacity = obj.vecCapacity;
                arr = new T[vecCapacity];
                for(int i = 0; i < vecSize; i++){
                    arr[i] = obj.arr[i];
                }
            }
            return *this;
        }
        T& operator[](int index){
            if(index >= 0 and index < vecSize)
                return arr[index];
            else
                throw invalid_argument("Index out of bound!");
        }
        // for const vector<int>
        const T& operator[](int index) const {
            if(index >= 0 && index < vecSize)
                return arr[index];
            else
                throw invalid_argument("Index out of bound!");
        }
        vector(const vector& obj){
            vecSize = obj.vecSize;
            vecCapacity = obj.vecCapacity;
            arr = new T[vecCapacity];
            for(int i = 0; i < vecSize; i++){
                arr[i] = obj.arr[i];
            }
        }
        ~vector(){
            delete[] arr;
        }
};

int main(int argc, char* argv[]){
    vector<int> v;

    try {
        cout << "Pushing 10, 20, 30...\n";
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);

        cout << "Size: " << v.size() << endl;
        cout << "Capacity: " << v.capacity() << endl;

        cout << "Front: " << v.front() << endl;
        cout << "Back: " << v.back() << endl;

        cout << "Element at index 1: " << v.at(1) << endl;

        cout << "Inserting 99 at index 1...\n";
        v.insert(1, 99);

        cout << "Erasing element at index 2...\n";
        v.erase(2);

        cout << "Using operator[]:\n";
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;

        cout << "Calling pop_back() twice...\n";
        v.pop_back();
        v.pop_back();

        cout << "Size after popping: " << v.size() << endl;

        cout << "Trying to access out-of-bounds element at index 10...\n";
        cout << v.at(10) << endl; // Will throw exception

    } 
    catch (const invalid_argument& e) {
        cerr << "❌ Caught exception: " << e.what() << endl;
    }
    return 0;
}
