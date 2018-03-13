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
	mpirun -np 8 ./build/zeta1 1000000
	mpirun -np 8 ./build/mach1 1000000

six:
	mpiCC -std=c++11 mach1/mach1.cpp -o build/mach1
	mpiCC -std=c++11 zeta1/zeta1.cpp -o build/zeta1
	g++ -std=c++11 mach0/tests.cpp -o build/mach_tests
	g++ -std=c++11 zeta0/tests.cpp -o build/zeta_tests
	@echo "\n\nZeta single:"
	./build/zeta_tests e 1000


	@echo "\n\nZeta multi:"
	mpirun -np 2 ./build/zeta1 1000
	mpirun -np 8 ./build/zeta1 1000


	@echo "\n\nMach single:"
	./build/mach_tests e 1000


	@echo "\n\nMach multi:"
	mpirun -np 2 ./build/mach1 1000
	mpirun -np 8 ./build/mach1 1000

seven:
	mpiCC -std=c++11 reduc/reduc.cpp -o build/reduc
	mpirun -np 2 ./build/reduc 1000
	mpirun -np 8 ./build/reduc 1000

eight:
	g++ -std=c++11 mach0/tests.cpp -o build/mach_tests
	g++ -std=c++11 zeta0/tests.cpp -o build/zeta_tests
	mpiCC -std=c++11 -fopenmp mach2/mach2.cpp -o build/mach2
	mpiCC -std=c++11 -fopenmp zeta2/zeta2.cpp -o build/zeta2

	@echo "\n\nZeta single:"
	./build/zeta_tests e 1000


	@echo "\n\nZeta multi:"
	./build/zeta2 1000 2
	./build/zeta2 1000 8


	@echo "\n\nMach single:"
	./build/mach_tests e 1000


	@echo "\n\nMach multi:"
	./build/mach2 1000 2
	./build/mach2 1000 8

nine:
	mpiCC -std=c++11 -fopenmp hybrid/mach_hybrid.cpp -o build/mach_hybrid
	mpiCC -std=c++11 -fopenmp hybrid/zeta_hybrid.cpp -o build/zeta_hybrid
	mpirun -np 4 ./build/mach_hybrid 10000 8
	mpirun -np 4 ./build/zeta_hybrid 10000 8

ten:
	mpiCC -std=c++11 -fopenmp hybrid/mach_hybrid.cpp -o build/mach_hybrid
	mpiCC -std=c++11 mach1/mach1.cpp -o build/mach1
	mpirun -np 2 ./build/mach_hybrid 10000 8
	mpirun -np 4 ./build/mach1 10000
