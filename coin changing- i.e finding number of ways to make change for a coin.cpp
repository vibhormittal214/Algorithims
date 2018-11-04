#include<iostream>
using namespace std;
int main(){
  int coin,supply;
  cin>>coin;
  cin>>supply;
  int *supply_item;
  supply_item=new int[supply];
  int i,j;
  for(i=0;i<supply;i++)
    cin>>supply_item[i];
  int arr[supply+1][coin+1];
  for(i=0;i<=supply;i++){
    for(j=0;j<=coin;j++){
        if(j==0 && i!=0)
            arr[i][j]=1;
        else if(i==0)
            arr[i][j]=0;
        else if(j<supply_item[i-1])
            arr[i][j]=arr[i-1][j];
        else
            arr[i][j]=arr[i-1][j]+arr[i][j-supply_item[i-1]];
    }
  }
  cout<<"\n";
  for(i=0;i<=supply;i++){
    for(j=0;j<=coin;j++)
        cout<<arr[i][j]<<" ";
    cout<<"\n";
  }
  cout<<"\n"<<"The Total possible supplies are "<<arr[supply][coin];

}

