#include "Suken.h"
#include "CSTitle.h"

/**
*	@file	Main.cpp
*	@brief	�����ݒ��������AGame.Init()����������A�@�\�ǉ��̐ݒ������Ƃ���ł�
*	@author	-
*/

SystemSetting suken::Config() {
	SystemSetting setting; //�ݒ�p�\���́@System.Awake()�ɓn�����߂̂���

	/////////////����������肵�������ݒ�ɂ��A���R�ɐG���Ă悵����//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	setting.WindowSyle = 0;						//�@0:���ʂ̃E�C���h�E�A1:�^�C�g���o�[�Ȃ��A������A2:�^�C�g���o�[�A���Ȃ��B
	setting.isWindow = true;					//	�t���X�N���[���ɂ��邩�ǂ����̃t���O�@true�Ȃ�𑜓x��640*480�ɕύX�����
	setting.WindowText = "�O������";	//�@����̃E�C���h�E�e�L�X�g
	setting.iconID = 101;						//	��{�M��Ȃ��Ă�����
	setting.SetWindowSize(800, 600);			//	��ʃT�C�Y�ݒ�
	setting.targetFps = 60.0f;					//	�ڕWfps�ݒ�
	setting.startLoadingMinTime = 00;			//	�ŏ��̍ŒZ���[�f�B���O����
	setting.startGraphPath = "SukenLibAsset/LOGO/LOGO.png";	//�ŏ��̃��[�h���ɕ\������摜
	setting.SetLoadingGraph("SukenLibAsset/LOGO/loading.png", 408, 64, 10, 392, 536);	//���[�h���ɕ\������A�j���[�V�����@����(�t�@�C�����Apixel���Apixel�����A�摜�؂�ւ����ԁA�\�����W)
//	setting.SetLoadingGraph();
	setting.isLaunchar = false;

	setting.debugWindowWidth = 200;
	setting.debugWindowHeight = 640;

	setting.InitScene(new CSTitle(), Flip::SCALEDOWN_ROTATION_RIGHT, 7);

	////////////���������ݒ肱���܂Ł���/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	return setting;//�G��Ȃ��ł�������
}

//�������p�B�قڏ����V�[���ݒ�p
void suken::Awake() {

}

//�f�o�b�O�p�@�V�[��������Ɏ��s�����
void suken::DebugLoopEnter() {

}

//���Ȃ����f�o�b�O�p�@�V�[���̌�Ɏ��s�����
void suken::DebugLoopExit() {

}