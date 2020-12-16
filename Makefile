src = $(wildcard src/*.cpp)  
obj = $(patsubst %.cpp, %.o, $(src))  
target = main  
CXX = g++ 

$(target): $(obj)
	$(CXX) $(obj) -o $(target) 	

%.o: %.cpp
	$(CXX) -c $< -o $@ 

.PHONY: clean  
clean:  
	rm -rf $(obj) $(target) 
