struct DSU {
    vector<int> par;
    int cc; // connected components
    DSU(int n): par(n, -1), cc(n) { }

    // get representive component (uses path compression)
    int get(int x) { return par[x] < 0 ? x : par[x] = get(par[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -par[get(x)]; }

    int groups() { return cc; } // number of groups

    int leader(int v) const {
        assert(0 <= a && a < _n);
        while (par[v] > -1) v = par[v];
        return v;
    }

    void unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return;
        cc--;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y]; par[y] = x;
    }
};