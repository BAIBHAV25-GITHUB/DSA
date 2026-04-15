class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int globalMin = arrays[0][0];
        int globalMax = arrays[0].back();
        int ans = 0;
        for(int i = 1; i < arrays.size(); i++){
            int localMin = arrays[i][0];
            int localMax = arrays[i].back();

            ans = max(ans, max(localMax - globalMin, globalMax - localMin));
            globalMin = min(globalMin, localMin);
            globalMax = max(globalMax, localMax);
        }
        return ans;
    }
};