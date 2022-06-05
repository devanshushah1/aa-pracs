# include <iostream>
# include <bits/stdc++.h>
using namespace std;

void print(int *arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

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
        cout<<"Enter the number you want to add in the dynamic array: ";
        cin>>n;
        if(count<size){
            *(p+count) = n;
            count+=1;
            cout<<"Potential: "<<potential(count, size)<<endl;
            print(p,count);
        }else{
            //double
            cout<<"DOUBLE"<<endl;
            int *new_arr = new int[size*2];
            for(int i=0; i<count; i++) new_arr[i] = *(p+i);
            size*=2;
            p = new_arr;
            *(p+count) = n;
            cout<<"Potential: "<<potential(count, size)<<endl;
            count+=1;
            print(p,count);
        }
        cout<<endl;
    }

    return 0;
}