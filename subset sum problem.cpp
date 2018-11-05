#include<iostream>
using namespace std;
int main(){
   int sum;
   int n;
   cin>>sum;
   cin>>n;
   int *set1;
   set1=new int[n];
   int i,j;
   for(i=0;i<n;i++)
   cin>>set1[i];
   int arr[n+1][sum+1];
   for(i=0;i<=n;i++){
    for(j=0;j<=sum;j++){
        if(i==0 &&j!=0)
            arr[i][j]=0;
        else if(j==0){
            arr[i][j]=1;
        }
        else if(j<set1[i-1]){
            arr[i][j]=arr[i-1][j];
        }
        else
            arr[i][j]=arr[i-1][j] || arr[i-1][j-set1[i-1]];
    }
   }
   cout<<"\n The Matrix after calculation is \n";
   for(i=0;i<=n;i++){
    for(j=0;j<=sum;j++)
        cout<<arr[i][j]<<" ";
    cout<<"\n";
   }
   cout<<"\n";
   if(arr[n][sum])
   {
   //trace back
   i=n;
   j=sum;
   int ans=arr[i][j];
   cout<<"\nThe subset is \n";
   while(j>0 && i>0){
    if(j<set1[i-1])
    {
        i=i-1;
        ans=arr[i][j];
        continue;
    }
    else{
        if(ans==arr[i-1][j-set1[i-1]]){
            cout<<set1[i-1]<<" ";
            j=j-set1[i-1];
            i=i-1;
            ans=arr[i][j];
        }
        else{
            i=i-1;
            ans=arr[i][j];
        }

    }
   }
   }
   else
    cout<<"\n No such sub set exist";
   return 0;
}
