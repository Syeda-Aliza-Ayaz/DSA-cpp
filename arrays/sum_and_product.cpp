#include<iostream>
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
    /*Q1: Calculate sum and product of all numbers of array*/
    int sum = 0, product = 1;
    for(int num : arr){
        sum += num;
        product *= num;
    }
    cout << "Sum: " << sum << endl << "Product: " << product << endl;
    return 0;
}