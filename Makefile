all: cmake_project	cmake_test

cmake_project:
	@echo "###Begin Generating Makefiles###"
	@echo "Creating build directory..."
	mkdir -p ./build
	@echo "Entering build directory and executing CMake..."
	cd ./build; \
	cmake .. -G"Eclipse CDT4 - Unix Makefiles"
	@echo "###CMake Complete - Makefiles generated###"
	@echo "###Particle Explosion Build Complete###"

	cd build && make

cmake_run:
	make
	cd build && ./SDL2Test


clean:
	@rm -frv ./build 
