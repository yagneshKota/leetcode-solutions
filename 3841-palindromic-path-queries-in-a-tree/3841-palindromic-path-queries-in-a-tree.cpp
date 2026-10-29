
class Solution {
    int LOG, timer;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, bit, mask;
    
    void update(int i, int val, int n) {
        for (; i <= n; i += i & -i)
            bit[i] ^= val;
    }

    int query(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

    void rangeUpdate(int l, int r, int val, int n) {
        update(l, val, n);
        if (r <= n)
            update(r, val, n);
    }

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[0][u] = p;

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer + 1;
    }

    bool isAncestor(int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }

    int lca(int u, int v) {
        if (isAncestor(u, v)) return u;
        if (isAncestor(v, u)) return v;

        for (int k = LOG - 1; k >= 0; k--) {
            if (!isAncestor(up[k][u], v))
                u = up[k][u];
        }

        return up[0][u];
    }

public:
    vector<bool> palindromePath(
        int n, vector<vector<int>>& edges,
        string s, vector<string>& queries
    ) {
        auto suneravilo = make_tuple(n, edges, s, queries);

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        timer = 0;
        adj.assign(n, {});
        up.assign(LOG, vector<int>(n, 0));
        tin.resize(n);
        tout.resize(n);
        depth.assign(n, 0);
        mask.resize(n);
        bit.assign(n + 2, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, 0);

        for (int k = 1; k < LOG; k++) {
            for (int u = 0; u < n; u++) {
                up[k][u] = up[k - 1][up[k - 1][u]];
            }
        }

        for (int u = 0; u < n; u++) {
            mask[u] = 1 << (s[u] - 'a');
            rangeUpdate(tin[u], tout[u], mask[u], n);
        }

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string op;
            int u;
            ss >> op >> u;

            if (op == "update") {
                char c;
                ss >> c;

                int newMask = 1 << (c - 'a');
                int diff = mask[u] ^ newMask;

                rangeUpdate(tin[u], tout[u], diff, n);
                mask[u] = newMask;
                s[u] = c;
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);
                int pathMask =
                    query(tin[u]) ^ query(tin[v]) ^ mask[w];

                ans.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return ans;
    }
};
