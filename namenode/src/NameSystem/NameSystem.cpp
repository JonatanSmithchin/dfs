//
// Created by 刘骁 on 2023/5/13.
//

#include "NameSystem.h"
#include "sstream"

using namespace std;

bool NameSystem::resolvePath(const string& path) {
    //分割处理文件路径
    stringstream ss(path);
    char c = '/';
    vector<string> results;
    string s;
    while (getline(ss, s, c)) {
        results.push_back(s);
    }
    //判断是否为Inode child
    INode *node = root;
    for (int i = 0; i < results.size(); i++) {
        if (node->isDir()) {
            auto *dir = dynamic_cast<INodeDir *>(node);
            INode *child = dir->getChild(results[i]);
            if (child == nullptr) {
                return false;
            }
            node = child;
        } else {
            return false;
        }
    }
    return true;
}

void NameSystem::addFile(INode* f) {
    if(resolvePath(f->getFullPathName())){

    }
}

void NameSystem::appendFile(const string &path) {
    if (resolvePath(path)) {

    }
}

bool NameSystem::releaseLease(Lease* lease, const string& path)
{

    return false;
}
