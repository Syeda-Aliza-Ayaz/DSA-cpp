#include<iostream>
#include<climits>
using namespace std;

//LEETCODE 53

int main(int argc, char* argv[]){
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int arr[size];
    cout << "Enter elements of array:\n";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    int currentSum = 0, maxSum = INT_MIN;
    // //maximum sum of subarray - brute-force approach - O(n^3)
    // cout << "------------------------- BRUTE FORCE APPROACH -------------------------\n";
    // for(int start = 0; start < size; start++){
    //     currentSum = 0;
    //     for(int end = start; end < size; end++){
    //         currentSum += arr[end];
    //         maxSum = max(currentSum, maxSum);
    //     }
    // }
    // cout << "Maximum sub-array sum by Brute-force = " << maxSum << endl;
    //maximum sum of subarray - Kadane's algorithm approach - O(n)
    cout << "------------------------- KADANE'S ALGORITHM -------------------------\n";
    currentSum = 0, maxSum = INT_MIN;
    for(int i = 0; i < size; i++){
        currentSum += arr[i];
        maxSum = max(currentSum, maxSum);
        if(currentSum < 0){ // If the sum goes negative, reinitialize it with 0, because elements giving negative sum can never give max sum
            currentSum = 0;
        }
    }
    cout << "Maximum sub-array sum by Kadane's approach = " << maxSum << endl;
    return 0;
}