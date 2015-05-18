//
// Created by Ronald Liu on 18/5/15.
//
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* next[26];
    bool terminal;
    // Initialize your data structure here.
    TrieNode():next() {
        terminal = false;
        memset(next, 0, sizeof(next));
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *p = root;
        for (auto i : s)
        {
            int idx = i-'a';
            if (p->next[idx]==nullptr)
                p->next[idx] = new TrieNode();
            p = p->next[idx];
        }
        p->terminal = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *p = root;
        for (auto i : key)
        {
            int idx = i-'a';
            if (p->next[idx]==nullptr)
                return false;
            p = p->next[idx];
        }
        return p->terminal;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (auto i : prefix)
        {
            int idx = i-'a';
            if (p->next[idx]==nullptr)
                return false;
            p = p->next[idx];
        }
        return true;
    }

private:
    TrieNode* root;
};

#include <cassert>
int main()
{
    Trie trie;
    trie.insert("somestring");
    assert(!trie.search("key"));
    assert(!trie.search("some"));
    assert(trie.startsWith("some"));
    trie.insert("some");
    assert(trie.search("some"));

    return 0;
}