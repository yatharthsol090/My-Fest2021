#include <bits/stdc++.h>
using namespace std;


 // function Template for C++

class Solution {
  public:
    vector<vector<int>> NextPerms(vector<int> arr ,int n) {
        // code here
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
          do 
          {
        ans.push_back(arr);
        } while (next_permutation(arr.begin(),arr.end()));
        return ans;
    }
};
