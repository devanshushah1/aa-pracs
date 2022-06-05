#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int size = 1;
    int count = 0;
    int arr[size];
    int *p = arr;
    int cost = 0;

    while(1){
        int n;
        cout << "Enter number to be added to dynamic table: ";
        cin >> n;
        if(count<size){
            *(p+count) = n;
            count += 1;
            cost += 1;
        }
        else{
            int *new_arr = new int(size*2);
            for(int i=0;i<count;i++){
                new_arr[i] = *(p+i);
            }
            cost+=count+1;
            new_arr[count] = n;
            count+=1;
            size*=2;
            p = new_arr;
        }
        cout << "Amortized cost: " << cost << endl;
    }
}