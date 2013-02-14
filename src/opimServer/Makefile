all:
	g++ -I/usr/include/libxml2 -lxml2 -lpthread -lsqlitewrapped -lsqlite3 -o server server.cpp main.cpp Client.cpp convo.cpp ../helpers/helpers.cpp ../opim/opim.cpp ../delegateThread/delegateThread.cpp 
clean:
	@rm -f server
