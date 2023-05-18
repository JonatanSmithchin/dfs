// namenode.cpp: 定义应用程序的入口点。
//

#include "namenode.h"

using namespace std;

int main()
{
	namenode nn = namenode();
	nn.join();
}

void namenode::loadNameSystem() {
	nameSystem = &NameSystem();
}

RPCServer* namenode::createRpcServer() {

};

void namenode::initialize()
{
	rpcServer = createRpcServer();
	loadNameSystem();
}

namenode::namenode()
{
	initialize();
}

void namenode::join()
{
}
