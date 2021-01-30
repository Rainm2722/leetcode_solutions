#include <vector>
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
};