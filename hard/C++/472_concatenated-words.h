/*
 * File: 472_concatenated-words.h
 * Project: C++
 * File Created: Tuesday, 28th December 2021 2:42:00 pm
 * Author: Antares (antares0982@gmail.com)
 * -----
 * Last Modified: Tuesday, 28th December 2021 2:43:17 pm
 * Modified By: Antares (antares0982@gmail.com)
 * -----
 * Copyright 2021 (c) Antares
 */

// Runtime: 140 ms, faster than 98.95% of C++ online submissions for Concatenated Words.
// Memory Usage: 241.8 MB, less than 46.46% of C++ online submissions for Concatenated Words.


struct trie472 {
    trie472 *mem[27] = {nullptr};

    bool searchheadAndInsert(string::const_iterator &bgn, const string::const_iterator &ed, trie472 &root) {
        if (bgn == ed) {
            mem[26] = &root;
            return false;
        }

        if (mem[26]) {
            auto bgnn = bgn;
            if (mem[26]->searchbody(bgnn, ed)) {
                return true;
            }
        }

        auto &pt = mem[(*bgn) - 'a'];
        if (!pt) {
            pt = new trie472;
        }
        return pt->searchheadAndInsert(++bgn, ed, root);
    }

    bool searchbody(string::const_iterator &bgn, const string::const_iterator &ed) {
        if (bgn == ed) return mem[26];

        if (mem[26]) {
            auto bgnn = bgn;
            if (mem[26]->searchbody(bgnn, ed)) return true;
        }
        auto &pt = mem[(*bgn) - 'a'];
        if (!pt) return false;
        return pt->searchbody(++bgn, ed);
    }
};

class Solution {
public:
    trie472 root;
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });

        vector<string> ans;
        for (const auto &s : words) {
            if (!s.size()) continue;
            auto it = s.begin();
            if (root.searchheadAndInsert(it, s.end(), root)) ans.emplace_back(s);
        }

        return ans;
    }
};

int _IO = []() {
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    return 0;
}();
