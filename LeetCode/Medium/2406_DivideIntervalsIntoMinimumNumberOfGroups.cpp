/**
 * Problem Link : https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        int n = Arrival.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[Arrival[i]]++;mp[Departure[i]+1]--;
        }
        int count=0;
        int plate=0;
        for(auto &it : mp){
            count+=it.second;
            plate = max(plate,count);
        }
        return plate;
    }

    int minGroups(vector<vector<int>>& intervals) {
        vector<int>Arrival; vector<int>Departure;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            Arrival.push_back(intervals[i][0]);
            Departure.push_back(intervals[i][1]);
        }
        return findPlatform(Arrival,Departure);
    }
};
