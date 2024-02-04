#include <iostream>
#define SIZE 9
using namespace std;

void quickSort(int *arr,int size){
    int l=0;
    int r=size-1;
    int mid = arr[size/2];
    int temp;
    do{
        while(arr[l]<mid) l++;
        while(arr[r]>mid) r--;
        if(l<=r){
            temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
    }while(l<=r);
    if(r>0){
        quickSort(arr,r+1);
    }
    if(l<size){
        quickSort(&arr[l],size-l);
    }
}

void mergeSort(int *arr,int l,int r){
    if(l==r) return;
    int mid = (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    int i = l;
    int j = mid + 1;
    int *mas = new int[r];
    for(int step=0;step<r-l+1;step++){
        if((j > r)||((i<=mid)&&(arr[i]<arr[j])))
        {
            mas[step] = arr[i];
            i++;
        }
        else
        {
            mas[step] = arr[j];
            j++;
        }
    }
    for(int step=0;step<r-l+1;step++){
        arr[l+step] = mas[step];
    }
    delete[] mas;
}
int main()
{
    int arr[SIZE] = {6,7,9,2,3,1,4,5,8};
    //quickSort(arr,SIZE);
    mergeSort(arr,0,SIZE-1);
    for(int x:arr) cout<<x<<" ";
    return 0;
}
