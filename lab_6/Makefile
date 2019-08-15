#Derek Wu
#djw4yv 
#8AM LAB
CXX=clang++ -O2 -std=c++11 $(CXXFLAGS)
DEBUG=-Wall -g

WordPuzzle : wordPuzzle.o timer.o hashTable.o
	$(CXX) $(DEBUG) wordPuzzle.o timer.o hashTable.o
	@echo "Ready to find those words" 
	
wordPuzzle.o: wordPuzzle.cpp timer.h timer.cpp hashTable.cpp hashTable.h
	$(CXX) -c wordPuzzle.cpp

hashTable.o: hashTable.cpp hashTable.h
	$(CXX) -c hashTable.cpp
	
timer.o: timer.h timer.cpp
	$(CXX) -c timer.cpp

	
clean:
	-rm *.o WordPuzzle
