
tests: option3.hpp option3.cpp tests.cpp
	clang++ -std=c++11 -Wall -I/opt/homebrew/opt/criterion/include -L/opt/homebrew/opt/criterion/lib -o tests -lcriterion option3.cpp tests.cpp