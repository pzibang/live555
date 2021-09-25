CXX = g++



SRC = $(shell find ./ -name *.cpp)

TAR = live555RtspServerDemo

CXX_FLAGS = -g -I/usr/local/include/BasicUsageEnvironment -I/usr/local/include/UsageEnvironment\
			-I/usr/local/include/groupsock -I/usr/local/include/liveMedia\
			-DNO_OPENSSL=1


LD_FLAGS = -lliveMedia -lBasicUsageEnvironment -lgroupsock -lUsageEnvironment -lpthread -lx264 -lasound -lfaac

all:
	$(CXX) -o $(TAR) $(SRC) $(CXX_FLAGS) $(LD_FLAGS)