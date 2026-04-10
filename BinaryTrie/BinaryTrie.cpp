struct BinaryTrie {
    static const int B = 30; // لـ 1e9 تقريبًا

    struct Node {
        int child[2];
        int cnt;
        Node() {
            child[0] = child[1] = 0;
            cnt = 0;
        }
    };

    vector<Node> trie;

    BinaryTrie(int maxNodes = 2000000) {
        trie.reserve(maxNodes);
        trie.push_back(Node()); // root = 0
    }

    void insert(int x, int val) {
        int v = 0;
        for (int i = B; i >= 0; i--) {
            int b = (x >> i) & 1;

            if (!trie[v].child[b]) {
                trie[v].child[b] = trie.size();
                trie.push_back(Node());
            }

            v = trie[v].child[b];
            trie[v].cnt += val;
        }
    }

    int maxXor(int x) {
        int v = 0, ans = 0;

        for (int i = B; i >= 0; i--) {
            int b = (x >> i) & 1;
            int want = b ^ 1;

            if (trie[v].child[want] &&
                trie[trie[v].child[want]].cnt > 0) {
                ans |= (1 << i);
                v = trie[v].child[want];
            } else {
                v = trie[v].child[b];
            }
        }

        return ans;
    }
};
