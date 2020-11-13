src = $(wildcard ../IR/*.cpp)  
obj = $(patsubst %.cpp, %.o, $(src))  
#obj = $(src:%.c=%.o)  
target = main  
CC = g++ 

$(target): $(obj)  
	$(CC) $(obj) -o $(target)  

%.o: %.c  
	$(CC) -c $< -o $@  

.PHONY: clean  
clean:  
    rm -rf $(obj) $(target) 