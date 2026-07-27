class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (endWord.empty() || find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        unordered_map<string, vector<string>> nei;
        wordList.push_back(beginWord);
        for (const string& word : wordList) {
            for (int j = 0; j < word.size(); ++j) {
                string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                nei[pattern].push_back(word);
            }
        }

        unordered_set<string> visit{beginWord};
        queue<string> q;
        q.push(beginWord);
        int res = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string word = q.front();
                q.pop();
                if (word == endWord) {
                    return res;
                }
                for (int j = 0; j < word.size(); ++j) {
                    string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                    for (const string& neiWord : nei[pattern]) {
                        if (visit.find(neiWord) == visit.end()) {
                            visit.insert(neiWord);
                            q.push(neiWord);
                        }
                    }
                }
            }
        ++res;
        }
    return 0;
    }
};
