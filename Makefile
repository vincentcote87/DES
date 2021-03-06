# Generic Makefile
# Note. Comments are preceded with #.
# A "Makefile" allows you to compile an entire project at once.
#
# Makefile for any project
#
# Sep. 15, 2011
#

# some settings...
# use the gnu C++ compiler program, g++
CCC = g++
# list all warnings
CCCFLAGS = -Wall -g -std=c++11 -lpthread

# all is called a target, after the colon you have dependencies
# ie. "the target all is dependent on the executables
all : main

# the target <excecutable1> is dependent on the list of dependencies
# the line following  is the required executable (don't need to adjust it)
# Note: executable lines, ie. $(CCC) ..., must always begin with a tab.
# $^ = this target
# $@ = this/these dependencies

main : main.o block.o key.o round.o encrypt.o decrypt.o
	$(CCC) $(CCCFLAGS) $^ -o $@

# if there is more than one problem to do on an assignment you can compile
# all the questions at the same time
# <executable2> : <executable2> dependencies spaces between (usually .o files)
#	$(CCC) $(CCCFLAGS) $^ -o $@

# default rule compiling .cc to .o
# all .o file targets are dependent on the corresponding .cc files
# $< = the corresponding .cc file
%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<

# If you are using .h files you need to indicate that the .o file targets
# are dependent on corresponding .h files
# Ex. file.o : file.h
main.o : block.h
block.o : block.h
round.o : round.h
key.o : key.h
encrypt.o : encrypt.h
decrypt.o : decrypt.h


# Clean out your directory but keep executables with command "clean".  Gets rid 
# of files you don't need anymore
clean:
	rm -f *.o *~ *% *# .#*

# Clean out your directory including executables with command "clean-all"
clean-all: clean
	rm -f main