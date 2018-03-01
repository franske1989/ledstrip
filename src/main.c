#include <stdio.h>
#include <wiringPi.h>
#include <wiringShift.h>

#define PIN_DATA 0
#define PIN_CLOCK 14

char r[8] = {0xFF, 0x00, 0x00};
char g[8] = {0x00, 0x0f, 0x00};
char b[8] = {0x00, 0x00, 0xff};
char data[4] = {0x94, 0x50, 0x0F, 0xFF};
int seq = 0;

void setup()
{
    wiringPiSetup();
    pinMode(PIN_DATA, OUTPUT); 	// SDI
    pinMode(PIN_CLOCK, OUTPUT); // SCK
}

void writeOut(char out)
{
    shiftOut(PIN_DATA, PIN_CLOCK, MSBFIRST, out);
}

int main(void)
{
	setup();
	for(;;)
    {
        int i = 0;
        while (i < 8)
        {
            if (i > 3)
            {
            	writeOut(b[seq]);
            	writeOut(b[seq]);
            	writeOut(g[seq]);
            	writeOut(g[seq]);
            	writeOut(r[seq]);
            	writeOut(r[seq]);
            }
            else
            {
            	writeOut(data[i]);
            }
            i++;
        }

        delay(500);

        seq++;
        if (seq == 3)
        {
            seq = 0;
        }
    }
}
