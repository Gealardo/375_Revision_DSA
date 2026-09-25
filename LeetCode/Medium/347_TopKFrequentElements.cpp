/**
 * Problem Link : https://leetcode.com/problems/top-k-frequent-elements/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct lemda{
        bool operator()(const pair<int,int>&a,const pair<int,int>&b){
            return a.second>b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        priority_queue< pair<int,int>,vector<pair<int,int>>, lemda>pq;
        for(auto &it:mp){
            pq.push({it.first,it.second});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
