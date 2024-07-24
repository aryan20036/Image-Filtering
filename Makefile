# Makefile

NVCC = nvcc
CXX = g++

CUDAFLAGS = -arch=sm_30
CXXFLAGS = -std=c++11

image_filtering.o: image_filtering.cu
    $(NVCC) $(CUDAFLAGS) -c $< -o $@

main.o: main.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

image_filtering: image_filtering.o main.o
    $(NVCC) $(CUDAFLAGS) $^ -o $@

clean:
    rm -f *.o image_filtering