class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int maxAst = 0;
        for(int a : asteroids){
            if(a > maxAst) maxAst = a;
        }

        vector<int> freq(maxAst+1, 0);
        for(int a : asteroids){
            freq[a]++;
        }

        long long currMass = mass;
        for(int i=1; i<=maxAst; i++){
            if(freq[i] > 0){
                if(i > currMass) return false;
                currMass += (long long)i * freq[i];
            }
        }
        return true;
    }
};