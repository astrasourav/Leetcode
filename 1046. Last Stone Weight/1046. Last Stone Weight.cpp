class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 0) {
            return 0;
        }

        if (stones.size() == 1) {
            return stones[0];
        }

        priority_queue<int>pq;//maxheap

        for (int i=0; i<stones.size(); i++) {
            pq.push(stones[i]);
        }

        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();

            int b = pq.top();
            pq.pop();

            pq.push(abs(a-b));
        }

        return pq.top();
    }
};
