#include <stdio.h>
#include <string.h>

#include <vector>
#include <string>

static const int kMaxChars = 26;

class TrieNode {
 public:
  TrieNode(std::string s) : is_word_(false), word_(s){
    memset(children_, 0, sizeof(children_));
  }
  TrieNode* & operator[] (char ch) {
    return children_[(ch - 'a') % kMaxChars];
  }
  TrieNode* & operator[] (int index) {
    return children_[index % kMaxChars];
  }

  std::string word_;
  bool is_word_;

 private:
  TrieNode* children_[kMaxChars];
};

class TrieTree {
 public:
  TrieTree() : root_(new TrieNode("")) {}
  ~TrieTree() { FreeTree(root_); }
  TrieNode* root() { return root_; }
  void AddWord(std::string& s) {
    TrieNode* node = root_;
    std::string t;
    for (size_t i = 0; i < s.size(); ++i) {
      t += s[i];
      if ((*node)[s[i]] == NULL) {
        (*node)[s[i]] = new TrieNode(t);
      }
      node = (*node)[s[i]];
    }
    node->is_word_ = true;
  }

 private:
  void FreeTree(TrieNode* node) {
    for (int i = 0; i < kMaxChars; ++i) {
      if ((*node)[i] != NULL) {
        FreeTree((*node)[i]);
      }
    }
    delete node;
  }

  TrieNode* root_;
};

class Solution {
 public:
  std::vector<std::string> FindWords(std::vector<std::vector<char> >& board,
                                     std::vector<std::string>& words) {
    TrieTree t;
    for (size_t i = 0; i < words.size(); ++i) {
      t.AddWord(words[i]);
    }

    std::vector<std::string> result;
    for (size_t i = 0; i < board.size(); ++i) {
      for (size_t j = 0; j < board[i].size(); ++j) {
        FindWordsHelper(t.root(), board, i, j, result);
      }
    }
    return result;
  }

  void FindWordsHelper(TrieNode* root,
                       std::vector<std::vector<char> >& board, int i, int j, 
                       std::vector<std::string>& result) {
    if (i < 0 || i >= board.size() ||
        j < 0 || j >= board[i].size() ||
        board[i][j] == '#') {
      return;
    }

    char c = board[i][j];
    root = (*root)[c];
    if (root == NULL) return;
   
    if (root->is_word_ == true) {
      result.push_back(root->word_);
      root->is_word_ = false;
    }

    board[i][j] = '#';
    
    FindWordsHelper(root, board, i, j - 1, result);
    FindWordsHelper(root, board, i, j + 1, result);
    FindWordsHelper(root, board, i + 1, j, result);
    FindWordsHelper(root, board, i - 1, j, result);

    board[i][j] = c;
  }
}; 

int main() {
  return 0;
}
