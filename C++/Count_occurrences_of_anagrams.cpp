
// Given a string, and another string, find count of occurances of all anagrams of 2nd one in 1st one.

// Input : "forxxorfxdofr", "for"
// Output : 3
// Explanation : Anagrams of the word for - for, orf, ofr appear in the text and hence the count is 3.

#include<bits/stdc++.h>
using namespace std;

// Function to count the anagrams present in string s
int solve(string str, string anagram){

    unordered_map<char, int> m;

    // Generate a map of all character occurances 
    for(auto i: anagram) 
        m[i]++;

    int k=anagram.length();
    int count=m.size();
    
    int i=0, j=0;
    int ans=0;
    
    // sliding window
    while(j<str.length()){
    
        if(m.find(str[j])!=m.end()){
            m[str[j]]--;
            if(m[str[j]]==0) count--;
        }
        
        if((j-i+1)<k) j++;
        
        else if((j-i+1)==k){

            if(count==0) ans++;

            if(m.find(str[i])!=m.end()){
                m[str[i]]++;
                if(m[str[i]]==1) count++;
            }

            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    string s = "forxxorfxdofr";
    string anagram = "for";

    int ans = solve(s, anagram);
    cout<<ans; 

    return 0;
}
