#include <stdio.h>
#include <wiringPi.h>

char r[8] = {0xFF, 0x00, 0x00};
char g[8] = {0x00, 0xff, 0x00};
char b[8] = {0x00, 0x00, 0xff};
char data[4] = {0x94, 0x50, 0x0F, 0xFF};
int seq = 0;

void setup()
{
    wiringPiSetup();
    //TODO : check pins
    pinMode(2, OUTPUT); // power
    pinMode(3, OUTPUT); // SDI
    pinMode(4, OUTPUT); // SCK
}

void writeOut(char out)
{
    shiftOut(3, 4, 1, out);
}

int main()
{

    for (;;)
    {
        digitalWrite(2, HIGH);
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

        delay(1000);

        seq++;
        if (seq == 3)
        {
            seq = 0;
        }
    }
}
