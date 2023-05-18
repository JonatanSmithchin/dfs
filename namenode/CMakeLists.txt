# CMakeList.txt: namenode 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("namenode")

include("D://vcpkg//vcpkg//scripts//buildsystems//vcpkg.cmake")

find_package(gRPC CONFIG REQUIRED)

find_package(protobuf CONFIG REQUIRED)

# 将源代码添加到此项目的可执行文件。
add_executable (namenode "namenode.h" "namenode.cpp" "src/Server/RPCServer.cpp" "../proto/ClientNamenode.grpc.pb.cc" "../proto/ClientNamenode.grpc.pb.h" "../proto/ClientNamenode.pb.cc" "../proto/ClientNamenode.pb.h" "../proto/dfs.pb.cc" "../proto/dfs.pb.h"  "src/Lease/Lease.cpp" "src/Lease/Lease.h" "src/Lease/LeaseManager.cpp" "src/Lease/LeaseManager.h" "src/NameSystem/NameSystem.cpp" "src/NameSystem/NameSystem.h" "src/INode/INode.cpp" "src/INode/INode.h" "src/INode/INodeDir.cpp" "src/INode/INodeDir.h" "src/INode/INodeFile.cpp" "src/INode/INodeFile.h" "src/INode/INodeReference.cpp" "src/INode/INodeReference.h" "src/INode/INodeSymlink.cpp" "src/INode/INodeSymlink.h" "src/Datanode/DatanodeDescriptor.cpp" "src/Datanode/DatanodeDescriptor.h" "src/Block/BlockIndex.cpp" "src/Block/BlockIndex.h" "src/Block/BlockIndexClashPoint.cpp" "src/Block/BlockIndexClashPoint.h" "src/Block/BlockIndexHash.cpp" "src/Block/BlockIndexHash.h" "src/Block/BlockIndexRBTree.cpp" "src/Block/BlockIndexRBTree.h" "src/Block/BlockManager.cpp" "src/Block/BlockManager.h" "../common" "src/NameSystem/FsPermission.h" "src/NameSystem/FsPermission.cpp" "src/Server/RPCServer.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET namenode PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(namenode PRIVATE gRPC::grpc++ gRPC::grpc++_reflection gRPC::gpr gRPC::grpc gRPC::grpc++ protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)
# TODO: 如有需要，请添加测试并安装目标。
