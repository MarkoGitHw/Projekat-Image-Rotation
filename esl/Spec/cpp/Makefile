CC = g++
CFLAGS = -std=c++11 `pkg-config --cflags --libs opencv4`

spec: main.o ImageProcessing.o FileOps.o
	@$(CC) main.o ImageProcessing.o FileOps.o -o spec $(CFLAGS)
	@echo "Making executable target file \n"

main.o: main.cpp  common.hpp FileOps.hpp ImageProcessing.hpp
	@$(CC) -c  main.cpp $(CFLAGS)
	@echo "Making main object file \n"

ImageProcessing.o: ImageProcessing.cpp ImageProcessing.hpp common.hpp
	@$(CC) -c  ImageProcessing.cpp $(CFLAGS)
	@echo "Making ImageProcessing object file \n"

FileOps.o: FileOps.cpp FileOps.hpp common.hpp
	@$(CC) -c  FileOps.cpp $(CFLAGS)
	@echo "Making FileOps object file \n"

run:
	@make spec
	@echo "Running executable target \n"
	@./spec  $(Direction) $(Degree)  

clean:
	@rm *.o spec
	@echo "Deleating all .o files \n"
