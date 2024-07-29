class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int , int>P;
        unordered_map<int, int> mp;
        vector<int> ans;

        int n = nums.size();
        for (int i=0; i<n; i++) {
            mp[nums[i]]++;
        }

        priority_queue<P, vector<P>, greater<P>> pq;

        for (auto it : mp) {
            int value = it.first;
            int freq = it.second;

            pq.push({freq, value});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
