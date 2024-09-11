# ## VERSION 1
# hello: main.cpp printhello.cpp factorial.cpp
# 	g++ -o hello main.cpp printhello.cpp factorial.cpp
# ## 上一行 g++前面要有一个tab
# ## 在终端中make命令如果报错了，要去mingw64/bin文件下找到mingw32-make.exe将其改名为make.exe




# ## VERSION 2
# CXX = g++
# TARGET = hello
# OBJ = main.o printhello.o factorial.o

# $(TARGET): $(OBJ)
# 	$(CXX) -o $(TARGET) $(OBJ)

# main.o: main.cpp
# 	$(CXX) -c main.cpp

# printhello.o: printhello.cpp
# 	$(CXX) -c printhello.cpp

# factorial.o: factorial.cpp
# 	$(CXX) -c factorial.cpp




# # VERSION 3
# CXX = g++
# TARGET = hello
# OBJ = main.o printhello.o factorial.o
 
# CXXLAGS = -c -Wall
 
# $(TARGET): $(OBJ)
# 	$(CXX) -o $@ $^
 
# %.o: %.cpp
# 	$(CXX) $(CXXLAGS) $< -o $@
 
# .PHONY: clean
 
# clean:
# 	rm -f *.o $(TARGET)




# # VERSION 4
# CXX = g++
# TARGET = hello
# # 所有当前目录的.cpp文件都放在SRC里面
# SRC = $(wildcard *.cpp)
# # 把SRC里面的.cpp文件替换为.o文件
# OBJ = $(patsubst %.cpp, %.o,$(SRC))
 
# CXXLAGS = -c -Wall
 
# $(TARGET): $(OBJ)
# 	$(CXX) -o $@ $^
 
# %.o: %.cpp
# 	$(CXX) $(CXXLAGS) $< -o $@
 
# .PHONY: clean
# clean:
# 	rm -f *.o $(TARGET)