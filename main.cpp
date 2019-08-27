#include <iostream>

using namespace std;

int OneThirdElement(int arr[], int arrSize, int oneThird, int index){
    int checkerIndex = oneThird + 1;
    bool leftFlag = true, rightFlag = true;
    if(arrSize < oneThird){
        return 0;
    }
    else{
       for(int i = index; i < checkerIndex; i++){
       if(arr[i] >= arr[checkerIndex]){
         leftFlag = false;
       }
     }
     int rightIndex;
     if(index > 1){
        rightIndex = checkerIndex + index;
     }
     else{
        rightIndex =  checkerIndex + oneThird;
     }

     if(rightIndex <= arrSize){
        for(int i = rightIndex; i > checkerIndex; i--){
            if(arr[i] <= arr[checkerIndex]){
                rightFlag = false;
            }
        }
     }
     else if(rightIndex > arrSize ){
        rightFlag = false;
     }
     if(leftFlag == true && rightFlag == true){
        cout << "The 1/3 element is: " << arr[checkerIndex] << endl;
     }
     return OneThirdElement(arr, arrSize, oneThird + oneThird, oneThird);
    }

}

int main()
{
    int arrSize;
    cout << "Enter the array size: ";
    cin >> arrSize;
    int arr[arrSize];
    cout << "Enter the array elements: ";
    for(int i = 1; i <= arrSize; i++){
        cin >> arr[i];
    }
    int oneThird = (arrSize / 3);
    OneThirdElement(arr, arrSize, oneThird, 1);
    return 0;
}
