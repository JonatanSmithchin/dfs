//
// Created by 刘骁 on 2023/4/23.
//

#ifndef DFSFORCPP_LEASEMANAGER_H
#define DFSFORCPP_LEASEMANAGER_H
#include "Lease.h"
#include "map"
#include "../NameSystem/NameSystem.h"
using namespace std;
class LeaseManager {
private:
    std::map<string,Lease> leases;
    std::set<Lease> sortedLeases;
    NameSystem fsnameSystem;
    class Monitor{
    public:
        void run(LeaseManager* leaseManager);
    }monitor;
public:
    Lease addLease(Lease* lease);
    void renewLease(Lease* lease);
    bool checkLeases();
    void removeLease(Lease* lease,const string& src);
    void startMonitor();
    void stopMonitor();
};
#endif //DFSFORCPP_LEASEMANAGER_H
