#!/bin/sh

# check whether there are already same image's container running 
CONTAINER_ID=$(docker ps | grep muduo-dev-env | awk '{print $1}')

if [ -z "$CONTAINER_ID" ]; then
  # no duplicate image container running setup a new container 
  docker run -d --name muduo_dev_env_container \
    -v /Users/emma/workspace/Learn-Network-in-CPP:/workspace \
    muduo-dev-env

  # wait new container setup   
  sleep 10

  # retrieve container id 
  CONTAINER_ID=$(docker ps | grep muduo-dev-env | awk '{print $1}')
  
  if [ -z "$CONTAINER_ID" ]; then
    echo "Failed to start the container."
    exit 1
  fi
else
  echo "Found running container with the same image: $CONTAINER_ID"
fi

# login contianer 
docker exec -it $CONTAINER_ID /bin/bash
