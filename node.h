#include <map>
#include <string>
#include <memory>
#include <vector>

#ifndef NODE_H
#define NODE_H

class Node{
    int noOfChildren = 0;
    bool isLeaf = false; 
    std::map<char, std::unique_ptr<Node> > children;

    public: 
    int getNoOfChildren();
    bool getIsLeaf();
    std::vector<std::string> getSuggestions(std::string s, std::string acc);
    void insert(std::string str); 
    bool canResolve(std::string str); 
    std::string resolveStr(std::string str, std::string res);
    Node(); 
};

#endif
