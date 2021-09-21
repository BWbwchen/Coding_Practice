
class Trie {
private:
    unordered_map<char, Trie*> child;
    bool isWord;
public:
    /** Initialize your data structure here. */
    Trie() {
        child = {}; 
        isWord = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for (char ch : word) {
            if (root->child.count(ch) == 0) {
                root->child[ch] = new Trie();
            }
            root = root->child[ch];
        } 
        root->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        for (char ch : word) {
            if (root->child.count(ch) != 0) {
                root = root->child[ch];
            } else {
                return false; 
            }
        }
        return root->isWord; 
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        for (char ch : prefix) {
            if (root->child.count(ch) != 0) {
                root = root->child[ch];
            } else {
                return false; 
            }
        }
        return true; 
    }
};
