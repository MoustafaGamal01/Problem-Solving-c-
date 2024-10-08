class Trie {
private:
    struct Node {
        vector<Node*> children;
        vector<string> suggestions;
        Node() : children(26, nullptr) {}
    };
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void Add(string str) {
        Node* node = root;
        for (auto it : str) {
            if (!node->children[it - 'a']) {
                node->children[it - 'a'] = new Node();
            }
            node = node->children[it - 'a'];
            if(node->suggestions.size() < 3){
                node->suggestions.push_back(str);
            }
        }
    }

    vector<string> WordsPfx(string s) {
        Node* node = root;
        for(auto it:s){
            if(node->children[it - 'a'] == NULL){
                return {};
            }
            node = node->children[it - 'a'];
        }
        return node->suggestions;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

        Trie trie;
        for (auto it : products) {
            trie.Add(it);
        }

        vector<vector<string>> ans;
        string str = "";
        
       for (auto it : searchWord) {
            str += it;
            vector<string> suggs = trie.WordsPfx(str);
            ans.push_back(suggs);
        }

        return ans;
    }
};
