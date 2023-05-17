# CMakeList.txt: dfsForCPP 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("dfsForCPP")

include("D://vcpkg//vcpkg//scripts//buildsystems//vcpkg.cmake")

find_package(gRPC CONFIG REQUIRED)

find_package(protobuf CONFIG REQUIRED)

add_executable (namenode "src/Server/RPCServer.cpp" "proto/helloworld.grpc.pb.cc" "proto/helloworld.pb.cc")

add_executable (client "src/client.cpp" "proto/helloworld.grpc.pb.cc" "proto/helloworld.pb.cc")

target_link_libraries(namenode PRIVATE gRPC::grpc++ gRPC::grpc++_reflection gRPC::gpr gRPC::grpc gRPC::grpc++ protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)

target_link_libraries(client PRIVATE gRPC::grpc++ gRPC::grpc++_reflection gRPC::gpr gRPC::grpc gRPC::grpc++ protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)

# 将源代码添加到此项目的可执行文件。
add_executable (dfsForCPP "dfsForCPP.cpp" "dfsForCPP.h")

# TODO: 如有需要，请添加测试并安装目标。
