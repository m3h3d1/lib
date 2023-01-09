#pragma once

struct RollingHash2D {
    static constexpr int M = 2;
    static constexpr long long MODS[M] = {999999937, 1000000007};
    static constexpr long long BASE_H = 9973;
    static constexpr long long BASE_W = 10007;
    vector<vector<long long>> hash[M];
    vector<long long> powH[M], powW[M];
    int h,w;
    RollingHash2D() {}
    RollingHash2D(const vector<string>& str) { init(str); }
    void init(const vector<string>& str) {
        h = str.size(), w = str[0].size();
        for(int k = 0; k < M; k++) {
            powH[k].resize(h + 1, 1);
            powW[k].resize(w + 1, 1);
            hash[k].resize(h + 1, vector<long long>(w + 1, 0));
            for(int i = 0; i < h; i++) {
                powH[k][i + 1] = powH[k][i] * BASE_H % MODS[k];
                for(int j = 0; j < w; j++) {
                    hash[k][i + 1][j + 1] = (hash[k][i + 1][j] * BASE_W % MODS[k] + str[i][j]) % MODS[k];
                }
            }
            for(int j = 0; j < w; j++) {
                powW[k][j + 1] = powW[k][j] * BASE_W % MODS[k];
                for(int i = 0; i < h; i++) {
                    hash[k][i + 1][j + 1] = (hash[k][i][j + 1] * BASE_H % MODS[k] + hash[k][i + 1][j + 1]) % MODS[k];
                }
            }
        }
    }

    // get hash [l1,r1) * [l2,r2)
    long long get(int l1, int r1, int l2, int r2, int k) {
        long long res = 0;
        res += hash[k][r1][r2];
        res -= hash[k][l1][r2] * powH[k][r1 - l1] % MODS[k];
        if(res < 0) res += MODS[k];
        res -= hash[k][r1][l2] * powW[k][r2 - l2] % MODS[k];
        if(res < 0) res += MODS[k];
        res += hash[k][l1][l2] * powH[k][r1 - l1] % MODS[k] * powW[k][r2 - l2] % MODS[k];
        if(res >= MODS[k]) res -= MODS[k];
        return res;
    }
};

bool match(RollingHash2D& RH, int L1, int R1, int L2, int R2, RollingHash2D& rh, int l1, int r1, int l2, int r2) {
    bool res = true;
    for (int k = 0; k < RollingHash2D::M; k++) {
        res &= RH.get(L1, R1, L2, R2, k) == rh.get(l1, r1, l2, r2, k);
    }
    return res;
}
