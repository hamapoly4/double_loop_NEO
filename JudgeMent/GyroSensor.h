#ifndef ___CLASS_GYROSENSOR
#define ___CLASS_GYROSENSOR

class GyroSensor {
private:
	int mangle;
public:
	GyroSensor(int angle = 0);
	~GyroSensor();
	int getAngle() const;
};

#endif // ___CLASS_GYROSENSOR