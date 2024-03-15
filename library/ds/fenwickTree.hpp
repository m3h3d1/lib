#pragma once

template <class T> struct FenwickTree { // 1 indexed
    int n;
    vector<T> data;
    FenwickTree() : n(0) {}
    FenwickTree(int n) : n(n), data(n+1, 0) {}

    // a[id] += x and all the ranges responsible for 'id', O(log(n))
    // x = i&-i => lsb(x); lsb(0b1101000) = 0b1000 = 8
    void add(int id, T x) {
        for (int i = id; i <= n; i += i & -i) {
            data[i] += x;
        }
    }
    void range_add(int l, int r, T val) {
        add(l, val);
        add(r + 1, -val);
    }

    // prefix sum from [1, r], O(log(n))
    T sum(int r) {
        T s(0);
        for (int i = r; i > 0; i -= i & -i) {
            s += data[i];
        }
        return s;
    }
    // [l, r]
    T sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
};