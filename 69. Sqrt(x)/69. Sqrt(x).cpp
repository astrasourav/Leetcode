//Brure force approach
class Solution {
public:
    int mySqrt(int x) {
        int ans=1;
        for (int i=1; i<x; i++) {
            if ((i*i) <= x) {
                ans = i;
            } else {
                break;
            }
        }

        return ans;
    }
};

//Optimal approach (using binary search)
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        int low = 1, high = x;
        while (low <= high) {
            long long mid = low +(high - low)/2;
            long long val = mid*mid;
            if (val <= x) {
                low = mid+1;
            } else {
                high = mid -1;
            }
        }

        return high;
    }
};
