PROGRAM=timer
CXX=clang
CXXFLAGS=-Wall -Wextra

$(PROGRAM): main.o
	$(CXX) $(CXXFLAGS) -o $@ $< -lm

main.o: main.c
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
	
clean:
	rm -f $(PROGRAM) *.o
