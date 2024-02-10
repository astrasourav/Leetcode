class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() ==0) {
            return 0;
        }

        sort(citations.rbegin(), citations.rend());

        int h=0;

        while (h < citations.size() && citations[h] > h) {
            h++;
        }

        return h;

    }
};
