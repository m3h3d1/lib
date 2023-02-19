#pragma once

template <class T> struct FenwickTree { // 1 indexed
    int n;
    vector<T> data;
    FenwickTree() : n(0) {}
    FenwickTree(int n) : n(n), data(n+1, 0) {}

    // a[id] += x
    void add(int id, T x) {
        for (int i = id; i <= n; i += i & -i) {
            data[i] += x;
        }
    }
    void range_add(int l, int r, T val) {
        add(l, val);
        add(r + 1, -val);
    }

    // [1, r]
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