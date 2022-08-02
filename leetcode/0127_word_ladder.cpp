class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // check whether the endword in wordlist
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) 
            return 0;

        unordered_map<string, int> pathcnt {{beginWord, 1}};

        queue<string> q {{beginWord}};
        while (!q.empty()) {
            auto newWord = q.front(); 
            q.pop();

            for (int i = 0; i < newWord.size(); ++i) {
                auto w = newWord;
                for (char c = 'a'; c <= 'z'; c++) {
                    w[i] = c;
                    if (words.count(w) && w == endWord)
                        return pathcnt[newWord] + 1;
                    if (words.count(w) && !pathcnt.count(w)) {
                        q.push(w);
                        pathcnt[w] = pathcnt[newWord] + 1;
                    }
                }
            }
        }
        return 0;
    }
};
