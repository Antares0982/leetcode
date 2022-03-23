/*
 * File: 911_online-election.cpp
 * Project: C++
 * File Created: Tuesday, 21st December 2021 11:41:21 pm
 * Author: Antares (antares0982@gmail.com)
 * -----
 * Last Modified: Tuesday, 21st December 2021 11:54:08 pm
 * Modified By: Antares (antares0982@gmail.com)
 * -----
 * Copyright 2021 (c) Antares
 */

// Runtime: 192 ms, faster than 99.27% of C++ online submissions for Online Election.
// Memory Usage: 102.8 MB, less than 90.22% of C++ online submissions for Online Election.


class TopVotedCandidate {
private:
    vector<int> tm;
    int *ans;

public:
    TopVotedCandidate(vector<int> &persons, vector<int> &times) : tm(times) {
        int _size = tm.size();
        ans = new int[_size];

        int maxperson = 0;
        for (auto &v : persons)
            if (v > maxperson) maxperson = v;

        int *mem = new int[maxperson + 1]{0};
        int maxvote = 0;
        for (int i = 0; i < _size; ++i) {
            int &v = ++mem[persons[i]];
            if (v >= maxvote) {
                ans[i] = persons[i];
                maxvote = v;
            } else {
                ans[i] = ans[i - 1];
            }
        }

        // delete[] mem;
    }

    int q(int t) {
        auto se = [&](const vector<int>::iterator &p) { return *p > t; };
        return ans[upper_bound(tm.begin(), tm.end(), t) - 1 - tm.begin()];
    }

    // ~TopVotedCandidate() { delete[] ans; }
};
