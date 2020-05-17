# CSC3022F Assignment 5

## Instructions

## Performing PCA

1. Compile with `make`
2. Execute clusterer located inside bin folder eg. `bin/pca`

The result are saved in a text file in the root folder, output.txt.
The input data can be modified using the data.txt file also found in the root folder

# Testing

1. Compile with `make`
2. Run `make test`

## Project structure

### main.cpp

Driver file for starting and showing the results for PCA

### pca_math.h

Includes methods for calculating the covariance matrix and displaying the results

### pca_math.cpp

Implementation for covariance calculation methods

### loader.h

Utility for loading values for data.txt file into a matrix

### loader.cpp

Implementation for load_files method

### test.cpp

Unit tests