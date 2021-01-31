/*
 * @lc app=leetcode.cn id=839 lang=cpp
 *
 * [839] 相似字符串组
 */

// @lc code=start

#include <vector>
#include <string>
using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;
    int setCount;

public:
    UnionFind(int n): parent(n), rank(n), setCount(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }

    bool setUnion(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y])
            parent[x] = y; 
        else {
            parent[y] = x;
            if (rank[x] == rank[y]) 
                ++rank[x];
        }
        --setCount;
        return true;
    }

    bool isConnected(int x, int y) {
        x = find(x);
        y = find(y);
        return x == y;
    }
};


bool isSimilar(string x, string y) {
    int cnt = 0;
    for (int i = 0; i < x.length(); ++i) {
        if (x[i] != y[i]) {
            ++cnt;
            if (cnt > 2)
                return false;
        }
    }
    return true;
}


class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        UnionFind uf(strs.size());
        for (int i = 0; i < strs.size(); i++) {
            for (int j = i + 1; j < strs.size(); j++) {
                if (!uf.isConnected(i, j)) {
                    if (isSimilar(strs[i], strs[j])) {
                        uf.setUnion(i, j);
                    }
                }
            }
        }
        return uf.setCount;
    }
};
// @lc code=end

