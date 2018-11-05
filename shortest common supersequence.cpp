#include<iostream>
using namespace std;
int min(int a,int b){
if(a<b)
    return a;
else
    return b;
}
int main(){
   int m,n;
   cin>>m;
   cin>>n;
   string str1,str2;
   cin.ignore();
   getline(cin,str1);
   getline(cin,str2);
   int arr[m+1][n+1];
   int i,j;
   for(i=0;i<=m;i++){
    for(j=0;j<=n;j++){
        if(!i)
            arr[i][j]=j;
        else if(!j)
            arr[i][j]=i;
        else if(str1[i-1]==str2[j-1])
            arr[i][j]=1+arr[i-1][j-1];
        else
            arr[i][j]=1+min(arr[i-1][j],arr[i][j-1]);
    }
   }
   for(i=0;i<=m;i++){
    for(j=0;j<=n;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<"\n";
   }
   cout<<"\n The length of shortest common super sequence is "<<arr[m][n];
   i=m;j=n;
   cout<<"\nThe LCS IN REVRESE ORDER IS ";
   cout<<"\n";
   int index=arr[m][n];
   string res(index+1,'\0');
   while(i>0 && j>0){
        if(str1[i-1]==str2[j-1]){
            res[index-1]=str1[i-1];
            i--;
            j--;
            index--;
        }
        else if (arr[i-1][j] < arr[i][j-1])
      { res[index-1] = str1[i-1];   i--;  index--; }
      else
      { res[index-1] = str2[j-1];  j--; index--; }
   }
   while (i > 0)
   {
       res[index-1] = str1[i-1];   i--;  index--;
   }

   // Copy remaining characters of string 'b'
   while (j > 0)
   {
       res[index-1] = str2[j-1];  j--; index--;
   }

   // Print the result
   cout << res;
   return 0;
   }
