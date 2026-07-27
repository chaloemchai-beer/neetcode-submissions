class Solution {
public:
    int ladderLength(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord)) {
            return 0;
        }

        unordered_set<string> beginSet{beginWord};
        unordered_set<string> endSet{endWord};

        dict.erase(beginWord);
        dict.erase(endWord);

        int steps = 1;

        while (!beginSet.empty() && !endSet.empty()) {
            // ขยายฝั่งที่มีจำนวนน้อยกว่าเสมอ
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
            }

            unordered_set<string> nextLevel;

            for (string word : beginSet) {
                for (int i = 0; i < word.size(); ++i) {
                    char original = word[i];

                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        if (ch == original) {
                            continue;
                        }

                        word[i] = ch;

                        // สองฝั่งมาเจอกัน
                        if (endSet.count(word)) {
                            return steps + 1;
                        }

                        // เป็นคำที่ยังไม่เคยใช้
                        auto it = dict.find(word);

                        if (it != dict.end()) {
                            nextLevel.insert(word);
                            dict.erase(it);
                        }
                    }

                    word[i] = original;
                }
            }

            beginSet = move(nextLevel);
            ++steps;
        }

        return 0;
    }
};