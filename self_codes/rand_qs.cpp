#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e){
    int pivot = s+(rand()%(e-s+1));
    int t =  arr[pivot];
    arr[pivot] = arr[e];
    arr[e] = t;
    pivot = e;
    int i = s;
    int pi = s;
    while(i<e){
        if(arr[pivot]>arr[i]){
            int temp = arr[pi];
            arr[pi] = arr[i];
            arr[i] = temp;
            i+=1;
            pi+=1;
        }
        else{
            i+=1;
        }
    }
    int temp = arr[pi];
    arr[pi] = arr[pivot];
    arr[pivot] = temp;
    return pi;
}

void quicksort(int arr[], int s, int e){
    if(s>=e) return;

    int p = partition(arr, s, e);
    quicksort(arr, s, p-1);
    quicksort(arr, p+1, e);
}

int main(){
    int arr[7] = {7,1,4,5,2,6,3};
    quicksort(arr, 0,6);
    for(int i=0;i<7;i++){
        cout << arr[i] << " ";
    }
    return 0;
}