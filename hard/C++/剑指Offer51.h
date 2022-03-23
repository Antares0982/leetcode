/*
 * File: 剑指Offer51.h
 * Project: C++
 * File Created: Thursday, 10th February 2022 5:09:26 pm
 * Author: Antares (antares0982@gmail.com)
 * -----
 * Last Modified: Thursday, 10th February 2022 5:09:50 pm
 * Modified By: Antares (antares0982@gmail.com)
 * -----
 * Copyright 2022 (c) Antares
 */

// 执行用时：88 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：43.1 MB, 在所有 C++ 提交中击败了92.23%的用户

class Solution {
public:
    vector<int>::iterator v0;
    int *v1 = nullptr;

    int reversePairs(const vector<int>::iterator &bg, const vector<int>::iterator &ed) {
        if (ed - bg <= 1) return 0;
        const auto md = bg + (ed - bg) / 2;
        auto ans = reversePairs(bg, md) + reversePairs(md, ed);

        // 排序
        auto it1 = bg;
        auto it2 = md;
        auto st = v1 + (bg - v0);
        while (it1 != md || it2 != ed) {
            if (it1 == md || (it2 != ed && *it2 < *it1)) {
                *(st++) = *(it2++);
            } else {
                // 填入it1，计算贡献
                // it2==ed || *it1<=*it2
                // 也就是[md, it2)都是已经排好序的, 都小于*it1
                ans += it2 - md;
                *(st++) = *(it1++);
            }
        }
        // copy back
        copy(v1 + (bg - v0), v1 + (ed - v0), bg);

        return ans;
    }

    int reversePairs(vector<int> &nums) {
        if (nums.size() <= 1) return 0;
        if (nums.size() == 2) return nums[0] > nums[1] ? 1 : 0;
        v0 = nums.begin();
        v1 = new int[nums.size()];
        return reversePairs(nums.begin(), nums.end());
    }

    ~Solution() { delete[] v1; }
};

int _IO = []() {
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    return 0;
}();