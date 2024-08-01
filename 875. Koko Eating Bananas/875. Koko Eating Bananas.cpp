class Solution {
public:

    int findmax(vector<int>& piles) {
        int maxi = INT_MIN;
        int n = piles.size();

        for (int i=0; i<n; i++) {
            maxi = max(piles[i], maxi);
        }

        return maxi;
    }

    long long calHour(vector<int>& piles, int hour) {
        long long totalHour = 0;
        int n = piles.size();

        for (int i = 0; i < n; i++) {
            totalHour += ceil( (double)piles[i] / (double)hour); 
        }
        return totalHour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = findmax(piles);
        
        int l = 1, r = maxi;

        while (l <= r) {
            int mid = l + (r-l)/2;

            long long time = calHour(piles, mid);
            if (time <= h) {
                r = mid-1;//because we have to find the minimum
            } else {
                l = mid +1;
            }
        }

        return l;
    }
};
