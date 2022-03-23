/*
 * File: 969_pancake-sorting.cpp
 * Project: C++
 * File Created: Saturday, 19th February 2022 5:35:08 pm
 * Author: Antares (antares0982@gmail.com)
 * -----
 * Last Modified: Saturday, 19th February 2022 5:35:27 pm
 * Modified By: Antares (antares0982@gmail.com)
 * -----
 * Copyright 2022 (c) Antares
 */

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：10.8 MB, 在所有 C++ 提交中击败了73.70%的用户


class Solution {
public:
    void pancake(int &place, const int &v) {
        if (place <= v - 1) place = v - 1 - place;
    }

    vector<int> pancakeSort(vector<int> &arr) {
        if (arr.size() <= 1) return {};

        pair<int, int> *pairsort = new pair<int, int>[arr.size()];
        for (int i = 0; i < arr.size(); ++i) {
            pairsort[i] = make_pair(arr[i], i);
        }
        sort(pairsort, pairsort + arr.size());

        vector<int> ans;
        ans.reserve(2 * arr.size());

        for (int i = arr.size() - 1; i >= 0; --i) {
            int place = pairsort[i].second;
            for (auto &&v : ans) {
                pancake(place, v);
            }
            if (place == i) continue;

            if (place) ans.emplace_back(place + 1);
            ans.emplace_back(i + 1);
        }

        delete[] pairsort;
        return ans;
    }
};
