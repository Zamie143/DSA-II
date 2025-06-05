#include <bits/stdc++.h>
using namespace std;
int partitionASC(int A[],int p,int r){
    int x=A[r];
    int i=p-1;
    for(int j=p;j<r;j++){
        if(A[j]<=x){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}
int partitionDESC(int A[],int p,int r){
    int x=A[r];
    int i= p-1;
    for(int j=p;j<r;j++){
        if (A[j]>=x){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}
void quicksortASC(int A[],int p,int r){
    if(p<r){
        int q=partitionASC(A,p,r);
        quicksortASC(A,p,q-1);
        quicksortASC(A,q+1,r);
    }
}
void quicksortDESC(int A[],int p,int r){
    if(p<r){
        int q=partitionDESC(A,p,r);
        quicksortDESC(A,p,q-1);
        quicksortDESC(A,q+1,r);
    }
}
void output(int A[],int n){
    for(int i=0;i<n;i++){
        cout<<" "<<A[i];
    }
    cout<<endl;
}
int main(){
    int a[]={32,22,31,19,18};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<"Before:";
    output(a,n);
    quicksortASC(a,0,n-1);
    cout<<"Ascending:";
    output(a,n);
    quicksortDESC(a,0,n-1);
    cout<<"Descending:";
    output(a, n);
    return 0;
}
