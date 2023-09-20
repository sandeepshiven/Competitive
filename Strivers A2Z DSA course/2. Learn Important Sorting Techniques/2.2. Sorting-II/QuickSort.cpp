#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


class Solution
{
    public:
    int partitionArray(int arr[], int low, int high){
        
        int pivot = arr[low];
        int i = low;
        int j = high;
        while(i < j){
            // all elements on left of pivot must be smaller than pivot
            while(i<=high && arr[i] <= pivot) i++;
            //all elements on right of pivot must be greater than pivot
            while(j>=low && arr[j] > pivot) j--;
            if(i < j){ // if i has not crossed j i.e. all elements are not in right place then swap
                swap(arr[i], arr[j]); 
            }
        }
        swap(arr[low], arr[j]); // every element is in correct place and j is pointing to smaller value as j has crossed i so we can swap arr[low] with arr[j]
        return j;
        
    }
    public:
    void quickSort(int arr[], int low, int high){

        if(low < high){
            int partition = partitionArray(arr, low, high);   
            quickSort(arr, low, partition-1);  
            quickSort(arr, partition+1, high);   
        }        
    }
};




int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}