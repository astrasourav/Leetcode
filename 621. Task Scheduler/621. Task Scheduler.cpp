class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>ch(26, 0);

        for (auto &it: tasks) {
            ch[it - 'A']++;
        }

        int time = 0;
        priority_queue<int>pq;//max_heap

        for (int i=0; i<26; i++) {
            if (ch[i] > 0) {
                pq.push(ch[i]);
            }
        }

        while (!pq.empty()) {
            vector<int> tmp;
            for (int i=1; i<=n+1; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    tmp.push_back(freq);
                }
            }

            for (auto &it: tmp) {
                if (it > 0) {
                    pq.push(it);
                }
            }

            if (pq.empty()) {
                time += tmp.size();
            } else {
                time += n+1;
            }
        }

        return time;
    }
};
