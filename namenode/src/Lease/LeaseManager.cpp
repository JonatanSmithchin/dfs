//
// Created by 刘骁 on 2023/4/23.
//

#include "LeaseManager.h"
#include "list"
#include "vector"

Lease LeaseManager::addLease(Lease* lease) {
    return Lease();
}

void LeaseManager::renewLease(Lease* lease) {

}

bool LeaseManager::checkLeases() {
	bool needSync = false;//是否需要互斥锁来修改租约状态

	while (sortedLeases.size()>0)
	{
		set<Lease>::iterator it = sortedLeases.begin();
		Lease oldest = *it;
		if (!oldest.expiredHardLimit())
		{
			return needSync;
		}

		list<string> removing;
		vector<string> paths;
		copy(oldest.getPath().begin(),oldest.getPath().end(), paths.begin());
		for each (string p in paths)
		{
			if (!needSync)
			{
				bool completed = nameSystem.releaseLease(&oldest,p);
				needSync = true;
			}
			//TODO:判断是否能恢复过期租约，如果不能则添加到删除list中
			removing.push_back(p);
		}

		for each (string p in removing)
		{
			removeLease(&oldest, p);
		}
	}
    return false;
}

void LeaseManager::removeLease(Lease* lease,const string& src) {

}

void LeaseManager::startMonitor() {
	monitor.run(this);
}

void LeaseManager::stopMonitor() {

}

void LeaseManager::Monitor::run(LeaseManager* leaseManager) {
	while (true)
	{
		bool needSync = false;
		if (needSync)
		{
			//log
		}
		needSync = leaseManager->checkLeases();
		//sleep for 2 sec
	}
}
