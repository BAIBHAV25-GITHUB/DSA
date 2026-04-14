class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int satisfied = 0;
        for(int i = 0; i < n; i++){
            satisfied += customers[i] * (1 - grumpy[i]);
        }

        int unsat = 0, maxUnsat = 0;
        for(int i = 0; i < n; i++){
            unsat += customers[i] * grumpy[i];

            if(i >= minutes){
                unsat -= customers[i - minutes] * grumpy[i - minutes];
            }

            maxUnsat = max(maxUnsat, unsat);
        }

        return satisfied + maxUnsat;
    }
};