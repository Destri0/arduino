/*
--Codigo realizado por Fran
*/
const int led1 = 9;

void setup()
{
	pinMode(led1, OUTPUT);
	Serial.begin(9600);
	Serial.println("Introduzca un numero de 0 a 255:\n");
}

void loop()
{
	if( Serial.available() > 0 )
	{       
		delay(5);
		analogWrite(led1, Serial.parseInt());
        while(Serial.read() > -1 );
	}
}
