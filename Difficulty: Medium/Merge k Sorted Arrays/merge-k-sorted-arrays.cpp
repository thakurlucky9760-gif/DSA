class Solution {
public:

    class Node {
    public:
        int value;
        int row;
        int col;

        Node(int v, int i, int j) {
            value = v;
            row = i;
            col = j;
        }
    };

    struct Compare {
        bool operator()(const Node &a, const Node &b) {
            return a.value > b.value;   // min heap
        }
    };

    vector<int> mergeArrays(vector<vector<int>> &a) {

        vector<int> res;

        int n = a.size();
        int m = a[0].size();

        priority_queue<Node, vector<Node>, Compare> pq;

        // Har row ka first element heap mein
        for(int i = 0; i < n; i++) {
            pq.push(Node(a[i][0], i, 0));
        }

        while(!pq.empty()) {

            Node temp = pq.top();
            pq.pop();

            res.push_back(temp.value);

            int row = temp.row;
            int col = temp.col;

            // Agar current row mein next element hai
            if(col < m - 1) {
                pq.push(Node(a[row][col + 1], row, col + 1));
            }
        }

        return res;
    }
};