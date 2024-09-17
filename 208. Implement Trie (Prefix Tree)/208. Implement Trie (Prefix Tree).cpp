struct Node{
    Node* link[26];//Wea are assuming that character are lowercase
    bool flag = false;

    bool containKey(char ch) {
        return link[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        link[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return link[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isLast() {
        return flag;
    }

};

class Trie {
private:
    Node* root;

public:

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;//dummy node
        int n = word.size();

        for (int i=0; i<n; i++) {
            if (!node->containKey(word[i])) {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);//move to the next node.
        }

        node->setEnd();//mark tha last node as the end of a word.
    }
    
    bool search(string word) {
        Node* node = root;//dummy node
        int n = word.size();

        for (int i=0; i<n; i++) {
            if (!node->containKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }

        return node->isLast();//to check is its the last node
    }
    
    bool startsWith(string prefix) {
        Node* node = root;//dummy node
        int n = prefix.size();

        for (int i=0; i<n; i++) {
            if (!node->containKey(prefix[i])) {
                return false;
            }

            node = node->get(prefix[i]);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
