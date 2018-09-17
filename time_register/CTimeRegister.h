#pragma once
#ifndef _CTIME_REGISTER_
#define _CTIME_REGISTER_
template<typename T>
class CTimeRegister
{
public:
	CTimeRegister() {}
	void timeUp() { time = true; }
	void timeDown() { time = false; }
	void valueWrite(T temp) {
		if (time == true) {
			temp_write = temp_last = temp;
		}
		else {
			temp_write = temp_last;
		}
	}
	void destinationWrite(bool dest) {
		dest ? (temp_B = temp_write) : (temp_A = temp_write);
	}
	T valueA() { return temp_A; }
	T valueB() { return temp_B; }
	~CTimeRegister() {}
private:
	T temp_last;
	T temp_write;
	T temp_A;
	T temp_B;
	bool time;
};


#endif // !_CTIME_REGISTER_
