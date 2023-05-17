#include "BlockIndexHash.h"
BlockIndexHash::BlockIndexHash() :BlockIndex() {
	son = NULL;
}
BlockIndexHash::BlockIndexHash(string blockid, int Size, int GenerationTimeStamp) :BlockIndex(blockid, Size, GenerationTimeStamp) {
	son = NULL;
}

bool BlockIndexHash::insert(string DataNodeID, string name) {
    return false;
}

bool BlockIndexHash::remove(string name) {
    return false;
}

BlockIndexRBTree *BlockIndexHash::checkRBTreeRoot() {
    return nullptr;
}

bool BlockIndexHash::createRBTreeRoot(string DataNodeID, string name) {
    return false;
}

int BlockIndexHash::inquire(string name) {
    return 0;
}

string BlockIndexHash::inquireALL(string name) {
    return std::string();
}
