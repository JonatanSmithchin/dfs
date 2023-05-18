//
// Created by 刘骁 on 2023/5/13.
//

#include "NameSystem.h"
#include "sstream"

using namespace std;



NameSystem:: NameSystem() {

}

bool NameSystem::construceFile(const string& src)
{
    INode* parent = findParent(src);
    if (parent != nullptr) {
        if (checkPermission(parent->getFsPermission(),FsAction::WRITE)) {
            auto* dir = dynamic_cast<INodeDir*>(parent);
            INodeFile *f = new INodeFile();//构造函数
            dir->addChild(*f);//构建元数据
            //TODO:选择namenode返回给client
        }
    }
    return false;
}

bool NameSystem::resolvePath(const string& path)
{
    return false;
}

INode* NameSystem::findParent(const string& path) {
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
    for (int i = 0; i < results.size()-1; i++) {
        if (node->isDir()) {
            auto *dir = dynamic_cast<INodeDir *>(node);
            INode *child = dir->getChild(results[i]);
            if (child == nullptr) {
                return nullptr;
            }
            node = child;
        } else {
            return nullptr;
        }
    }
    return node;
}

bool NameSystem::checkPermission(FsPermission permission,FsAction op)
{
    //解析permission
    return false;
}

INode* NameSystem::addFile(const CreateRequest& request) {
    
}

LocatedBlock* NameSystem::appendFile(const AppendRequest& request) {
    LocatedBlock* lb;
    return lb;
}

bool NameSystem::releaseLease(const RenewLeaseRequest& request)
{

    return false;
}

void NameSystem::rename(const RenameRequest& request)
{
    const string& dst = request.dst();
    if (resolvePath(request.src())) {

    }
    else {

    }
}

void NameSystem::setOwner(const string& src, const string& username, const string& groupname)
{
}

void NameSystem::close()
{
}
