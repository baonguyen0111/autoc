#include <algorithm>
#include "autoc.h"


AutoC::AutoC(std::vector<std::string> pool, bool isCaseSensitive)
    : isCaseSensitive{isCaseSensitive}
{
    if (!isCaseSensitive){
        for (auto &str: pool){
            std::transform(str.begin(), str.end(), str.begin(), ::tolower); 
        }
    }
    trie = std::make_unique<Trie>(pool);
}

AutoC::AutoC(bool isCaseSensitive): isCaseSensitive {isCaseSensitive}{
    trie = std::make_unique<Trie>(std::vector<std::string>(0)); 
}

void AutoC::addToPool(std::vector<std::string> pool){
    if(!isCaseSensitive){
        for(auto &str: pool){
            std::transform(str.begin(), str.end(), str.begin(), ::tolower); 
        }
    }
    trie->addToPool(pool); 
}

void AutoC::addToPool(std::string word){
    if(isCaseSensitive){
        std::transform(word.begin(), word.end(), word.begin(), ::tolower); 
    }
    trie->addToPool(word); 
}

bool AutoC::canResolve(std::string str){
    return trie->canResolve(str);
}

std::string AutoC::resolve(std::string str){
    return trie->resolve(str); 
}

std::vector<std::string> AutoC::getSuggestions(std::string str){
    return trie->getSuggestions(str);
}

