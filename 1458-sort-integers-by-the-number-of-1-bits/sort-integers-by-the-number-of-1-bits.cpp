class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b){
            int setBitA = __builtin_popcount(a);
            int setBitB = __builtin_popcount(b);
            if(setBitA == setBitB) return a<b;
            return setBitA < setBitB;
        });
        return arr;
    }
};