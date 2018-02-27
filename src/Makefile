all: pi
strip: main.c
	gcc -g -o strip main.c -lwiringPi -lwiringPiDev -lpthread -lm -lcrypt -lrt -L/usr/local/lib -I/usr/local/include -I.
pi: main.c
	arm-linux-gnueabihf-gcc -g -Wimplicit-function-declaration -o piStrip.elf main.c -lwiringPi -lwiringPiDev -lpthread -lm -lcrypt -lrt -L/usr/local/libarm -I/usr/local/includearm -I.
