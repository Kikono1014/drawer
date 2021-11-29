.PHONY = all run install

OUT = drawer
COMPILER = g++
FILES = ./Frame/Frame.cpp ./Drawer/Drawer.cpp ./Drawer/Sprite.cpp
LIBS = ./TextStyle/TextStyle.cpp

all:
	${COMPILER} ${LIBS} ./main.cpp ${FILES} -o ${OUT}

run: all
	./${OUT}

install: all
	cp ./${OUT} /usr/bin

clear:
	rm ./${OUT}
