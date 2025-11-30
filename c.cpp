#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int n;
    int sum=0;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n/2;i++){
        if(a[i]==a[i+n/2])
           sum+=2;        
    }
    cout<<sum<<endl;
    return 0;
}
