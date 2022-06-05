#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int size = 1;
    int count = 0;
    int arr[size];
    int *p = arr;
    int account = 0;

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
            for(int i=0;i<count;i++){
                new_arr[i] = *(p+i);
            }
            account-=count;
            new_arr[count] = n;
            p = new_arr;
            count+=1;
            size*=2;
            account-=1;
        }
        cout << "Remaining account balance is: " << account << endl;
    }
}