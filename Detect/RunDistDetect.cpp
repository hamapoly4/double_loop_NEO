#include "RunDistDetect.h"

using namespace ev3api;

Motor RunDistDetect::LeftMotorEncoder(PORT_C);
Motor RunDistDetect::RightMotorEncoder(PORT_B);

RunDistDetect::RunDistDetect(unsigned char tire)
    : mtire(tire), mold_left_cnt(0), mold_right_cnt(0)
{
    LeftMotorEncoder.setCount(0);
    RightMotorEncoder.setCount(0);
}

RunDistDetect::~RunDistDetect()
{
    ;
}

float RunDistDetect::getRunDist()
{
    measureRunDist();
    return mrun_dist;
}

void RunDistDetect::measureRunDist()
{
    if (mtire == RIGHT)
    {
        mright_cnt = RightMotorEncoder.getCount();
        mright_sum += mright_cnt - mold_right_cnt;
        mrun_dist = mright_sum * mANGLE1DIST;
        
        mold_right_cnt = mright_cnt;
    }
    else if (mtire == LEFT)
    {
        mleft_cnt = LeftMotorEncoder.getCount();
        mleft_sum += mleft_cnt - mold_left_cnt;
        mrun_dist = mleft_sum * mANGLE1DIST;

        mold_left_cnt = mleft_cnt;
    }
    else if (mtire == BOTH)
    {
        mright_cnt = RightMotorEncoder.getCount();
        mleft_cnt = LeftMotorEncoder.getCount();

        mright_sum += mright_cnt - mold_right_cnt;
        mleft_sum += mleft_cnt - mold_left_cnt;

        mrun_dist = (mright_sum + mleft_sum) * mANGLE1DIST / 2.0;

        mold_right_cnt = mright_cnt;
        mold_left_cnt = mleft_cnt;
    }
}