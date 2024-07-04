struct Node {
    Node* links[26] = {NULL};
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class WordDictionary {
    
private:
    Node* root;

    bool searchHelper(const string& word, int index, Node* node) {
        if (index == word.length()) {
            return node->isEnd();
        }
        
        if (word[index] != '.') {
            if (!node->containsKey(word[index])) {
                return false;
            }
            return searchHelper(word, index + 1, node->get(word[index]));
        } else {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (node->containsKey(ch) && searchHelper(word, index + 1, node->get(ch))) {
                    return true;
                }
            }
            return false;
        }
    }

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */