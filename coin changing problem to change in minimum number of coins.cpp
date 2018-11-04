#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int min1(int a,int b){
if(a<b)
    return a;
else
    return b;
}
int main(){
   int n,coin;
   cin>>n;
   cin>>coin;
   int *supply;
   supply=new int[coin];
   int i,j;
   sort(supply,supply+coin);
   for(i=0;i<coin;i++)
    cin>>supply[i];
   int arr[coin+1][n+1];
   for(i=0;i<=coin;i++){
    for(j=0;j<=n;j++)
        if(i==0||j==0)
        arr[i][j]=0;
        else if(i==1 && j!=0){
            arr[i][j]=1+arr[i][j-supply[i-1]];
        }
        else if(j<supply[i-1])
            arr[i][j]=arr[i-1][j];
        else
            arr[i][j]=min1(arr[i-1][j],1+arr[i][j-supply[i-1]]);
   }
   cout<<"\n";
   for(i=0;i<=coin;i++){
    for(j=0;j<=n;j++)
        cout<<arr[i][j]<<" ";
    cout<<"\n";
   }
   int ans;
    i=coin;j=n;
    ans=arr[i][j];
    cout<<ans<<"\n";
    for(i=coin;i>0 && j>0;i--){
        if(ans==arr[i-1][j]){
            continue;
        }
        else
        {
            cout<<supply[i-1]<<" ";
            ans=ans-supply[i-1];
            j=j-supply[i-1];
        }
        //ans=arr[i][j];
    }
   return 0;
}
