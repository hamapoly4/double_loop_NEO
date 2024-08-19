#include "GyroSensor.h"
#include <stdio.h>

GyroSensor::GyroSensor(int angle)
	: mangle(angle)
{
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!ジャイロセンサオブジェクトの生成！！\n");
}

GyroSensor::~GyroSensor()
{
	printf("ジャイロセンサオブジェクトを破棄！！\n");
}

int GyroSensor::getAngle() const
{
	printf("旋回角度：%d\n", mangle);
	return mangle;
}
