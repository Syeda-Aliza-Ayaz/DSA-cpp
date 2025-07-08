#include<iostream>
#include<climits>
using namespace std;

/*Homework question's solutions*/

int main(int argc, char* argv[]){
    int size1;
    cout << "Enter the number of elements of array 1: ";
    cin >> size1;
    int arr1[size1];
    cout << "Enter the elements of array 1:\n";
    for(int i = 0; i < size1; i++){
        cout << "Element[" << i + 1 << "]: "; 
        cin >> arr1[i];
    }
    int size2;
    cout << "Enter the number of elements of array 2: ";
    cin >> size2;
    int arr2[size2];
    cout << "Enter the elements of array 2:\n";
    for(int i = 0; i < size2; i++){
        cout << "Element[" << i + 1 << "]: "; 
        cin >> arr2[i];
    }
    /*Q4: Print intersection of two arrays*/
    // assuming all elements are unique
    bool first = false;
    cout << "[";
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            if(arr1[i] == arr2[j]){
                if(first){
                    cout << " ";
                }
                cout << arr1[i];
                first = true;
                break;
            }
        }
    }
    cout << "]";
    
    return 0;
}