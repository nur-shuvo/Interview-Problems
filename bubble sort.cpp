#include <stdio.h>
#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
      // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(arr[j], arr[j+1]);
}

int main()
{
    int n = 5;
    int arr[] = { 5,4,1,3,5};
    bubbleSort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<endl;
}
