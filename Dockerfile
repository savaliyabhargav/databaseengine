# Dockerfile
FROM ubuntu:24.04

# Install only essential C++ build tools
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    clang \
    gdb \
    vim \
    git \
    && apt-get clean

WORKDIR /app
CMD ["/bin/bash"]
