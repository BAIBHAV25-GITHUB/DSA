class Solution {
public:
    double angleClock(int hour, int minutes) {
        double mins = 6.0*minutes;
        double hrs = 30*(hour % 12)+ 0.5*minutes;
        double diff = abs(hrs-mins);
        return min(diff, 360.0-diff);
    }
};