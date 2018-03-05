test:
	g++ -std=c++11 mach0/mach0.cpp -o build/mach
	g++ -std=c++11 zeta0/zeta0.cpp -o build/zeta
	./build/zeta 3
	./build/mach 3

utest:
	g++ -std=c++11 mach0/tests.cpp -o build/mach_tests
	g++ -std=c++11 zeta0/tests.cpp -o build/zeta_tests
	./build/zeta_tests u
	./build/mach_tests u

vtest:
	g++ -std=c++11 mach0/tests.cpp -o build/mach_tests
	g++ -std=c++11 zeta0/tests.cpp -o build/zeta_tests
	./build/zeta_tests v
	./build/mach_tests v

five:
	mpiCC -std=c++11 mach1/mach1.cpp -o build/mach1
	mpiCC -std=c++11 zeta1/zeta1.cpp -o build/zeta1
	mpirun -np 16 ./build/zeta1 1000000
	mpirun -np 8 ./build/mach1 1000

six:
	mpiCC -std=c++11 mach1/mach1.cpp -o build/mach1
	mpiCC -std=c++11 zeta1/zeta1.cpp -o build/zeta1
	g++ -std=c++11 mach0/tests.cpp -o build/mach_tests
	g++ -std=c++11 zeta0/tests.cpp -o build/zeta_tests
	echo "Zeta singel:"
	./build/zeta_tests e 1000
	echo "\n\nZeta multi:"
	mpirun -np 2 ./build/zeta1 1000
	mpirun -np 4 ./build/zeta1 1000
	mpirun -np 8 ./build/zeta1 1000
	mpirun -np 16 ./build/zeta1 1000
	mpirun -np 32 ./build/zeta1 1000
	echo "\n\nMach single:"
	./build/mach_tests e 1000
	echo "\n\nMach multi:"
	mpirun -np 2 ./build/mach1 1000
	mpirun -np 4 ./build/mach1 1000
	mpirun -np 8 ./build/mach1 1000
	mpirun -np 16 ./build/mach1 1000
	mpirun -np 32 ./build/mach1 1000
	mpirun -np 64 ./build/mach1 1000
