class Solution {
public:

    struct cmp {
        bool operator()(pair<int,char>& a, pair<int,char>& b) {

            if(a.first != b.first) {
                return a.first < b.first;
            }

            return a.second < b.second;
        }
    };

    string reorganizeString(string s) {

        priority_queue<pair<int,char>,
                       vector<pair<int,char>>,
                       cmp> pq;

        unordered_map<char,int> f;

        int n = s.size();

        // Frequency count
        for(int i = 0; i < n; i++) {
            f[s[i]]++;
        }

        // Push frequency + character into heap
        for(auto i : f) {

            char cha = i.first;
            int freq = i.second;

            pair<int,char> p{freq, cha};

            pq.push(p);
        }

        string res = "";
        int seat = 0;

        while(!pq.empty()) {

            pair<int,char> p = pq.top();
            pq.pop();

            // Current character is different from previous
            if(seat == 0 || res[seat-1] != p.second) {

                res.push_back(p.second);
                seat++;

                p.first--;

                if(p.first > 0) {
                    pq.push(p);
                }
            }

            // Current character is same as previous
            else {

                // No other character available
                if(pq.empty()) {
                    return "";
                }

                // Take second most frequent character
                pair<int,char> p1 = pq.top();
                pq.pop();

                res.push_back(p1.second);
                seat++;

                p1.first--;

                if(p1.first > 0) {
                    pq.push(p1);
                }

                // Put first character back
                pq.push(p);
            }
        }

        return res;
    }
};