/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/majority-vote/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int n=arr.size();
        int candidate = 0;
        int second_candidate = 1;
        int count1 = 0;
        int count2 = 0;
        for(int i=0;i<n;i++){
            
            if(arr[i] == candidate) count1++;
            
            else if(arr[i] == second_candidate) count2++;
            
            else if(count1 == 0){
                   candidate = arr[i]; count1=1;
            }
            
            else if(count2 == 0) {
                second_candidate = arr[i]; count2=1;
            }
            
            else {
                count1--;count2--;
            }
        }
        vector<int>ans;
        int f1=0;int f2=0;
        for(int i=0;i<n;i++){
            if(arr[i] == candidate) f1++;
            else if(arr[i] == second_candidate) f2++;
        }
        int k = n/3;
        if(f1>k) ans.push_back(candidate);
        if(f2>k && candidate!=second_candidate) ans.push_back(second_candidate);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
