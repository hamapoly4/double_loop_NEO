#ifndef ___CLASS_SCENE
#define ___CLASS_SCENE

#include "abstract_run.h"	// ���ۃN���X�̃w�b�_�i���s�j
#include "RotateRun.h"		//
#include "StraRun.h"		//
#include "LineSearchRun.h"	//
#include "LineTraceRun.h"	// �h���N���X

#include "JudgeMent.h"				// ���ۃN���X�̃w�b�_�i����j
#include "RotateAngleJudgeMent.h"	//
#include "RunDistJudgeMent.h"		//
#include "ColorJudgeMent.h"			// �h���N���X

class Scene {
private:
	enum eRun {
		ROTATE_R,   ROTATE_L,    STRAIGHT,
		LINESEARCH, LINETRACE_R, LINETRACE_L,
	};

	enum eWhich { RIGHT, LEFT, BOTH, };

	enum eColor { BLACK, BLUE, };

	static Run* mRun[6];
	static JudgeMent* mJudgeMent[16];

	unsigned char mcurrent_scene_no;
	unsigned char index_run;

public:
	Scene(unsigned char scene_no);
	~Scene();
	void run();
	bool fin_judge();
};

#endif // ___CLASS_SCENE