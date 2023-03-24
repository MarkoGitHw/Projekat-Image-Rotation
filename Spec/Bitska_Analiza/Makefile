CC = g++ -lsystemc
CFLAGS = `pkg-config --cflags --libs opencv4`

spec: main.o ImageProcessing.o FileOps.o
	@$(CC) main.o ImageProcessing.o FileOps.o -o spec $(CFLAGS)
	@echo "Making executable target file "

main.o: main.cpp  common.hpp FileOps.hpp ImageProcessing.hpp
	@$(CC) -c  main.cpp $(CFLAGS)
	@echo "Making main object file "

ImageProcessing.o: ImageProcessing.cpp ImageProcessing.hpp common.hpp
	@$(CC) -c  ImageProcessing.cpp $(CFLAGS)
	@echo "Making ImageProcessing object file "

FileOps.o: FileOps.cpp FileOps.hpp common.hpp
	@$(CC) -c  FileOps.cpp $(CFLAGS)
	@echo "Making FileOps object file "

run:
	@make spec
	@echo "Running executable target "
	@./spec  $(Direction) $(Degree) $(Boundry) $(Pathi) $(Patho)


clean:
	@rm *.o spec
	@echo "Deleating all .o files "