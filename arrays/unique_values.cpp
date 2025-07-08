#include<iostream>
#include<climits>
using namespace std;

/*Homework question's solutions*/

int main(int argc, char* argv[]){
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of array:\n";
    for(int i = 0; i < size; i++){
        cout << "Element[" << i + 1 << "]: "; 
        cin >> arr[i];
    }
    /*Q3: Print all unique values in an array*/
    // sort
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
    for(int i = 0; i < size; i++){
        bool isUnique = true;
        for(int j = i + 1; j < size; j++){
            if(arr[i] == arr[j]){
                isUnique = false;
                break;
            }
        }
        if(isUnique){
            cout << arr[i] << " ";
        }
    }
    return 0;
}