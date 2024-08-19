/******************************************************************************
 *  ファイル名：app.cpp
 *　　　　内容：タスクであるmain_taskの実施
 *  　　作成日：2024/7/25
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#include "app.h"
#include "Runner.h"

/* 名前空間ev3apiを使用する */
using namespace ev3api

/* オブジェクトを静的に確保する */
ColorSensor gColorSensor(PORT_2);
SonarSensor gSonarSensor(PORT_3);
Motor       gLeftWheel(PORT_C);
Motor       gRightWheel(PORT_B);

/*----------------------------------------------------
*                      内部結合
*-----------------------------------------------------*/
namespace {
    /* オブジェクトの定義 */
    Calculation* gCalculation;
    Walker* gWalker;
    Runner* gRunner;

    /* システムの生成 */
    void user_system_create()
    {
        /* オブジェクトを動的に確保 */
        gCalculation = new Calculation(gColorSensor);
        gWalker = new Walker(gLeftWheel, gRightWheel);
        gRunner = new Runner(gSonarSensor, gCalculation, gWalker);
    }

    /* システムの破棄 */
    void user_system_destroy()
    {
        /* 左右のモータをリセット */
        gLeftWheel.reset();
        gRightWheel.reset();

        /* 動的なオブジェクトの解放 */
        delete gRunner;
        delete gCalculation;
        delete gWalker;
    }
}

/*----------------------------------------------------
*                    メインタスク
*-----------------------------------------------------*/
void main_task(intptr_t unused)
{
    user_system_create();   /* センサやモータの初期化処理 */

    /* 周期ハンドラ開始 */
    sta_cyc(CYC_RUNNER);

    slp_tsk();  /* メインタスクの起床待ち */

    /* 周期ハンドラ停止 */
    stp_tsk(CYC_RUNNER);

    user_system_destroy();  /* 終了処理 */

    ext_tsk();  /* タスクの終了 */
}

/*----------------------------------------------------
*                    ランナータスク
*-----------------------------------------------------*/
void runner_tsk(intptr_t exinf)
{
    /* ラージハブの右ボタンが押されたら判定 */
    if (ev3_button_is_pressed(RIGHT) == true)
    {
        wup_tsk(MAIN_TASK); /* メインタスクの起床 */
    }
    else
    {
        gRunner->runL();    /* 走行 */
    }

    ext_tsk();
}
