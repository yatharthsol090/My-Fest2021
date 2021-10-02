#include<iostream>
using namespace std;
void selection(int [],int);
int main()
{

int ar[50],size,i;
cout<<"Enter number of elements=";
cin>>size;
cout<<"Enter Array's Elements=";
for(i=0;i<size;i++)
cin>>ar[i];

selection(ar,size);

return 0;
}
void selection(int ar[],int size)
{
int i,j,small,pos;
for(i=0;i<size-1;i++)
{
small=ar[i];
pos=i;
for(j=i+1;j<size;j++)
{
if(ar[j]<small)
{
small=ar[j];
pos=j;    
}
}    
ar[pos]=ar[i];
ar[i]=small;
}
cout<<"After Sorting elements are";
for(i=0;i<size;i++)
cout<<"\n"<<ar[i];
}