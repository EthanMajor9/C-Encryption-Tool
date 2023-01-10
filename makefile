#
# this makefile will compile and and all source
# found in the "MyApp" directory.  This represents a sample
# development directory structure and project
# 
# =======================================================
#                  MyApp Example
# =======================================================
# FINAL BINARY Target
./bin/myApp : ./obj/myApp.o ./obj/getUserInput.o
	cc ./obj/myApp.o ./obj/getUserInput.o -o ./bin/myApp
#
# =======================================================
#                     Dependencies
# =======================================================                     
./obj/myApp.o : ./src/myApp.c ./inc/getUserInput.h
	cc -g -c ./src/myApp.c -o ./obj/myApp.o

./obj/getUserInput.o : ./src/getUserInput.c ./inc/getUserInput.h
	cc -g -c ./src/getUserInput.c -o ./obj/getUserInput.o

#
# =======================================================
# Other targets
# =======================================================                     
all : ./bin/myApp

clean:
	rm -f ./bin/*
	rm -f ./obj/*.o
	


