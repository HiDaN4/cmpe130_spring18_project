CXX = g++-7
CXXFLAGS = -Wall -Wextra -g -std=c++11 -O0 -Iinclude
LDFLAGS =
OBJ = $(OBJFOLDER)/main.o $(OBJFOLDER)/Currency.o $(OBJFOLDER)/CurrencyPair.o $(OBJFOLDER)/CurrencyPairParser.o

OBJFOLDER = build
SRCFOLDER = src
INCFOLDER = include
EXECUTABLE = exec

all: $(EXECUTABLE)

$(EXECUTABLE) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJ) -o $@

$(OBJFOLDER)/main.o : $(SRCFOLDER)/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJFOLDER)/%.o: $(SRCFOLDER)/%.cpp $(INCFOLDER)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY:
clean:
	@rm build/*.o $(EXECUTABLE)
