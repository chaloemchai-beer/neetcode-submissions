class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combine(int n, int k) {
        res.clear();
        vector<int> comb;
        backtrack(1, n, k, comb);
        return res;
    }

    void backtrack(int start, int n, int k, vector<int>& comb) {
        if (comb.size() == k) {
            res.push_back(comb);
            return;
        }

        for (int i = start; i <= n; i++) {
            comb.push_back(i);
            backtrack(i + 1, n, k, comb);
            comb.pop_back();
        }
    }
};