//
// Created by 刘骁 on 2023/4/10.
//

#include "INodeDir.h"

bool INodeDir::addChild(const INode &child) {
    children.push_back(child);
    return true;
}

bool INodeDir::removeChild(const string &childName) {
    for each (INode* c in children)
    {
        if (childName.compare(c->getName) == 0) {
            children.erase(c);
            return true;
        }
    }
    return false;
}

bool INodeDir::replaceChild(const INode &child) {
    for each (INode * c in children)
    {
        if (child.getName().compare(c->getName) == 0) {
            children.erase(c);
            children.push_back(child);
            return true;
        }
    }
    return false;
}

bool INodeDir::clearChildren() {
    return false;
}

INode* INodeDir::getChild(const string &childName) {
    for each (INode* c in children)
    {
        if (childName.compare(c->getName()) == 0) {
            return c;
        }
    }
    return nullptr;
}

bool INodeDir::isFile() {
    return false;
}

bool INodeDir::isDir() {
    return true;
}

bool INodeDir::isRoot() {
    if(getParent()== nullptr){
        return true;
    } else{
        return false;
    }
}

bool INodeDir::isSymlink() {
    return false;
}
