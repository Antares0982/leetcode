/*
 * File: 1610_maximum-number-of-visible-points.h
 * Project: C++
 * File Created: Tuesday, 21st December 2021 11:26:01 pm
 * Author: Antares (antares0982@gmail.com)
 * -----
 * Last Modified: Tuesday, 21st December 2021 11:53:17 pm
 * Modified By: Antares (antares0982@gmail.com)
 * -----
 * Copyright 2021 (c) Antares
 */

// Runtime: 360 ms, faster than 100.00% of C++ online submissions for Maximum Number of Visible Points.
// Memory Usage: 145.4 MB, less than 99.42% of C++ online submissions for Maximum Number of Visible Points.


const float pi = atanf(1) * 4;

class Solution {
public:
    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location) {
        int _size = 0;
        int &x = location[0];
        int &y = location[1];

        float *angarr = new float[points.size()];

        for (auto &pt : points) {
            int &px = pt[0];
            int &py = pt[1];
            if (px == x && py == y) continue;
            angarr[_size] = getangle(x, y, px, py);
            ++_size;
        }

        if (!_size) return points.size();

        sort(angarr, angarr + _size);

        int i = 0;
        int j = upper_bound(angarr, angarr + _size, (*angarr) + angle) - angarr;

        int maxwindow = j;

        if (maxwindow == _size) return points.size();

        for (int t = 0; t < _size; ++t) {
            while (angledist(angarr, _size, i, j) > angle) ++i;
            ++j;
            if (j - i >= _size) return points.size();
            maxwindow = max(maxwindow, j - i);
        }

        // delete[] angarr;

        return maxwindow + points.size() - _size;
    }

    float getangle(const int &x, const int &y, const int &px, const int &py) {
        if (py == y) return px > x ? 0 : 180;
        if (px == x) return py > y ? 90 : -90;
        float ans = atan(float(py - y) / (px - x)) / pi * 180;
        if (px < x) return py > y ? ans + 180 : ans - 180;
        return ans;
    }

    float angledist(float *const &arr, const int &_size, const int &i, const int &j) {
        const float &an1 = arr[i % _size];
        const float &an2 = arr[j % _size];
        if (an1 > an2) return an2 - an1 + 360;
        return an2 - an1;
    }
};

int _IO = []() {
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    return 0;
}();
