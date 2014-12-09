
#include <Arduino.h>

class Cube_4{
public:
	Cube_4(unsigned char port0, unsigned char port1, unsigned char port2, unsigned char port3,
		unsigned char port4, unsigned char port5, unsigned char port6, unsigned char port7,
		unsigned char port8, unsigned char port9, unsigned char port10, unsigned char port11,
		unsigned char port12, unsigned char port13, unsigned char port14, unsigned char port15,
		unsigned char gnd0, unsigned char gnd1, unsigned char gnd2, unsigned char gnd3);
	Cube_4();

	void init (unsigned char port0, unsigned char port1, unsigned char port2, unsigned char port3,
		unsigned char port4, unsigned char port5, unsigned char port6, unsigned char port7,
		unsigned char port8, unsigned char port9, unsigned char port10, unsigned char port11,
		unsigned char port12, unsigned char port13, unsigned char port14, unsigned char port15,
		unsigned char gnd0, unsigned char gnd1, unsigned char gnd2, unsigned char gnd3);

	void set (unsigned char col, unsigned char base, bool state);
	void setBase (unsigned char base, bool state = true);
	void setCol (unsigned char col, bool state = true);
	void setAll (bool state = true);
	void apply ();
private:
	unsigned char _port[16];
	bool _port_state[16];
	unsigned char _gnd[4];
	bool _gnd_state[4];
};
