#include<iostream>
#include<string>
#include<grpcpp/grpcpp.h>
#include<string>
#include"../../../proto/ClientNamenode.grpc.pb.h"
#include"../../../proto/dfs.pb.h"
#include"../NameSystem/NameSystem.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using std::string;
using namespace ClientNamenode;

class ClientNamenodeServiceImpl final :public ClientService::Service {
private:
	NameSystem nameSystem;
public:
	Status getBlockLocation(ServerContext* context, const GetBlockLocationsRequest& request, const GetBlockLocationResponse& response) {

	}

	Status GetServerDefaults(ServerContext* context, const GetServerDefaultsRequest& request, const GetServerDefaultsResponse& response) {

	}

	Status Create(ServerContext* context, const CreateRequest& request, const CreateResponse& response) {
		nameSystem.addFile(request);
	}

	Status Append(ServerContext* context, const AppendRequest& request, AppendResponse* response) {
		BlockInfo* b = nameSystem.appendFile(request);
		LocatedBlock lb;
		response->set_allocated_block(&lb);
		return Status::OK;
	}

	Status Rename(ServerContext* context, const RenameRequest& request, const RenameResponse& response) {

	}

	Status Delete(ServerContext* context, const DeleteRequest& request, const DeleteResponse& response) {

	}

	Status SetOwner(ServerContext* context, const SetOwnerRequest& request,const SetOwnerResponse& response){
		

	}

	Status SetPermission(ServerContext* context, const SetPermissionRequest& request, const SetPermissionResponse& response){
	}

	Status SetOwner(ServerContext* context, const SetOwnerRequest& request, const SetOwnerResponse& response) {

	}

	Status mkdir(ServerContext* context, const mkdirRequest& request, const mkdirResponse& response) {

	}

	Status Listing(ServerContext* context, const GetListingRequest& request, const GetListingResponse& response){
	}

	Status RenewLease(ServerContext* context, const RenewLeaseRequest& request, const RenewLeaseResponse& response) {

	}
};

void RunServer() {
	string server_address("0.0.0.0:4491");
	ClientNamenodeServiceImpl ClientService;

	ServerBuilder builder;

	builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

	builder.RegisterService(&ClientService);

	std::unique_ptr<Server> server(builder.BuildAndStart());
	std::cout << "server listeningn on " << server_address << std::endl;
	server->Wait();
}