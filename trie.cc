#include <utility>
#include <queue> 
#include <memory>
#include <sstream>
#include "trie.h"

Trie::Trie(std::vector<std::string> pool){
    for(std::string &s: pool){
        insert(s); 
    }
}

void Trie::addToPool(std::vector<std::string> &pool){
    for(std::string &s: pool){
        insert(s);
    }
}

void Trie::addToPool(std::string str){
    insert(str);
}

bool Trie::canResolve(std::string str){
    return parent.canResolve(str); 
}

std::string Trie::resolve(std::string str){
    return parent.resolveStr(str, ""); 
}

void Trie::insert(std::string str){
    parent.insert(str); 
}
std::vector<std::string> Trie::getSuggestions(std::string str){
    return parent.getSuggestions(str, ""); 
}

