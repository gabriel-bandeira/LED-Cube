
#include <Cube_4.h>

Cube_4::Cube_4()
{

}

Cube_4::Cube_4 (unsigned char port0, unsigned char port1, unsigned char port2, unsigned char port3,
	unsigned char port4, unsigned char port5, unsigned char port6, unsigned char port7,
	unsigned char port8, unsigned char port9, unsigned char port10, unsigned char port11,
	unsigned char port12, unsigned char port13, unsigned char port14, unsigned char port15,
	unsigned char gnd0, unsigned char gnd1, unsigned char gnd2, unsigned char gnd3)
{
	this->init	(port0, port1, port2, port3,
		port4, port5, port6, port7,
		port8, port9, port10, port11,
		port12, port13, port14, port15,
		gnd0, gnd1, gnd2, gnd3);
}

void Cube_4::init (unsigned char port0, unsigned char port1, unsigned char port2, unsigned char port3,
	unsigned char port4, unsigned char port5, unsigned char port6, unsigned char port7,
	unsigned char port8, unsigned char port9, unsigned char port10, unsigned char port11,
	unsigned char port12, unsigned char port13, unsigned char port14, unsigned char port15,
	unsigned char gnd0, unsigned char gnd1, unsigned char gnd2, unsigned char gnd3)
{
	this->_port[0] = port0;
	this->_port[1] = port1;
	this->_port[2] = port2;
	this->_port[3] = port3;
	this->_port[4] = port4;
	this->_port[5] = port5;
	this->_port[6] = port6;
	this->_port[7] = port7;
	this->_port[8] = port8;
	this->_port[9] = port9;
	this->_port[10] = port10;
	this->_port[11] = port11;
	this->_port[12] = port12;
	this->_port[13] = port13;
	this->_port[14] = port14;
	this->_port[15] = port15;

	this->_gnd[0] = gnd0;
	this->_gnd[1] = gnd1;
	this->_gnd[2] = gnd2;
	this->_gnd[3] = gnd3;

	for(unsigned char i = 0; i < 16; i++)
		pinMode(this->_port[i], OUTPUT);
	for(unsigned char i = 0; i < 4; i++)
		pinMode(this->_gnd[i], OUTPUT);
}

void Cube_4::set(unsigned char col, unsigned char base, bool state)
{
	this->_port_state[col] = state;
	this->_gnd_state[base] = !state;
}

void Cube_4::setBase(unsigned char base, bool state)
{
	for(unsigned char i = 0; i < 16; i++)
		this->_port_state[i] = state;
	for(unsigned char i = 0; i < 4; i++)
		this->_gnd_state[i] = state;
	this->_gnd_state[base] = !state;
}

void Cube_4::setCol(unsigned char col, bool state)
{
	for(unsigned char i = 0; i < 16; i++)
		this->_port_state[i] = !state;
	for(unsigned char i = 0; i < 4; i++)
		this->_gnd_state[i] = !state;
	this->_port_state[col] = state;
}

void Cube_4::setAll(bool state)
{
	for(unsigned char i = 0; i < 16; i++)
		this->_port_state[i] = state;
	for(unsigned char i = 0; i < 4; i++)
		this->_gnd_state[i] = !state;
}

void Cube_4::apply()
{
	for(unsigned char i = 0; i < 16; i++)
		digitalWrite(this->_port[i], this->_port_state[i]);
	for(unsigned char i = 0; i < 4; i++)
		digitalWrite(this->_gnd[i], this->_gnd_state[i]);
}
