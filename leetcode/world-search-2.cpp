#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    struct Trie {
        int count;
        Trie* children[26];
        Trie() : count(0) {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };
    
    int n, m;
    unordered_set<string> result;
    
    void add(Trie* cur, string w) {
        for (int i = 0; i < w.length(); i++) {
            if (cur->children[w[i]-'a'] == nullptr)
                cur->children[w[i]-'a'] = new Trie();
            cur = cur->children[w[i]-'a'];
        }
        cur->count++;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, Trie* cur, string res) {
        if (i < 0 || i >= n || j < 0 || j >= m) return;
        if (board[i][j] == ' ') return;
        cur = cur->children[board[i][j]-'a'];
        if (cur == nullptr)
            return;
        res += board[i][j];
        if (cur->count > 0)
            result.insert(res);
        char tmp = board[i][j];
        board[i][j] = ' ';
        dfs(board, i+1, j, cur, res);
        dfs(board, i-1, j, cur, res);
        dfs(board, i, j+1, cur, res);
        dfs(board, i, j-1, cur, res);
        board[i][j] = tmp;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        for (auto& w : words)
            add(root, w);
        
        n = board.size();
        m = n > 0 ? board[0].size() : 0;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                dfs(board, i, j, root, "");
            }
        return vector<string>(result.begin(), result.end());
    }
};
