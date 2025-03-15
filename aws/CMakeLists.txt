   cmake_minimum_required(VERSION 3.10)
   project(aws-c-app)

   # Find the AWS SDK
   find_package(AWSSDK REQUIRED COMPONENTS s3)

   # Create the executable
   add_executable(${PROJECT_NAME} main.cpp)

   # Link against AWS SDK libraries
   target_link_libraries(${PROJECT_NAME} ${AWSSDK_LINK_LIBRARIES})