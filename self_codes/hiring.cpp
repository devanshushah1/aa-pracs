#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Interviewee{
    public:
        string name;
        int talent;
};

int compute_cost(Interviewee I[], int n, int interview_cost, int hiring_cost){
    int best = -1;
    int cost = 0;
    for(int i=0;i<n;i++){
        cost+=interview_cost;
        if(I[i].talent>best){
            best = I[i].talent;
            cost+=hiring_cost;
        }
    }
    return cost;
}

int compute_randomized_cost(Interviewee I[], int n, int interview_cost, int hiring_cost){
    random_shuffle(I, I + n);
    int best = -1;
    int cost = 0;
    for(int i=0;i<n;i++){
        cost+=interview_cost;
        if(I[i].talent>best){
            best = I[i].talent;
            cost+=hiring_cost;
        }
    }
    return cost;
}



int main(){
    int interview_cost, hiring_cost, n;
    cout << "Enter interview cost: ";
    cin >> interview_cost;
    cout << "Enter hiring cost: ";
    cin >> hiring_cost;
    cout << "Enter number of applicants: ";
    cin >> n;
    cout << endl;
    Interviewee I[n];
    for(int i=0;i<n;i++){
        Interviewee J;
        cout << "Enter name of applicant" << i << ": ";
        cin >> J.name;
        cout << "Enter talent of applicant" << i << ": ";
        cin >> J.talent;
        I[i] = J;
    }
    int cost = compute_cost(I, n, interview_cost, hiring_cost);
    int random_cost = compute_randomized_cost(I, n, interview_cost, hiring_cost);
    cout << "Cost: " << cost << endl;
    cout << "Random Cost: " << random_cost << endl;
    
}