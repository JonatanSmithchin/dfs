//
// Created by 刘骁 on 2023/4/10.
//

#include "INode.h"

int INode::getId() const {
    return id;
}

void INode::setId(int id) {
    INode::id = id;
}

const string &INode::getName() const {
    return name;
}

void INode::setName(const string &name) {
    INode::name = name;
}

INode *INode::getParent() const {
    return parent;
}

void INode::setParent(INode *parent) {
    INode::parent = parent;
}

const string &INode::getFullPathName() const {
    return fullPathName;
}

void INode::setFullPathName(const string &fullPathName) {
    INode::fullPathName = fullPathName;
}

const string &INode::getUserName() const {
    return userName;
}

const string &INode::getGroupName() const {
    return groupName;
}

short INode::getFsPermission() const {
    return fsPermission;
}

time_t INode::getModifiedTime() const {
    return modifiedTime;
}

time_t INode::getAccessTime() const {
    return accessTime;
}

bool INode::isFile() {
    return false;
}

bool INode::isDir() {
    return false;
}

bool INode::isRoot() {
    return false;
}

bool INode::isSymlink() {
    return false;
}
