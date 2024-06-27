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
    libgtest-dev \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory in the container
WORKDIR /app

# Clone the Muduo repository
#RUN git clone https://github.com/chenshuo/muduo.git

# Set the working directory to Muduo source
WORKDIR /app/muduo

# Build Muduo
#RUN ./build.sh

# Run tests
RUN ctest --output-on-failure

# Entry point
CMD ["/bin/bash"]

