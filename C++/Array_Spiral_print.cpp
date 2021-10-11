#include<iostream>
using namespace std;
int main()
{
 int r,c;
 cin>>r>>c;
 int a[r][c];
 for(int i=0;i<r;i++){
     for(int j=0;j<c;j++){
         cin>>a[i][j];
     }
 }
//  for(int i=0;i<r;i++){
//      for(int j=0;j<c;j++){
//          cout<<a[i][j]<<" ";
//      }
//      cout<<endl;
//  }
 int sr=0;
 int er=r-1;
 int sc=0;
 int ec=c-1;
 cout<<endl;
 for(int i=sc;i<=ec;i++){
     cout<<a[sr][i]<<","<<" ";
 }
 sr++;
 for(int i=sr;i<=er;i++){
     cout<<a[i][ec]<<","<<" ";
 }
 ec--;
 for(int i=ec;i>=sc;i--){
     cout<<a[er][i]<<","<<" ";
 }
 er--;
 for(int i=er;i>=sr;i--){
     cout<<a[i][sc]<<","<<" ";
 }
 sc++;
 for(int i=sc;i<=ec;i++){
     cout<<a[sr][i]<<","<<" ";
 }
 sr++;
 for(int i=ec;i>=sc;i--){
     cout<<a[sr][i]<<","<<" ";
 }
 cout<<"END";
 return 0;
}
