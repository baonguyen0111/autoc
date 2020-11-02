#include <string> 
#include <memory>
#include "node.h"

#ifndef TRIE_H
#define TRIE_H

class Trie{
    Node parent;
    void insert(std::string str);

    public: 
    Trie(std::vector<std::string> pool); 
    void addToPool(std::vector<std::string> &pool); 
    void addToPool(std::string str); 
    bool canResolve(std::string str); 
    std::string resolve(std::string str);
    std::vector<std::string> getSuggestions(std::string str); 
};
#endif

