#include <string>
#include <unordered_map>

class TrieNode {
 public:
  // Initialize your data structure here.
  TrieNode() : is_word(false) {
  }

  bool is_word;
  unordered_map<char, TrieNode*> children;
};

class Trie {
 public:
  Trie() {
    new TrieNode();
  }

  // Inserts a word into the trie.
  void insert(std::string word) {
    if (word.size() <= 0) return;
    TrieNode* node = root;
    for (size_t i = 0; i < word.size(); ++i) {
      if (node->children.find(word[i]) == node->children.end()) {
        node->children[word[i]] = new TrieNode();
      } 
      node = node->children[word[i]];
    }
    node->is_word = true;
  }

  // Returns if the word is in the trie.
  bool search(std::string word) {
    return retrieve(word, true);
  }

  // Returns if the word is in the trie
  // that starts with the given prefix.
  bool startsWith(std::string prefix) {
    return retrieve(prefix, false);
  }

 private:
  inline bool retrieve(const std::string& key, bool is_word) {
    if (key.size() <= 0) return false;
    TrieNode* node = root;
    for (size_t i = 0; i < key.size(); ++i) {
      if (node->children.find(key[i]) == node->children.end()) {
        return false;
      }
      node = node->children[key[i]];
    }
    return is_word ? node->is_word : true;
  } 

  TrieNode* root;
};
// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("something");
// trie.search("key");
