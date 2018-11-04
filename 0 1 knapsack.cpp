#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int max1(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}
int main(){
    int total_weight,items;
    cin>>total_weight;
    cin>>items;
    int item_list[items][2];
    int i,j;
    for(i=0;i<items;i++){
        cin>>item_list[i][0];
        cin>>item_list[i][1];
    }
    cout<<"\n The item list is \n";
    for(i=0;i<items;i++){
        cout<<item_list[i][0]<<" "<<item_list[i][1];
    }
    int arr[items+1][total_weight+1];
    for(i=0;i<=items;i++){
        for(j=0;j<=total_weight;j++){
            if(i==0||j==0)
                arr[i][j]=0;
            else if(j<item_list[i-1][0])
                arr[i][j]=arr[i-1][j];
            else
                arr[i][j]=max1(item_list[i-1][1]+arr[i-1][j-item_list[i-1][0]],arr[i-1][j]);
        }
    }
    for(i=0;i<=items;i++){
        for(j=0;j<=total_weight;j++)
        cout<<arr[i][j]<<" ";
    cout<<"\n";}
    cout<<"\n";
    //trace back and see which items are selected
    int ans;
    i=items;j=total_weight;
    ans=arr[i][j];
    cout<<ans<<"\n";
    for(i=items;i>0 && ans>0;i--){
        if(ans==arr[i-1][j]){
            continue;
        }
        else
        {
            cout<<item_list[i-1][0]<<" ";
            ans=ans-item_list[i-1][1];
            j=j-item_list[i-1][0];
        }
        //ans=arr[i][j];
    }
    return 0;
}
