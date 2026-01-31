class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> ans(n, 0);
        if(k == 0) return ans;
        
        int i=-1, j=-1;
        if(k > 0){
            i = 1, j = k;
        }
        else{
            i = n - abs(k), j = n-1;
        }

        int sum = 0;
        for(int idx = i; idx <= j; idx++) sum += code[idx];

        for(int idx = 0; idx < n; idx++){
            ans[idx] = sum;
            
            sum -= code[i%n];
            i++;
            sum += code[(j+1) % n];
            j++;
        }
        return ans;
    }
};