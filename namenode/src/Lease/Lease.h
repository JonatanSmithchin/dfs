//
// Created by 刘骁 on 2023/4/23.
//

#ifndef DFSFORCPP_LEASE_H
#define DFSFORCPP_LEASE_H

#include <string>
#include <set>
#include <chrono>

using  std::string;
using std::set;
using namespace std::chrono;

class Lease {
private:
    string holder;
    time_t lastUpdated;
    set<string> paths;
public:
    set<string> getPath();
    void renew();
    bool expiredSoftLimit();
    bool expiredHardLimit();
};


#endif //DFSFORCPP_LEASE_H
