#include <string> 
#include <memory> 
#include <vector>
#include "trie.h"

#ifndef AUTOC_H
#define AUTOC_H

class AutoC{
    std::unique_ptr<Trie> trie;
    bool isCaseSensitive; 

    public: 
    AutoC(bool isCaseSensitive = true); 
    AutoC(std::vector<std::string> pool, bool isCaseSensitive = true);
    void addToPool(std::vector<std::string> wordset); 
    void addToPool(std::string str); 
    std::vector<std::string> getSuggestions(std::string str); 
    bool canResolve(std::string str);
    std::string resolve(std::string str); 
};
#endif
