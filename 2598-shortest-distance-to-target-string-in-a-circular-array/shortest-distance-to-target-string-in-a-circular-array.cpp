class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = words.size();
        int n = words.size();
        for(int i = 0; i < n; i++){
            if(words[i] == target){
                int dis = abs(i - startIndex);
                ans = min(ans, min(dis, n-dis));
            }
        }
        return ans < n? ans : -1;
    }
};