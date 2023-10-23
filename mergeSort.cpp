// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void merge(int arr[],int start, int end) {
    int mid = (start+end) / 2;
    
    int leftIndex = mid - start +1;
    int rightIndex = end - mid;
    
    //create left and right array for merge
    int *leftarray = new int [leftIndex];
    int *rightarray = new int [rightIndex];
    
    //copy values from original array to left arrray
    int k = start; // pointer to starting index to original array
    for(int i=0; i<leftIndex; i++) {
        leftarray[i] = arr[k];
        k++;
    }
    
    //copy values from original array to right arrray
    k = mid + 1; // pointer to starting index to original array
    for(int i=0; i<rightIndex; i++) {
        rightarray[i] = arr[k];
        k++;
    }
    
    //actual merge logic
    // left and right is already sorted
    int left = 0;
    int right = 0;
    int mainIndex = start;
    
    while(left <leftIndex && right < rightIndex) {
        
        if(leftarray[left] < rightarray[right]) {
            arr[mainIndex] = leftarray[left];
            mainIndex++;
            left++;
        }else {
            arr[mainIndex] = rightarray[right];
            mainIndex++;
            right++;
            
        }
    }
    
    while (right < rightIndex) {
         arr[mainIndex] = rightarray[right];
         mainIndex++;
         right++;
        
    }
    
     while (left < leftIndex) {
         arr[mainIndex] = leftarray[left];
         mainIndex++;
         left++;
        
    }
    
    delete(leftarray);
    delete(rightarray);
    
    
}

void mergeSort(int arr [], int start, int end) {
    
    if(start >= end) {  // invaild and single element array
        return;
    }
    
    //break the array
    int mid = (start+end) / 2;
    //left array
    mergeSort(arr,start,mid);
    
    //right array
    mergeSort(arr,mid+1,end);
    
    //merge 2 sorted arrays from left and right
    merge(arr,start,end);
    
    
}

int main() {
    int arr [] = {2,1,6,9,4,5};
    int size = 6;
    int start = 0;
    int end = size-1;
    
    mergeSort(arr,start,end);
    cout << "Afer merge sort" << endl;
    for(int i=0; i<size; i++){
        cout << arr[i] << endl;
    }

    return 0;
}
