appname := main
CXX := g++
#CXXFLAGS := -Wall -g
#srcfiles := $(shell find . -maxdepth 1 -name "*.cpp")
#objects  := $(patsubst %.cpp, %.o, $(srcfiles))

objects = main.o ThreadBTree.o
$(appname) : $(objects)
	$(CXX) -o $(appname) $(objects) 

main.o: ThreadBTree.h ThreadBTreeNode.h
ThreadBTree.o: ThreadBTree.h ThreadBTreeNode.h

clean :
	rm $(appname) $(objects)
run :
	./$(appname)
