src = $(wildcard src/*.cpp)  
obj = $(patsubst %.cpp, %.o, $(src))  
#obj = $(src:%.c=%.o)  
target = main  
CXX = g++ 

$(target): $(obj)
	$(CXX) $(obj) -o $(target) 	

%.o: %.c  
	$(CXX) -c $< -o $@  

.PHONY: clean  
clean:  
	rm -rf $(obj) $(target) 
