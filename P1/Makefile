test:
	g++ -std=c++11 mach0/mach0.cpp -o mach0/temp
	g++ -std=c++11 zeta0/zeta0.cpp -o zeta0/temp
	./zeta0/temp 3
	./mach0/temp 3

utest:
	g++ -std=c++11 zeta0/zeta0.cpp -o zeta0/temp
	g++ -std=c++11 zeta0/tests.cpp -o zeta0/tests
	./zeta0/tests