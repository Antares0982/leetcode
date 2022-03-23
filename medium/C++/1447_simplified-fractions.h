/*
 * File: 1447_simplified-fractions.cpp
 * Project: C++
 * File Created: Thursday, 10th February 2022 5:10:52 pm
 * Author: Antares (antares0982@gmail.com)
 * -----
 * Last Modified: Thursday, 10th February 2022 5:11:55 pm
 * Modified By: Antares (antares0982@gmail.com)
 * -----
 * Copyright 2022 (c) Antares
 */

// 执行用时：8 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：15.6 MB, 在所有 C++ 提交中击败了100.00%的用户

static unordered_set<int> *mem;
static vector<string> *smem;
int *numcount;

inline int gcd(int x, int y) {
    if (x < y) swap(x, y);
    while (y != 1) {
        x %= y;
        if (!x) return y;
        swap(x, y);
    }
    return 1;
}

int init = []() {
    mem = new unordered_set<int>[99];
    smem = new vector<string>[99];
    numcount = new int[99];
    for (int i = 100; i > 50; --i) {
        for (int j = 1; j < i; ++j) {
            int g = gcd(i, j);
            mem[i / g - 2].insert(j / g);
        }
    }

    int dum = 0;
    for (int i = 0; i < 99; ++i) {
        for (auto &v : mem[i]) {
            smem[i].emplace_back(to_string(v) + "/" + to_string(i + 2));
        }
        dum += mem[i].size();
        numcount[i] = dum;
    }

    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        if (n == 1) return {};
        vector<string> ans;
        ans.reserve(numcount[n - 2]);
        for (int i = 0; i < n - 1; ++i) ans.insert(ans.end(), smem[i].begin(), smem[i].end());
        return ans;
    }
};
