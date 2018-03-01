test:
	g++ -std=c++11 mach0/mach0.cpp -o build/mach
	g++ -std=c++11 zeta0/zeta0.cpp -o build/zeta
	./build/zeta 3
	./build/mach 3

utest:
	g++ -std=c++11 mach0/tests.cpp -o build/mach_tests
	g++ -std=c++11 zeta0/tests.cpp -o build/zeta_tests
	./build/zeta_tests
	./build/mach_tests