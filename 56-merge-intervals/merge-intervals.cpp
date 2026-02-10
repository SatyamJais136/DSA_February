class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int i = 1, n = intervals.size();
        if(n == 0) return ans;

        sort(intervals.begin(), intervals.end());
        vector<int> newInterval = intervals[0];

        // Merge all overlapping intervals
        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= newInterval[1]){
                // overlap -> merge
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            else{
                // No overlap -> push current and reset
                ans.push_back(newInterval);
                newInterval = intervals[i];
            }
        }

        //Push the last merged interval
        ans.push_back(newInterval);
        return ans;
    }
};