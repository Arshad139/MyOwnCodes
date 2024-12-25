//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include<iostream>
#include<string>
#include<unordered_set>

using namespace std:

int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> set;
        int left = 0,curr_len = 0, max_len = 0;

        for(int right = 0;right<n;right ++){
            // Here you had followed a template from a previous problem, clear the duplicates before hand & adjust your left pointer accordingly, while updating the set, you wont even need the curr_len variable, but you can keep it for easy readability.
            while(set.count(s[right])){
                set.erase(s[left]);
                curr_len = curr_len - 1;
                left++;
            }

            set.insert(s[right]);
            curr_len = curr_len + 1;
            max_len = max(max_len,curr_len);
        }

        return max_len;
    }

int lengthOfLongestSubstring2(string s) {
        unordered_set<char> set;
        int left = 0, max_len = 0;

        for(int right = 0;right<s.size(); right ++){
            while(set.count(s[right])){
                set.erase(s[left]);
                left++;
            }

            set.insert(s[right]);
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }

int lengthOfLongestSubstring3(string s) {
        unordered_set<char> set;
        int left = 0, max_len = 0;

        for(int right = 0;right<s.size();right ++){
            
            while(set.count(s[right])) set.erase(s[left++]);

            set.insert(s[right]);

            max_len = max(max_len,right-left+1);
        }

        return max_len;
    }


int main (){
  string s = "abcabcbbb";
  cout<<longestSubstring;
  return 0;
}
