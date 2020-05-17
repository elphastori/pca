pca test_bin: main.o utilities.o
	g++ -o bin/pca bin/main.o bin/utilities.o -std=c++11
	# g++ -o bin/test_bin bin/test.o bin/utilities.o -std=c++11
main.o: main.cpp 
	@mkdir -p bin
	g++ -c -o bin/main.o main.cpp -std=c++11 -I ./eigen-3.3.7/
utilities.o: utilities.cpp
	@mkdir -p bin
	g++ -c -o bin/utilities.o utilities.cpp -std=c++11  -I ./eigen-3.3.7/
# test.o: test.cpp
# 	@mkdir -p bin
# 	g++ -c -o bin/test.o test.cpp -std=c++11 -I ./eigen-3.3.7/
test:
	bin/test_bin
clean:
	rm -rf bin