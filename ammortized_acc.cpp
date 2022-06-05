#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int size = 1;
    int count = 0;
    int arr[size];
    int *p = arr;
    int account = 0;
    cout << "Initial account: " << account << endl;

    while(1){
        int n;
        cout << "Enter number to be added to dynamic array: ";
        cin >> n;
        account+=3;
        if(count<size){
            *(p+count) = n;
            count+=1;
            account-=1;
        }
        else{
            int *new_arr = new int(size*2);
            for(int i=0;i<n;i++){
                new_arr[i] = *(p+i);
            }
            account-=count;
            new_arr[count] = n;
            count+=1;
            size*=2;
            p = new_arr;
            account-=1;
        }
        cout << "Remaining balance in account is: " << account << endl;
    }
}