#include<iostream>
using namespace std;
int main(){
   int n;
   cin>>n;
   int *arr;
   arr=new int[n];
   int i,j;
   for(i=0;i<n;i++)
    cin>>arr[i];
   int sum=0;
   for(i=0;i<n;i++)
    sum+=arr[i];
   if(sum%2!=0)
    cout<<"False";
   else{
    bool part[(sum/2+1)+1][n+1];
    for(i=0;i<=n;i++)
        part[0][i]=true;
    for(i=1;i<=sum/2;i++)
        part[i][0]=false;
    for(i=1;i<=sum/2;i++){
        for(j=1;j<=n;j++){
            part[i][j]=part[i][j-1];
            if(i>=arr[j-1]){
                part[i][j]=part[i][j] ||part[i-arr[j-1]][j-1];
            }
        }
    }
    cout<<part[sum/2][n];
   }
   return 0;
}
