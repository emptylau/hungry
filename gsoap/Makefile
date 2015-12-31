TARGET=webserver

PWD=$(shell pwd)
GSOAP_ROOT=/opt/gsoap-2.8/gsoap

INCLUDE=-I$(PWD) \
		-I$(PWD)/gen_src/ \
		-I$(GSOAP_ROOT)/import
SRC=gen_src/soapC.cpp gen_src/soapServer.cpp webserver.cpp gen_src/stdsoap2.cpp
CC=g++
CC_FLAG=-g 

$(TARGET): $(SRC)
	$(CC) -o $(PWD)/bin/$(TARGET) \
		$(INCLUDE) $(CC_FLAG) \
		$(SRC)

.PHONY: clean
clean:
	rm *.o $(TARGET)
