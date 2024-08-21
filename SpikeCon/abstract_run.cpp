#include "abstract_run.h"

using namespace ev3api;

Motor Run::LeftMotor(PORT_C);
Motor Run::RightMotor(PORT_B);

Run::Run(int pwm)
	: mfix_pwm(pwm)
{
	;
}
