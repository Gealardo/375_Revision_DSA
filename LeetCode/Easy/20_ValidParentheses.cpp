/**
 * Problem Link : https://leetcode.com/problems/valid-parentheses/
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto &c: s){
            if(st.empty() || c=='(' || c=='[' || c=='{'){
                st.push(c);
            }
            else{
                char ch = st.top();
                st.pop();
                if(c==')' && ch!='(') return false;
                if(c=='}' && ch!='{') return false;
                if(c==']' && ch!='[') return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
