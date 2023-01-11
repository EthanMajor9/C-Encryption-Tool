#
# this makefile will compile and and all source
# found in the "MyApp" directory.  This represents a sample
# development directory structure and project
# 
# =======================================================
#                  MyApp Example
# =======================================================
# FINAL BINARY Target
./bin/cryptoMagic : ./obj/main.o ./obj/decrypt.o ./obj/encrypt.o
	cc ./obj/main.o ./obj/decrypt.o ./obj/encrypt.o -o ./bin/cryptoMagic
#
# =======================================================
#                     Dependencies
# =======================================================      
./obj/main.o : ./src/main.c ./inc/globals.h
	cc -g -c ./src/main.c -o ./obj/main.o
	
./obj/decrypt.o : ./src/decrypt.c ./inc/globals.h
	cc -g -c ./src/decrypt.c -o ./obj/decrypt.o
	
./obj/encrypt.o : ./src/encrypt.c ./inc/globals.h
	cc -g -c ./src/encrypt.c -o ./obj/encrypt.o
	
#
# =======================================================
# Other targets
# =======================================================                     
all : ./bin/cryptoMagic

clean:
	rm -f ./bin/*
	rm -f ./obj/*.o
	


