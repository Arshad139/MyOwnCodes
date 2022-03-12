class Solution {
public:
    
  
  int MyApproach_firstUniqChar(string s) {
        if(s.length()==0 || s.length()==1) return 0;
        
        unordered_map<char,int> hash;
        int len=s.length();
        
        for (char c : s) hash[c]++;
        for(int i=0;i<len;i++) if(hash[s[i]]==1) return i;
        
        return -1;
    
    }
  
  int Better_approach_firstUniqChar(string s) {
        if(s.length()==0 || s.length()==1) return 0;
        
        unordered_map<char,pair<int,int>> hash;
        int index_ans=s.length();
        
       for(int i=0;i<index_ans;i++){
            hash[s[i]].first++;
            hash[s[i]].second=i;
        }
        
       for(auto [c,p]: hash) if(p.first==1)  index_ans=min(index_ans,p.second);
       return index_ans==s.size()?-1:index_ans;
    }
  
  int Probably_the_best_firstUniqChar(string s) {
       int counts[26]={0};
       int len=s.length();
        int index=0;
        
        
       for(int i=0;i<len;i++){
           index=s[i]-'a';
           counts[index]++;
       }
        
       for(int i=0;i<len;i++){
           index=s[i]-'a';
           if(counts[index]==1) return i;
       }
        return -1;
    }
  
};
