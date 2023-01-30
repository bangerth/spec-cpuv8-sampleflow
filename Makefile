SRC = $(shell find dealii/source -name '*.cc' ; \
              find dealii/bundled/boost-1.70.0/libs -name '*.cpp' ; \
              echo mcmc-laplace.cc)
OBJ = $(subst .cpp,.o,$(subst .cc,.o,$(SRC)))

INCLUDEDIRS = -Idealii/include \
              -Idealii/bundled/boost-1.70.0/include \
              -ISampleFlow/include

%.o : %.cc
	c++ -std=c++14 -Wno-deprecated-declarations -c $< -o $@ $(INCLUDEDIRS) -I..

%.o : %.cpp
	c++ -std=c++14 -Wno-deprecated-declarations -c $< -o $@ $(INCLUDEDIRS) -I..

sample-flow: $(OBJ)
	c++ -o $@ $(OBJ) -lpthread

clean:
	-rm -f $(OBJ) sample-flow
