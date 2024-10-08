class Trie {
private:
    struct Node{
        bool isLeaf = false;
        bool isEnd = false;
        vector<Node*> children = vector<Node*>(26, NULL);
    };
public:
    Node* root;
    Trie() {
        root = new Node;
    }
    
    void insert(string word) {
        Node* node = root;
        for(auto &it : word){
            if(node->children[it-'a'] == NULL){
                node->children[it-'a'] = new Node;
            }
            node = node->children[it-'a'];
        }
        node->isLeaf = true;
        node->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(auto &it : word){
            if(node->children[it-'a'] == NULL){
                return false;
            }
            node = node->children[it-'a'];
        }
        return node->isEnd && node->isLeaf;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(auto &it: prefix) {
            if(node->children[it-'a'] == NULL){
                return false;
            }
            node = node->children[it-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */