#include"RPCServer.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using std::string;
using namespace ClientNamenode;

Status ClientNamenodeServiceImpl::getBlockLocation(ServerContext* context, const GetBlockLocationsRequest& request, GetBlockLocationResponse* response) {

}

Status ClientNamenodeServiceImpl::GetServerDefaults(ServerContext* context, const GetServerDefaultsRequest& request, GetServerDefaultsResponse* response) {

}

Status ClientNamenodeServiceImpl::Create(ServerContext* context, const CreateRequest& request, CreateResponse* response) {
	INode* node =  nameSystem.addFile(request);
	FileStatus fs;
	response->set_allocated_status(&fs);
	return Status::OK;
}

Status ClientNamenodeServiceImpl::Append(ServerContext* context, const AppendRequest& request, AppendResponse* response) {
	LocatedBlock* lb = nameSystem.appendFile(request);
	response->set_allocated_block(lb);
	return Status::OK;
}

Status ClientNamenodeServiceImpl::Rename(ServerContext* context, const RenameRequest& request, RenameResponse* response) {
	nameSystem.rename(request);
}

Status ClientNamenodeServiceImpl::Delete(ServerContext* context, const DeleteRequest& request, DeleteResponse* response) {
		
}

Status ClientNamenodeServiceImpl::SetOwner(ServerContext* context, const SetOwnerRequest& request,SetOwnerResponse* response){
		

}

Status ClientNamenodeServiceImpl::SetPermission(ServerContext* context, const SetPermissionRequest& request, SetPermissionResponse* response){
}

Status ClientNamenodeServiceImpl::mkdir(ServerContext* context, const mkdirRequest& request, mkdirResponse* response) {

}

Status ClientNamenodeServiceImpl::Listing(ServerContext* context, const GetListingRequest& request, GetListingResponse* response){
}

Status ClientNamenodeServiceImpl::RenewLease(ServerContext* context, const RenewLeaseRequest& request, RenewLeaseResponse* response) {

}



void RPCServer::RunServer() {
	string server_address("0.0.0.0:4491");
	ClientNamenodeServiceImpl ClientService;

	ServerBuilder builder;

	builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

	builder.RegisterService(&ClientService);

	std::unique_ptr<Server> server(builder.BuildAndStart());
	std::cout << "server listeningn on " << server_address << std::endl;
	server->Wait();
}