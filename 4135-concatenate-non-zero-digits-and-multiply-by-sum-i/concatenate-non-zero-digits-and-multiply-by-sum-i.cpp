class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0, num = 0, place = 1, x = n;
        while (x > 0){
            int rem = x%10;
            if(rem != 0){
                sum += rem;
                num = (rem*place)+num;
                place *= 10; 
            }
            x /= 10;
        }
        return (sum * num);
    }
};