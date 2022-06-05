#include <iostream>
#include <bits/stdc++.h>
using namespace std; 

class Interviewee{
    public:    
        string name;
        int talent;
};

int compute_cost(Interviewee I[], int n, int ci, int ch){
    int best = -1;
    int cost = 0;
    for(int i=0; i<n; i++){
        cost+=ci;
        if(I[i].talent > best){
            best = I[i].talent;
            cost+=ch;
        }
    }
    return cost;
}

int compute_randomized_cost(Interviewee I[], int n, int ci, int ch){
    random_shuffle(I, I + n);
    int best = -1;
    int cost = 0;
    for(int i=0; i<n; i++){
        cost+=ci;
        if(I[i].talent > best){
            best = I[i].talent;
            cost+=ch;
        }
    }
    return cost;
}


int main(){
    cout<<"HIRING PROBLEM"<<endl;
    cout<<endl; 

    int interview_cost, hiring_cost, n;

    cout<<"enter interview cost: ";
    cin>>interview_cost;

    cout<<"enter hiring cost: ";
    cin>>hiring_cost;

    cout<<"enter number of applicants: ";
    cin>>n;

    cout<<endl;
    Interviewee I[n];
    for(int i=0; i<n; i++){
        Interviewee j;
        cout<<"Enter name of applicant "<<i<<": "; 
        cin>>j.name;
        cout<<"Enter talent of applicant "<<i<<": "; 
        cin>>j.talent;
        I[i] = j;
        cout<<endl;
    }

    int cost = compute_cost(I, n, interview_cost, hiring_cost);
    int randcost = compute_randomized_cost(I, n, interview_cost, hiring_cost);

    cout<<"Cost: "<<cost<<endl;
    cout<<"Randomized Cost: "<<randcost<<endl;

    return 0;
}