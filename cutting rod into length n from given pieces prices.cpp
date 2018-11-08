#include<iostream>
using namespace std;
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main(){
   int len;
   int n;
   cin>>n;
   cin>>len;
   int price[n];
   int i,j;
   for(i=0;i<n;i++)
    cin>>price[i];
   int arr[n+1][len+1];
   for(i=0;i<=n;i++){
    for(j=0;j<=len;j++){
         if(i==0 || j==0)
         arr[i][j]=0;
        else if(j>=i){
                arr[i][j]=max(arr[i-1][j],price[i-1]+arr[i][j-i]);
        }
        else{arr[i][j]=arr[i-1][j];}

    }
   }
   for(i=0;i<=n;i++){
    for(j=0;j<=len;j++){
         cout<<arr[i][j]<<" ";
    }
    cout<<"\n";
   }

   cout<<"\n MAX COST OBTAINED IS "<<arr[n][len];
   //trace back
   i=n;
   j=len;
   int ans=arr[i][j];
   cout<<"\n Pieces to be picked are \n";
   for(i=n;i>0 &&ans>0;i--){
    if(ans==arr[i-1][j]){
        continue;
    }
    else{
        cout<<i<<" ";
        ans=arr[i][j-i];
        j=j-i;
        i++;
    }
   }
   return 0;
}
