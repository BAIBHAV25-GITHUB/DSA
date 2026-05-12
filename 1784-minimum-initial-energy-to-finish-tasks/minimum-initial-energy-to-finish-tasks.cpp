class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return (a[1] - a[0]) > (b[1] - b[0]);
    }

    bool isPossible(vector<vector<int>>& tasks, int mid){
        for(auto& task : tasks){
            int actual = task[0];
            int minimum = task[1];

            if(minimum > mid){
                return false;
            }
            mid -= actual;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        int l = 0, r = 1e9;
        int ans = INT_MAX;

        sort(tasks.begin(), tasks.end(), comp);

        while(l <= r){
            int mid = l + (r-l)/2;
            if(isPossible(tasks, mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};