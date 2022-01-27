/*
 * File: 1996.cpp
 * Project: C++
 * File Created: Friday, 28th January 2022 1:41:17 am
 * Author: Antares (antares0982@gmail.com)
 * -----
 * Last Modified: Friday, 28th January 2022 1:42:10 am
 * Modified By: Antares (antares0982@gmail.com)
 * -----
 * Copyright 2022 (c) Antares
 */

// 执行用时：500 ms, 在所有 C++ 提交中击败了 97.10 % 的用户
// 内存消耗： 121.7 MB, 在所有 C++ 提交中击败了 100.00 % 的用户


class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties) {
        sort(properties.begin(), properties.end());
        int lastmax = 0;
        int dummax = 0;
        int lastx = INT32_MAX;
        int ans = 0;
        for (auto it = properties.rbegin(); it != properties.rend(); ++it) {
            auto &x = (*it)[0];
            auto &y = (*it)[1];
            if (lastx != x) {
                lastx = x;
                lastmax = max(lastmax, dummax);
                dummax = y;
            }
            if (y < lastmax) {
                ++ans;
            }
        }
        return ans;
    }
};
