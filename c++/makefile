CXX = c++
CXXFLAGS = -Wall -Wextra -g -std=c++11 -O0 -Iinclude -Isrc
LDFLAGS =
OBJ = $(OBJFOLDER)/Currency.o $(OBJFOLDER)/CurrencyCalculator.o $(OBJFOLDER)/CurrencyPair.o $(OBJFOLDER)/CurrencyPairParser.o $(OBJFOLDER)/DirectedMatrixGraph.o $(OBJFOLDER)/UndirectedMatrixGraph.o $(OBJFOLDER)/Graph.o $(OBJFOLDER)/GraphManager.o

OBJFOLDER = build
SRCFOLDER = src
INCFOLDER = include
EXECUTABLE = exec
LIBRARY = libproject.a
LIBRARYDIR = ../nodejs/lib

all: $(LIBRARY)

libproject.a: $(OBJ)
	 ar rc $(LIBRARYDIR)/$(LIBRARY) $(OBJ)

# Commented sections are for compiling the src into an executable
# all: $(EXECUTABLE)

# $(EXECUTABLE) : $(OBJ)
# 	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJ) -o $@

# $(OBJFOLDER)/main.o : $(SRCFOLDER)/main.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJFOLDER)/DirectedListGraph.o: $(INCFOLDER)/DirectedListGraph.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJFOLDER)/DirectedMatrixGraph.o: $(INCFOLDER)/DirectedMatrixGraph.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJFOLDER)/UndirectedListGraph.o: $(INCFOLDER)/UndirectedListGraph.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJFOLDER)/UndirectedMatrixGraph.o: $(INCFOLDER)/UndirectedMatrixGraph.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJFOLDER)/Graph.o: $(INCFOLDER)/Graph.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJFOLDER)/%.o: $(SRCFOLDER)/%.cpp $(INCFOLDER)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY:
clean:
	@rm build/*.o $(LIBRARYDIR)/$(LIBRARY)
