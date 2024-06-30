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
    #install boost lib here 
    libboost-all-dev \ 
    #install gtest lib here 
    libgtest-dev \
    libgmock-dev \
    libprotobuf-dev \
    protobuf-compiler libprotoc-dev libgoogle-perftools-dev \
    libc-ares-dev libcurl4-openssl-dev \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory to Muduo source
WORKDIR /app/muduo

# Entry point
CMD ["/bin/bash"]

