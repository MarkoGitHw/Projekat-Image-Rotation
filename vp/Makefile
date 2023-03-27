CC = g++ -lsystemc

.PHONY: clean
.DEFAULT_GOAL := main_d

main_d: main.o vp.o hardware.o cpu.o memory.o interconnect.o
	@$(CC) main.o hardware.o cpu.o vp.o memory.o interconnect.o -o main_d  

main.o: main.cpp vp.cpp vp.hpp
	@$(CC) -c main.cpp 
	@echo "Compiling main.cpp"

vp.o: vp.cpp vp.hpp common.hpp cpu.cpp cpu.hpp hardware.cpp hardware.hpp vp_address.hpp memory.hpp memory.cpp
	@$(CC) -c vp.cpp 
	@echo "Compiling vp.cpp"

hardware.o: hardware.cpp common.hpp hardware.hpp vp_address.hpp
	@$(CC) -c hardware.cpp 
	@echo "Compiling hardware.cpp"

cpu.o: cpu.hpp cpu.cpp vp_address.hpp hardware.cpp hardware.hpp common.hpp
	@$(CC) -c cpu.cpp 
	@echo "Compiling cpu.cpp"

memory.o: memory.cpp memory.hpp common.hpp vp_address.hpp cpu.hpp cpu.cpp hardware.hpp hardware.cpp
	@$(CC) -c memory.cpp 
	@echo "Compiling memory.cpp"

interconnect.o: interconnect.cpp interconnect.hpp common.hpp cpu.cpp cpu.hpp hardware.cpp hardware.hpp vp_address.hpp memory.hpp memory.cpp
	@$(CC) -c interconnect.cpp
	@echo "Compiling interconnect.cpp"

clean:
	@rm *.o main_d
	@echo "Deleting all .o files"
