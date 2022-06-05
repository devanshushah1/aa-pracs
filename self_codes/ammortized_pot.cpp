#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int potential(int count, int size){
    return (2*count - size);
}

int main(){
    int size = 1;
    int count = 0;
    int arr[size];
    int *p = arr;

    while(1){
        int n;
        cout << "Enter number to be added to dynamic array: ";
        cin >> n;
        if(count<size){
            *(p+count) = n;
            count +=1;
            cout << "Potential: " << potential(count, size) << endl;
        }
        else{
            int *new_arr = new int(size*2);
            for(int i=0;i<count;i++){
                new_arr[i] = *(p+i);
            }
            new_arr[count] = n;
            p = new_arr;
            count +=1;
            size*=2;
            cout << "Potential: " << potential(count, size) << endl;
        }
        cout << endl;
    }
}
