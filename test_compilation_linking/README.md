# 了解编译和链接

g++ main.cpp --std=c++11 -o hello  
./hello  
编译hello.cpp文件  
采用c++11标准  
输出可执行文件，且名字为hello  
执行名为hello的可执行文件    


g++ main.cpp factorial.cpp printhello.cpp -o main  
./main  
编译链接这三个cpp文件，执行可执行文件main  


g++ main.cpp -c  
只编译main.cpp文件，不链接，这样会产生.o文件  


g++ *.o -o main  
链接所有的.o文件，输出为main可执行文件  


rm main.exe  
删除可执行文件main  
也可以执行 rm *.exe 删除所有的.exe文件  
