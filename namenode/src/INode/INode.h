//
// Created by 刘骁 on 2023/4/10.
//

#ifndef DFSFORCPP_INODE_H
#define DFSFORCPP_INODE_H

#include "string"
#include "ctime"
#include "../NameSystem/FsPermission.h"

using std::string;

class INode {
private:
    int id;
    string name;
    INode *parent;
    string fullPathName;
    string userName;
    string groupName;
    FsPermission fsPermission;
    time_t modifiedTime;
    time_t accessTime;
public:
    const string &getFullPathName() const;

    void setFullPathName(const string &fullPathName);

    int getId() const;

    void setId(int id);

    const string &getName() const;

    void setName(const string &name);

    INode *getParent() const;

    void setParent(INode *parent);

    const string &getUserName() const;

    const string &getGroupName() const;

    const FsPermission& getFsPermission() const;

    time_t getModifiedTime() const;

    time_t getAccessTime() const;

    virtual bool isFile()=0;

    virtual bool isDir()=0;

    virtual bool isRoot()=0;

    virtual bool isSymlink()=0;
};


#endif //DFSFORCPP_INODE_H
