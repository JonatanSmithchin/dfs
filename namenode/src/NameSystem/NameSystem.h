//
// Created by 刘骁 on 2023/5/13.
//

#ifndef DFSFORCPP_NAMESYSTEM_H
#define DFSFORCPP_NAMESYSTEM_H

#include "../INode/INodeDir.h"
#include "../Lease/Lease.h"
#include "../../../proto/ClientNamenode.pb.h"

using namespace ClientNamenode;

class NameSystem {
private:
    INodeDir* root;
    bool construceFile(const string& src,int permission);
public:
    bool resolvePath(const string& path);
    void addFile(const CreateRequest& request);
    void appendFile(const AppendRequest& request);
    bool releaseLease(const RenewLeaseRequest& request);
};


#endif //DFSFORCPP_NAMESYSTEM_H
