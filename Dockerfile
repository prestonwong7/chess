# Use official GCC imagge with CMake installed
FROM gcc:latest

# Install CMake and Ninja
RUN apt-get update && \
    apt-get install -y cmake ninja-build && \
    rm -rf /var/lib/apt/lists/*
# Set the working directory
WORKDIR /app

# Copy the source code into the container
COPY . .

# Configure the project using CMake
RUN cmake -G Ninja . && ninja

# Run the executable
CMD ["./Chess"]