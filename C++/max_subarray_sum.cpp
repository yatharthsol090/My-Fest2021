#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums)
{
    int cursum=0,maxsofar=0;
    
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        cursum+=nums[i];
        if(cursum<0)
            cursum=0;
        maxsofar=max(maxsofar,cursum);
    }
    
    if(maxsofar==0)
        maxsofar=*max_element(nums.begin(),nums.end());
    return maxsofar;
        
}    

int main()
{
   int n;
   cin>>n;

   vector<int> nums;
   for(int i=0;i<n;i++)
   {
      int x;
      cin>>x;
      nums.push_back(x);
   }
   cout<<maxSubArray(nums);
   return 0;
}