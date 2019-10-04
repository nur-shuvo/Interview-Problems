#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void permute(int arr[], int start, int endd)
{
    if(start == endd){
        for(int i = 0;i<endd;i++)
            printf("%d",arr[i]);
        printf("\n");
        return;
    }

    permute(arr, start + 1, endd);
    int i;
    for(i = start + 1; i < endd; i++){
        if(arr[start] == arr[i])  /* If want to avoid same permutation(repeat) */
            continue;
        swap(arr, start, i);
        permute(arr, start + 1, endd);
        swap(arr, start, i);
    }
}
int main()
{
    int arr[100];
    int n ;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);

    permute(arr,0,n);
}

