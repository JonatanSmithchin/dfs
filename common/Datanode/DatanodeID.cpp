//
// Created by 刘骁 on 2023/4/10.
//

#include "DatanodeID.h"

const string &DatanodeID::getIpAddr() const {
    return ipAddr;
}

void DatanodeID::setIpAddr(const string &ipAddr) {
    DatanodeID::ipAddr = ipAddr;
}

const string &DatanodeID::getHostName() const {
    return hostName;
}

void DatanodeID::setHostName(const string &hostName) {
    DatanodeID::hostName = hostName;
}

const string &DatanodeID::getId() const {
    return ID;
}

void DatanodeID::setId(const string &id) {
    ID = id;
}

int DatanodeID::getTransPort() const {
    return TransPort;
}

void DatanodeID::setTransPort(int transPort) {
    TransPort = transPort;
}

int DatanodeID::getInfoPort() const {
    return infoPort;
}

void DatanodeID::setInfoPort(int infoPort) {
    DatanodeID::infoPort = infoPort;
}

int DatanodeID::getRpcPort() const {
    return RPCPort;
}

void DatanodeID::setRpcPort(int rpcPort) {
    RPCPort = rpcPort;
}
