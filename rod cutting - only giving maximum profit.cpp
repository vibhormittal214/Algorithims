#include<iostream>
using namespace std;
int max(int a,int b){
if(a>b)
    return a;
else
    return b;
}
int main(){
    int n;
    cin>>n;
    int *price,*val;
    price=new int[n];
    val=new int[n+1];
    int i,j,max_val;
    for(i=0;i<n;i++){
        cin>>price[i];
    }
    val[0]=0;
    for(i=1;i<=n;i++){
        max_val=INT_MIN;
        for(j=0;j<i;j++){
            max_val=max(max_val,price[j]+val[i-j-1]);
        }
        val[i]=max_val;
    }
    cout<<val[n];
    return 0;
}
