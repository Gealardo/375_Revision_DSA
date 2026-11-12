/**
 * Problem Link : https://leetcode.com/problems/find-a-peak-element-ii/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int i = 0;
        int j = m-1;
        while(i<=j){
            int mid = i+(j-i)/2;

            int maxi = mat[0][mid];
            int maxi_idx = 0;
            for(int k=1; k<n; k++){
                if(mat[k][mid] > maxi){
                    maxi = mat[k][mid];
                    maxi_idx = k;
                }
            }
            if(mid-1 < 0 && mid+1 == m){
               return {maxi_idx , mid};
            }
            else if(mid-1 < 0){
                if(mat[maxi_idx][mid+1] < maxi){
                     return {maxi_idx , mid};
                }else{
                    i = mid+1;
                }
            }
            else if(mid+1 == m){
                if(mat[maxi_idx][mid-1] < maxi){
                    return {maxi_idx , mid};
                }else{
                    j = mid-1;
                }
            }
            else if(mat[maxi_idx][mid-1] < maxi && mat[maxi_idx][mid+1] < maxi){
                return {maxi_idx , mid};
            }else if(mat[maxi_idx][mid-1] > maxi){
                j = mid-1;
            }else{
                i = mid+1;
            }
        }
        return {-1,-1};
    }
};
