#include "node.h"


Node::Node(): noOfChildren{0}{} 

int Node::getNoOfChildren(){
    return noOfChildren;
}

bool Node::getIsLeaf(){
    return isLeaf;
}

std::vector<std::string> Node::getSuggestions(std::string s, std::string acc){
    std::vector<std::string> res; 
    if(s != ""){
        if(children.count(s[0])){
            return res; 
        }
        return children[s[0]] ->getSuggestions(s.substr(1), acc + s[0]); 
    }

    if(isLeaf){
        res.emplace_back(acc);
    }

    for(auto &c: children){
        std::vector<std::string> tmp = children[c.first]->getSuggestions("", acc + c.first);
        for (auto &t: tmp){
            res.emplace_back(t); 
        }
    }
    return res; 

}

void Node::insert(std::string str){
    if(str.length() == 0){
        isLeaf = true; 
        return; 
    }

    noOfChildren++; 
    if(children.count(str[0]) == 0){
        children[str[0]] = std::make_unique<Node>(); 
    }
    
    if(str.length() == 1){
        children[str[0]]->insert(""); 
    } else{
        children[str[0]]->insert(str.substr(1)); 
    }
} 
bool Node::canResolve(std::string str){
    if(str.length() == 0 && ( isLeaf || noOfChildren == 1)){
        return true; 
    }

    if(str.length() == 0 || children.count(str[0]) == 0){
        return false; 
    }

    return children[str[0]]->canResolve(str.substr(1)); 
} 
std::string Node::resolveStr(std::string str, std::string res){
    if(str == ""){
        for(auto &c:children){
            char cChar = c.first;
            return children[cChar]->resolveStr(str.substr(1), res + cChar); 
        }
        return res; 
    }

    return children[str[0]]->resolveStr(str.substr(1), res + str[0]); 
}


