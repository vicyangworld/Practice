appname := main
CXX := g++
#CXXFLAGS := -Wall -g
#srcfiles := $(shell find . -maxdepth 1 -name "*.cpp")
#objects  := $(patsubst %.cpp, %.o, $(srcfiles))


objects = main.o myString.o
$(appname) : $(objects)
	$(CXX) -o $(appname) $(objects) 

main.o:myString.h
myString.o:myString.h

clean :
	rm $(appname) $(objects)
run :
	./$(appname)
