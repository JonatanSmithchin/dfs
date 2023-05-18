//
// Created by 刘骁 on 2023/5/13.
//

#ifndef DFSFORCPP_NAMESYSTEM_H
#define DFSFORCPP_NAMESYSTEM_H

#include "../INode/INodeDir.h"
#include "../INode/INodeFile.h"
#include "../Lease/Lease.h"
#include "../../../proto/ClientNamenode.pb.h"
#include "../../../common/Block/BlockInfo.h"
#include "FsPermission.h"
#include "../Block/BlockManager.h"
#include "../Lease/LeaseManager.h"

using namespace ClientNamenode;
class LeaseManager;
class NameSystem {
private:
    INodeDir* root;
    BlockManager* blockManager;
    LeaseManager* leaseManager;
    bool construceFile(const string& src);
    bool resolvePath(const string& path);
    INode* findParent(const string& path);
    bool checkPermission(FsPermission permission, FsAction op);
public:
    NameSystem();
    INode* addFile(const CreateRequest& request);
    LocatedBlock* appendFile(const AppendRequest& request);
    bool releaseLease(const RenewLeaseRequest& request);
    void rename(const RenameRequest& request);
    void setOwner(const string& src, const string& username, const string& groupname);
    void close();
};


#endif //DFSFORCPP_NAMESYSTEM_H
