#include "BlockManager.h"

bool BlockManager::clearHashTable(vector<BlockIndexHash *> *tablePoint) {
    return false;
}

bool BlockManager::initHashTable(int HashTableSize, int HashKey) {
    return false;
}

bool BlockManager::addBlock(string DatanodeID, string Name) {
    return false;
}

bool BlockManager::removeBlock(string Name) {
    return false;
}

int BlockManager::getBlock(string Name) {
    return 0;
}

bool BlockManager::refrashBlock(int Datanode, string Name) {
    return false;
}

bool BlockManager::refrashHashTable() {
    return false;
}

string BlockManager::getBlockALL(string name) {
    return std::string();
}

BlockManager::BlockManager(int HashTableSize, int HashKey) {
    hashTableSize = HashTableSize;
    hashKey = HashKey;
    if (!initHashTable(hashTableSize, hashKey)) {
        ///////////////////////////////////////////////////////////////////////////
    }
}
