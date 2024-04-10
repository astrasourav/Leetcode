Approach 1:- without using queue

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        if (deck.size() == 1 || deck.size() == 2) {
            return deck;
        }
        
        int n = deck.size();
        queue<int> que;
        vector<int> result(n);

        for (int i=0; i<n; i++) {
            que.push(i);
        }

        sort(deck.begin(), deck.end());

        for (int i=0; i<n; i++) {
            int idx = que.front();
            que.pop();

            result[idx] = deck[i];
            if (!que.empty()) {
                que.push(que.front());
                que.pop();
            }
        }

        return result;
    }
};

----------------------------------------------------------------------------------------------

Approach 2:- Using queue

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        if (deck.size() == 1 || deck.size() == 2) {
            return deck;
        }
        
        int n = deck.size();
        queue<int> que;
        vector<int> result(n);

        for (int i=0; i<n; i++) {
            que.push(i);
        }

        sort(deck.begin(), deck.end());

        for (int i=0; i<n; i++) {
            int idx = que.front();
            que.pop();

            result[idx] = deck[i];
            if (!que.empty()) {
                que.push(que.front());
                que.pop();
            }
        }

        return result;
    }
};
