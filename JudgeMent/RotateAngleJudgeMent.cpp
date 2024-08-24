#include "RotateAngleJudgeMent.h"
#include <stdio.h>

using namespace ev3api;

GyroSensor RotateAngleJudgeMent::mGyroSensor(PORT_4);

RotateAngleJudgeMent::RotateAngleJudgeMent(unsigned char rota, int target_angle)
	: mrota(rota), mtarget_angle(target_angle), angle_reset(true)
{
	;
}

RotateAngleJudgeMent::~RotateAngleJudgeMent()
{
	;
}

bool RotateAngleJudgeMent::judge()
{
	if (angle_reset == true)
	{
		angle_reset = false;
		mGyroSensor.reset();
		return false;
	}
	mcurrent_angle = mGyroSensor.getAngle();

	if (mrota == RIGHT)
	{
		printf("右旋回角度：%d度\n", mcurrent_angle);
		if (mcurrent_angle >= mtarget_angle)
		{
			return true;
		}
	}
	else if (mrota == LEFT)
	{
		printf("左旋回角度：%d度\n", mcurrent_angle);
		if (mcurrent_angle <= mtarget_angle)
		{
			return true;
		}
	}
}
