all: pi
strip: main.c
	gcc -g -o strip main.c -lwiringPi -lwiringPiDev -lpthread -lm -lcrypt -lrt -I.
pi: main.c
	arm-linux-gnueabihf-gcc -g -Wimplicit-function-declaration -o piStrip.elf main.c -lwiringPi -lwiringPiDev -lpthread -lm -lcrypt -lrt -L../wiringPiArm/ -I../wiringPiArm -I.
