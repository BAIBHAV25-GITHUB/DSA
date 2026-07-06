class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        auto lambda = [](vector<int> v1, vector<int> v2){
            if(v1[0] == v2[0]){
                return v1[1] > v2[1];
            }
            return v1[0] < v2[0];
        };

        sort(intervals.begin(), intervals.end(), lambda);
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if(res.back()[1] >= intervals[i][1]){
                continue;
            }
            res.push_back(intervals[i]);
        }

        return res.size();
    }
};