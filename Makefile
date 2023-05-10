CXX		 	 = g++
CXXFLAGS 	 = -Wall -std=c++11
TARGETMAIN	 = sqrt
SRCMAIN	 	 = src/libs/square_root.cpp src/headlands.cpp
TARGETTEST	 = test
SRCTEST	 	 = src/libs/square_root.cpp src/tests/UnitTest.cpp src/tests/square_root_test.cpp

.SUFFIXES: .cpp

$(TARGETMAIN): $(SRCMAIN)
	$(CXX) $(CXXFLAGS) $(SRCMAIN) -o $@ 

$(TARGETTEST): $(SRCTEST)
	$(CXX) $(CXXFLAGS) $(SRCTEST) -o $@ 

.PHONY: all clean

all: $(TARGETMAIN) $(TARGETTEST)

clean:
	rm -f $(TARGETMAIN) $(TARGETTEST) 
