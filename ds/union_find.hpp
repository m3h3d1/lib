struct DSU {
    vector<int> e;
    int cc; // connected components
    DSU(int n): e(n, -1), cc(n) { }

    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    int groups() { return cc; } // number of groups

    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        cc--;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x; return true;
    }
};