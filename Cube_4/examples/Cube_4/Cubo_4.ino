
#include <Cube_4.h>

Cube_4 cube(53,51,49,47,45,43,41,39,37,35,33,31,29,27,25,23,2,3,4,5);

void setup()
{
	//cube.init(53,51,49,47,45,43,41,39,37,35,33,31,29,27,25,23,2,3,4,5);
}

void loop()
{
	for(unsigned char i = 0; i < 4; i++)
	{
		cube.setAll(true);
		cube.apply();
		delay(500);
		cube.setAll(false);
		cube.apply();
		delay(500);
	}

	cube.setAll(false);
	for(unsigned char j = 0; j < 4; j++)
		for(unsigned char i = 0; i < 4; i++)
		{
			cube.setBase(i, true);
			cube.apply();
			delay(200);
			cube.setBase(i, false);
			cube.apply();
			//delay(200);
		}

	cube.setAll(false);
	for(unsigned char j = 0; j < 4; j++)
		for(unsigned char i = 0; i < 16; i++)
		{
			cube.setCol(i, true);
			cube.apply();
			delay(150);
			cube.setCol(i, false);
			cube.apply();
			//delay(150);
		}
}
