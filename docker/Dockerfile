# Use an official Ubuntu as a parent image
FROM ubuntu:20.04

# Set environment variables to non-interactive
ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update && \
    apt-get install -y \
    g++ \
    cmake \
    make \
    git \
    tree \
    libprotobuf-dev protobuf-compiler libprotoc-dev libgoogle-perftools-dev \
    libc-ares-dev libcurl4-openssl-dev \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory to Muduo source
WORKDIR /app/muduo

# init git submodules like boost and gtest 
RUN git submodule update --init --recursive 

# build boost 
RUN cd thirdparty/boost && ./bootstrap.sh && ./b2 

# build google test 
RUN cd thirdparty/googletest && mkdir build && cd build && cmake .. && make && make install

# Entry point
CMD ["/bin/bash"]

