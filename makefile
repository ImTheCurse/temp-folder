CXXFLAGS = -std=c++17
CC = g++
OBJS = main.cpp src/TempFolder.cpp 

all: ${OBJS}
	${CC} ${OBJS}  -o tfold ${CXXFLAGS} 

debug: ${OBJS}
	${CC} ${OBJS}  -o tfold ${CXXFLAGS} -g 

clean:
	rm *.o tfold
