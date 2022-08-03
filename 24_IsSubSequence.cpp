/*
LC 392. Is Subsequence
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the 
relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
*/

//My attempt - failed after few test cases.
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<int> s_pos(26,-1);
        vector<int> t_pos(26,-1);
        
        int s_len=s.length(),t_len=t.length(),ind=-1,prev=-1;
        
        for(int i=0;i<s_len;i++){
            ind=s[i]-'a';
            s_pos[ind]=i;
        }

        for(int i=0;i<t_len;i++){
            ind=t[i]-'a';
            //cout<<ind<<t[i]<<endl;
            t_pos[ind]=i;
        }
       
        for(int i=0;i<s_len;i++){
            ind=s[i]-'a';
            
            if((s_pos[ind]<=t_pos[ind]) && (t_pos[ind]!=-1) && (t_pos[ind]>prev)){
                prev=t_pos[ind];
                continue;
            }
            else return false;
        }
           
        return true;
    }
};

// Solution 1

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(),m=t.length();
        int j = 0; 
    // For index of s (or subsequence
 
    // Traverse s and t, and
    // compare current character
    // of s with first unmatched char
    // of t, if matched
    // then move ahead in s
    for (int i = 0; i < m and j < n; i++)
        if (s[j] == t[i])
            j++;
 
    // If all characters of s were found in t
    return (j == n);
    }
};

// Just improving it further 
class Solution {
public:
    bool isSubsequence(string s, string t) {
       int s_len=s.length(),t_len=t.length(),j=0;
       
        for(int i=0;i<t_len;i++){
            if(s[j]==t[i]) j++;
            if(j==s_len) return true;
        }
       
       return (j==s_len);
    }
};

// DP Solution
class Solution {
    int isSubSequence(string& s1, string& s2, int i, int j , vector<vector<int>> &dp)
{
    if (i == 0 || j == 0) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (s1[i - 1] == s2[j - 1]) {
        return dp[i][j]
               = 1 + isSubSequence(s1, s2, i - 1, j - 1,dp);
    }
    else {
        return dp[i][j] = isSubSequence(s1, s2, i, j - 1,dp);
    }
}
 
public:
    bool isSubsequence(string s, string t) {
         int m = s.size();
    int n = t.size();
    if (m > n) {
        return false;
    }
    vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
    if (isSubSequence(s, t, m, n,dp) == m) {
        return true;
    }
    else {
        return false;
    }
    }
};
