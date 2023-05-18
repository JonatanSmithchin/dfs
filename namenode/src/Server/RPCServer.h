#pragma once
#ifndef RPCSERVER_H
#define RPCSERVER_H
#include<iostream>
#include<string>
#include<grpcpp/grpcpp.h>
#include<string>
#include"../../../proto/ClientNamenode.grpc.pb.h"
#include"../../../proto/dfs.pb.h"
#include"../NameSystem/NameSystem.h"


class ClientNamenodeServiceImpl final :public ClientService::Service {
private:
	NameSystem nameSystem;
public:
	grpc::Status getBlockLocation(grpc::ServerContext* context, const GetBlockLocationsRequest& request, GetBlockLocationResponse* response);

	grpc::Status GetServerDefaults(grpc::ServerContext* context, const GetServerDefaultsRequest& request, GetServerDefaultsResponse* response);

	grpc::Status Create(grpc::ServerContext* context, const CreateRequest& request, CreateResponse* response);

	grpc::Status Append(grpc::ServerContext* context, const AppendRequest& request, AppendResponse* response);

	grpc::Status Rename(grpc::ServerContext* context, const RenameRequest& request, RenameResponse* response);

	grpc::Status Delete(grpc::ServerContext* context, const DeleteRequest& request, DeleteResponse* response);

	grpc::Status SetOwner(grpc::ServerContext* context, const SetOwnerRequest& request, SetOwnerResponse* response);

	grpc::Status SetPermission(grpc::ServerContext* context, const SetPermissionRequest& request, SetPermissionResponse* response);

	grpc::Status mkdir(grpc::ServerContext* context, const mkdirRequest& request, mkdirResponse* response);

	grpc::Status Listing(grpc::ServerContext* context, const GetListingRequest& request, GetListingResponse* response);

	grpc::Status RenewLease(grpc::ServerContext* context, const RenewLeaseRequest& request, RenewLeaseResponse* response);
};

class RPCServer {
public:
	void RunServer();
};
#endif