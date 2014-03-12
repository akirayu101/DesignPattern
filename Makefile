.PHONY : all clean
CC = g++
all :\
	output/builder\
	output/singleton\
	output/factorymethod\
	output/abstractfactory\
	output/prototype\
	output/adapter\
	output/bridge\


	

output/builder : builder.cpp
	$(CC) $^ -o $@
output/singleton : singleton.cpp
	$(CC) $^ -o $@
output/factorymethod : factorymethod.cpp
	$(CC) $^ -o $@
output/abstractfactory : abstractfactory.cpp
	$(CC) $^ -o $@
output/prototype : prototype.cpp
	$(CC) $^ -o $@
output/adapter : adapter.cpp
	$(CC) $^ -o $@
output/bridge : bridge.cpp
	$(CC) $^ -o $@
clean: 
	rm -rf output/*
