.PHONY : all clean
CC = g++
all :\
	output/builder\
	output/singleton\
	output/factorymethod\
	output/abstractfactory\


	

output/builder : builder.cpp
	$(CC) $^ -o $@
output/singleton : singleton.cpp
	$(CC) $^ -o $@
output/factorymethod : factorymethod.cpp
	$(CC) $^ -o $@
output/abstractfactory : abstractfactory.cpp
	$(CC) $^ -o $@
clean: 
	rm -rf output/*
