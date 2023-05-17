//
// Created by 刘骁 on 2023/4/10.
//

#include "DatanodeInfo.h"

long DatanodeInfo::getCapacity() const {
    return capacity;
}

void DatanodeInfo::setCapacity(long capacity) {
    DatanodeInfo::capacity = capacity;
}

long DatanodeInfo::getUsed() const {
    return used;
}

void DatanodeInfo::setUsed(long used) {
    DatanodeInfo::used = used;
}

long DatanodeInfo::getRemained() const {
    return remained;
}

void DatanodeInfo::setRemained(long remained) {
    DatanodeInfo::remained = remained;
}

time_t DatanodeInfo::getLastUpdated() const {
    return lastUpdated;
}

void DatanodeInfo::setLastUpdated(time_t lastUpdated) {
    DatanodeInfo::lastUpdated = lastUpdated;
}

int DatanodeInfo::getXceiverNum() const {
    return XceiverNum;
}

void DatanodeInfo::setXceiverNum(int xceiverNum) {
    XceiverNum = xceiverNum;
}

const string &DatanodeInfo::getLocation() const {
    return location;
}

void DatanodeInfo::setLocation(const string &location) {
    DatanodeInfo::location = location;
}

const string &DatanodeInfo::getVersion() const {
    return version;
}

void DatanodeInfo::setVersion(const string &version) {
    DatanodeInfo::version = version;
}

DatanodeInfo::State DatanodeInfo::getNodeState() const {
    return nodeState;
}

void DatanodeInfo::setNodeState(DatanodeInfo::State nodeState) {
    DatanodeInfo::nodeState = nodeState;
}
