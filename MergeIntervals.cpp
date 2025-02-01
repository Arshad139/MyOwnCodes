// https://leetcode.com/problems/merge-intervals/description/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
 //    int merged = 0;
	// int n = arr.size();
	// do{
	// 	merged = 0;
 //        for (int i = 1; i < n; i++) {
	// 		if(arr[i][0] <= arr[i-1][1]){
	// 			arr[i-1][1] = arr[i][1];
	// 			arr.erase(arr.begin()+i);
	// 			n--;
	// 			merged++;
	// 		}
 //        }
	// } while(merged > 0);
 //    return arr;
        
        
        //The above was your previous approach, but the below one looks great enough, to start with, you will need the intervals to be in a sorted order. 
        //Then you use an output array, where you keep pushing the merged intervals, the first interval goes in first & then you iterate over the arrays by comparing
        //the elements & thus by updating the previous elemets upper bound - this is what you call the merging operation. There was no question of index being out of range too. 
        int n = intervals.size();
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        for(int i = 0; i<n; i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1])
                ans.push_back(intervals[i]);
            else
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }

        return ans;
    }
The below code is when you tried to do it yourself, after a few weeks.
 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();
        ans.push_back(intervals[0]);
        int ans_index = 0;
        for(int i=1; i<n; i++){
            if(intervals[i][0] <= ans[ans_index][1]){
                ans[ans_index][1] = max(intervals[i][1], ans[ans_index][1]);
            } else{
                ans.push_back(intervals[i]);
                ans_index++;
            }
        }
        return ans;
    }
};
