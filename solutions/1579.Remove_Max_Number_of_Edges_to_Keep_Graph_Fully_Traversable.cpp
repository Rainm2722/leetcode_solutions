/*
 * @lc app=leetcode.cn id=1579 lang=cpp
 *
 * [1579] 保证图可完全遍历
 */

// @lc code=start
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

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int> >& edges) {
        int ans = 0;
        UnionFind alice(n), bob(n);
        
        // common edges
        for (int i = 0; i < edges.size(); i++){
            if (edges[i][0] == 3){
                if (!alice.setUnion(edges[i][1] - 1, edges[i][2] - 1))
                    ++ans;
                else
                    bob.setUnion(edges[i][1] - 1, edges[i][2] - 1);
            }
        }

        for (int i = 0; i < edges.size(); i++) {
            // Alice's edge
            if (edges[i][0] == 1) {
                if (!alice.setUnion(edges[i][1] - 1, edges[i][2] - 1))
                    ++ans;
            }
            // Bob's edge
            if (edges[i][0] == 2) {
                if (!bob.setUnion(edges[i][1] - 1, edges[i][2] - 1))
                    ++ans;
            }
        }

        if (alice.setCount > 1 || bob.setCount > 1)
            return -1;
        return ans;
    }
};
// @lc code=end

