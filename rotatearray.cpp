#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,i,rotVal,temp;
    cout<<"Enter size of array: ";
    cin>>n;
    vector <int> v(n),res(n,0);
    cout<<"Enter elements: \n";
    for(i=0;i<n;i++)cin>>v[i];
    cout<<"Array: ";
    for(i=0;i<n;i++)cout<<v.at(i)<<" ";
    cout<<"\nEnter no: of shifts: ";
    cin>>rotVal;
    while(rotVal>n){
    rotVal-=n;
    }
    for(i=0;i<n;i++){
        if((n-1-i)>=rotVal){
            res[(i+rotVal)]=v[i];
        }
        else{
            res[(rotVal+i)-n]=v[i];
        }
    }
    cout<<"Rotated Array:\n";
    for(i=0;i<n;i++)cout<<res.at(i)<<" ";
    return 0;
}