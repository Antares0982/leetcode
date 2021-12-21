# leetcode
My Leetcode solutions with fast runtime. C++ and Go are commonly used.

## Some tricks

* For C++, leetcode do not consider memory release. You may not `delete` in leetcode (but it is a bad habit!). Also, declaring `new int[n]` will not be counted into memory you used. Memory is counted only when you access it.

* Use this to accelerate in C++:

  ```c++
  int _IO = []() {
      ios::sync_with_stdio(0);
      cin.tie(0); //cout.tie(0);
      return 0;
  }();
  ```

  This will slightly increase IO speed (but maybe cost a little more memory).

