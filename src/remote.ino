#include <RCSwitch.h>

byte led[] = {4, 5, 6, 7};
RCSwitch mySwitch = RCSwitch();
int tt0 = 0;
int tt1 = 0;
int tt2 = 0;
int tt3 = 0;
int tt4 = 0;
int tt5 = 0;
int tt6 = 0;
int tt7 = 0;

void setup() 
{
	Serial.begin(9600);
	mySwitch.enableReceive(0);

	for (int i = 0; i < 4; i++)
	{
		pinMode(led[i], OUTPUT);
		digitalWrite(led[i], LOW);
	}
}
void loop() 
{
	if (mySwitch.available()) 
	{
		output(mySwitch.getReceivedValue(), mySwitch.getReceivedBitlength(), mySwitch.getReceivedDelay(), mySwitch.getReceivedRawdata());
		unsigned long signalRF = mySwitch.getReceivedValue();
		switch (signalRF) 
		{
			case 8449960:
				tt0 = ~tt0;
				if (tt0)  digitalWrite(led[0], HIGH);
				else    digitalWrite(led[0], LOW);
			break;

			case 8449956:
				tt1 = ~tt1;
				if (tt1)  digitalWrite(led[1], HIGH);
				else    digitalWrite(led[1], LOW);
			break;

			case 8449954:
				tt2 = ~tt2;
				if (tt2)  digitalWrite(led[2], HIGH);
				else    digitalWrite(led[2], LOW);
			break;

			case 8449953:
				tt3 = ~tt3;
				if (tt3)  digitalWrite(led[3], HIGH);
				else    digitalWrite(led[3], LOW);
			break;

			case 8449964:
				tt4 = ~tt4;
				if (tt4)
					for (int i = 0; i < 4; i++)
					{
						digitalWrite(led[i], LOW);
						delay(500);
					}

				else
					for (int i = 0; i < 4; i++)
					{
						digitalWrite(led[i], HIGH);
						delay(500);
					}
			break;

			case 8449958:
				tt5 = ~tt5;
				if (tt5)
				{
					  digitalWrite(led[0], HIGH);
					  digitalWrite(led[2], HIGH);
				}
				else
				{
					digitalWrite(led[0], LOW);
					digitalWrite(led[2], LOW);
				}
			break;

			case 8449955:
				tt6 = ~tt6;
				if (tt6)
				{
					digitalWrite(led[1], HIGH);
					digitalWrite(led[3], HIGH);
				}
				else
				{
					digitalWrite(led[1], LOW);
					digitalWrite(led[3], LOW);
				}
			break;

			case 8449961:
				tt7 = ~tt7;
				if (tt7)
					for (int i = 0; i < 4; i++)
						digitalWrite(led[i], LOW);
				else
					for (int i = 0; i < 4; i++)
						digitalWrite(led[i], HIGH);
				break;
		}
		mySwitch.resetAvailable();
	}
}




