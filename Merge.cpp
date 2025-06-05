#include <bits/stdc++.h>
using namespace std;
void merge(int A[],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    int L[n1+1],R[n2+1];
    for(int i=0;i<n1;i++){
        L[i]=A[p+i];
    }
    for(int j=0;j<n2;j++){
        R[j]= A[q+1+j];
    }
    L[n1]=INT_MAX;
    R[n2]=INT_MAX;
    int i=0,j=0;
    for(int k= p;k<=r;k++){
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }else{
            A[k]=R[j];
            j++;
        }
    }
}
void mergesort(int A[],int p,int r)
 {
    if(p<r)
    {
        int q = (p + r) / 2;
        mergesort(A,p,q);
        mergesort(A,q+1,r);
        merge(A,p,q,r);
    }
}
void output(int a[],int n)
 {
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout << endl;
}
int main() {
    int n;
    cout<<"Enter Size:";
    cin>>n;
    int a[n];
    cout<<"Enter the Array:";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<endl<<"Unsorted Array: ";
    output(a, n);
    mergesort(a, 0, n - 1);
    cout<<"Sorted Array: ";
    output(a, n);
    return 0;
}
