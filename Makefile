
g++ -o main main.cpp block.cpp
# Clean out your directory but keep executables with command "clean".  Gets rid 
# of files you don't need anymore
clean:
	rm -f *.o *~ *% *# .#*

# Clean out your directory including executables with command "clean-all"
clean-all: clean
	rm -f main