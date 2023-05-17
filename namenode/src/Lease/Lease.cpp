//
// Created by 刘骁 on 2023/4/23.
//

#include "Lease.h"

set<string> Lease::getPath()
{
    return paths;
}

void Lease::renew() {

}

bool Lease::expiredSoftLimit() {
    if (lastUpdated - time(NULL) > 1000) {
        return true;
    }
    return false;
}

bool Lease::expiredHardLimit() {
    if (lastUpdated - time(NULL) > 10000) {
        return true;
    }
    return false;
}
