/*
 * File: 440_k-th-smallest-in-lexicographical-order.h
 * Project: C++
 * File Created: Wednesday, 23rd March 2022 8:02:50 pm
 * Author: Antares (antares0982@gmail.com)
 * -----
 * Last Modified: Wednesday, 23rd March 2022 8:03:55 pm
 * Modified By: Antares (antares0982@gmail.com)
 * -----
 * Copyright 2022 (c) Antares
 */

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：5.7 MB, 在所有 C++ 提交中击败了91.83%的用户

class Solution {
public:
    constexpr pair<int, int> prevandnext(const int &x) {
        int prev = 1;
        int nxt = 1;
        for (int i = 1; i < x; ++i) {
            prev *= 10;
            prev++;
            nxt *= 10;
            nxt++;
        }
        nxt /= 10;
        return {prev, nxt};
    }

    int recursiveSearch(const string &ref, int k, string &&node, int total) {
        if (k == 1) return stoi(node);

        k--;
        total--;

        if (ref.substr(0, node.size()) == node) {
            auto [prev, nxt] = prevandnext(ref.size() - node.size());

            auto &&compv = ref[node.size()];

            int mid = total - (compv - '0') * prev - ('9' - compv) * nxt;

            char t = '0';

            while (t != compv) {
                if (k <= prev) {
                    node += t;
                    return recursiveSearch(ref, k, move(node), prev);
                }
                k -= prev;
                t++;
            }

            if (k <= mid) {
                node += t;
                return recursiveSearch(ref, k, move(node), mid);
            }
            k -= mid;
            t++;

            while (t <= '9') {
                if (k <= nxt) {
                    node += t;
                    return recursiveSearch(ref, k, move(node), nxt);
                }
                k -= nxt;
                t++;
            }

            return 0;
        }

        int tt = (node < ref) ? prevandnext(ref.size() - node.size()).first : prevandnext(ref.size() - node.size()).second;

        char t = '0';

        while (t <= '9') {
            if (k <= tt) {
                node += t;
                return recursiveSearch(ref, k, move(node), tt);
            }
            k -= tt;
            t++;
        }

        return 0;
    }

    int findKthNumber(int n, int k) {
        if (n < 10) return k;

        auto s = to_string(n);

        auto [prev, nxt] = prevandnext(s.size());

        int mid = n - (s[0] - '1') * prev - ('9' - s[0]) * nxt;

        char t = '1';

        while (t != s[0]) {
            if (k <= prev) return recursiveSearch(s, k, string(1, t), prev);
            k -= prev;
            t++;
        }

        if (k <= mid) return recursiveSearch(s, k, string(1, t), mid);

        k -= mid;
        t++;

        while (t <= '9') {
            if (k <= nxt) return recursiveSearch(s, k, string(1, t), nxt);
            k -= nxt;
            t++;
        }

        return 0;
    }
};
