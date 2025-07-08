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
    /*Q2: Swap max and min of array*/
    int max = INT_MIN, min = INT_MAX, maxIdx, minIdx;
    for(int i = 0; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
            minIdx = i;
        }
        else if(arr[i] > max){
            max = arr[i];
            maxIdx = i;
        }
    }
    cout << "Array entered by the user:\n";
    for(int i = 0; i < size; i++){
        if(i != size - 1){
            cout << arr[i] << ", ";
        }
        else{
            cout << arr[i] << endl;
        }
    }
    swap(arr[maxIdx], arr[minIdx]);
    cout << "After swapping minimum = " << min << " and maximum = " << max << ":\n";
    for(int i = 0; i < size; i++){
        if(i != size - 1){
            cout << arr[i] << ", ";
        }
        else{
            cout << arr[i] << endl;
        }
    }
    return 0;
}