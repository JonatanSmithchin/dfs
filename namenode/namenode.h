// namenode.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once
#ifndef NAMENODE_H
#define NAMENODE_H
#include <iostream>
#include "src/NameSystem/NameSystem.h"
#include "src/Server/RPCServer.h"
class namenode {
private:
	NameSystem* nameSystem;
	RPCServer* rpcServer;
	void loadNameSystem();
	RPCServer* createRpcServer();
	void initialize();
public:
	namenode();
	void join();
};

// TODO: 在此处引用程序需要的其他标头。
#endif