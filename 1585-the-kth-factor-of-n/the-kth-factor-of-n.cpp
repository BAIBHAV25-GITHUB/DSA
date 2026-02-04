class Solution {
public:
    int kthFactor(int n, int k) {
        // int cnt = 0;
        // for(int i=1; i<=n; i++){
        //     if(n % i == 0){
        //         cnt += 1;
        //         if(cnt == k) return i;
        //     }
        // }
        // return -1;

        int root = sqrt(n);
        for(int i = 1; i <= root; i++){
            if(n % i == 0){
                k--;
                if(k == 0) return i;
            }
        }
        for(int i = root; i >= 1; i--){
            if(n % i == 0 && i != n/i){
                k--;
                if(k == 0) return n/i;
            }
        }
        return -1;
    }
};