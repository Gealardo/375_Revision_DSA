/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // use boyer-moore-voting algo
        int n=arr.size();
        int candidate = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            if(candidate == arr[i]) count++;
            else if(count==0){
                candidate = arr[i];
                count=1;
            }
            else count--;
        }
        int f=0;
        for(int i=0;i<n;i++){
            if(candidate == arr[i]) f++;
        }
        if(f > (n/2)) return candidate;
        return -1;
    }
};
