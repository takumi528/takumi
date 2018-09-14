#pragma once

/**
*	@file	System.h
*	@brief	�����ݒ��A�V�X�e���I�Ȃ��Ƃ�����
*	@author Photon
*/

#include "../Manager.h"
#include "../GameEngine/Game.h"
#include "../DebugWindow/Debug.h"
#include "../Utility/Graph.h"
#include <DxLib.h>
#include <string>

namespace suken {
	/**
	*	@brief�@�����ݒ�p�\���̂���@WinMain�Ŏg���Ă��
	*/
	struct SystemSetting {
		unsigned char WindowSyle;//!>	�E�C���h�E�X�^�C���@1�F���ʁ@�Q�F�^�C�g���o�[�Ȃ��A������@�R�F�^�C�g���o�[�A���Ȃ�
		bool isWindow;
		std::string WindowText;//!>	����̃^�C�g��
		unsigned char iconID;//!>�A�C�R����ID�@��{�G��Ȃ�
		int windowWidth;//!>�@�E�C���h�E��
		int windowHeight;//!>�@�E�C���h�E����
		float targetFps;//!>�@�ڕWfps
		float startLoadingMinTime;//!>�@�ŏ��̃��[�h����
		std::string startGraphPath;//!>�@�ŏ��̉��
		std::string loadingGraphPath;//!>�@���[�f�B���O���̃A�j���[�V�����摜
		int loadingSizeX;//!>�@���[�f�B���O�摜�̉���
		int loadingSizeY;//!>�@���[�f�B���O�摜�̍���
		unsigned char loadingFlipTime;//!>�@���[�f�B���O�摜�̕\���ؑ֎���
		int loadingPosX;//!>�@���[�f�B���O�摜�̕\���ʒu
		int loadingPosY;//!>�@���[�f�B���O�摜�̕\���ʒu
		bool isUseLoading;//!>�@���[�f�B���O�A�j���[�V�������g�����ǂ���
		bool isLaunchar;//!>�@���g�������`���[���ǂ���

		int debugWindowWidth;
		int debugWindowHeight;

		CScene* scene;
		Flip flip;
		bool isTransiton;

		/**
		*	@brief�@�E�C���h�E�T�C�Y�ݒ�
		*	@param	(width)�@����
		*	@param	(height)�@����
		*/
		void SetWindowSize(int width,int hegiht);

		/**
		*	@brief�@���[�f�B���O�摜�ݒ�B�g��Ȃ��Ƃ��͕K������
		*/
		void SetLoadingGraph();

		/**
		*	@brief�@���[�f�B���O�摜�ݒ�
		*	@param	(filrName)�@�摜�t�@�C���̈ʒu�@
		*	@param	(sizeX)�@�摜������̉���
		*	@param	(sizeY)�@�摜������̍���
		*	@param	(flipTime)�@�A�j���[�V�����̐؂�ւ�����
		*	@param	(positionX)�@�摜�̕\�����W�@�@
		*	@param	(positionY)�@�摜�̕\�����W�@�@
		*/
		void SetLoadingGraph(const char* fileName, int sizeX, int sizeY,int flipTime=10, int positionX = 0, int positionY = 0);

		/**
		*	@brief�@�����ݒ�ł�
		*/
		void InitScene(CScene* scene);

		/**
		*	@brief�@�����ݒ�ł��@������ʂ���g�����V�W�������܂�
		*/
		void InitScene(CScene* scene, const char* ruleGraph, unsigned char speed = 10, unsigned char gradate = 1);

		/**
		*	@brief�@�����ݒ�ł��@������ʂ���g�����V�W�������܂�
		*/
		void InitScene(CScene* scene, const char* ruleGraph, const char* ruleGraph2, unsigned char speed = 10, unsigned char gradate = 1);

		/**
		*	@brief�@�����ݒ�ł��@������ʂ���g�����V�W�������܂�
		*/
		void InitScene(CScene* scene, Flip::Type flipType, unsigned char speed = 10);
	};

	/**
	*	@brief�@�V�X�e���N���X����@System.�`�@�ŏo�Ă���֐��́A�g���Ă���č\��Ȃ���@Escape()�͎��ȐӔC�ł�
	*/
	class CSystem {
	public:
		/**
		*	@brief�@�R���X�g���N�^
		*/
		CSystem();

		/**
		*	@brief�@�f�X�g���N�^
		*/
		~CSystem();

		/**
		*	@brief�@���s����Ƌ����I���ł��܂�
		*/
		void Escape();

		/**
		*	@brief�@�E�C���h�E���擾
		*/
		int GetWindowX()const;

		/**
		*	@brief�@�E�C���h�E�����擾
		*/
		int GetWindowY()const;

		/**�@
		*	@brief�@�f�B�X�v���C���擾
		*/
		int GetDispX()const;

		/**
		*	@brief�@�f�B�X�v���C�����擾
		*/
		int GetDispY()const;

		/**
		*	@brief�@exe���n�܂��Ă���̃t���[�����擾
		*/
		int GetFrame()const;

		/**
		*	@brief�@���t���[���̎n�܂������Ԏ擾�i�}�C�N���b�j
		*/
		int GetNow()const;

		/**
		*	@brief�@�t���[�����[�g�擾
		*/
		float GetFps()const;

		/**
		*	@brief�@���ɃV�[���؂�ւ�����Ƃ��̍ŒჍ�[�h���Ԃ�ݒ�ł��܂�
		*/
		void SetNextLoadTime(float nextLoadingMinTime);

		/**
		*	@brief�@�V�[���؂�ւ��A�j���[�V������ύX�ł��܂�
		*/
		void SetDoadAnimation(Anim anim,int positionX,int positionY);

		HINSTANCE GetHInstance();

		int GetNCmdShow();

	private:
		void Awake(SystemSetting setting);

		void Start(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow);

		void Update();

		void Loop();

		void GoLoading();

		void EndLoad();

		bool GetIsEscape();

		void Wait();

		void End();

		struct {
			int now;
			int windowWidth;
			int windowHeight;
			int displayX;
			int displayY;
			float fps;
			float targetRate;
			int startTime;
			int refreshRate;
			unsigned char cnt;//count�̎��B�g�p�������L���O��ʂɓ���̂ŁA�O�����ϐ��ɓa������
			int frame;
			float loadingMinTime;
			float nextLoadingMinTime;
			unsigned char flag;
		}m;

		HINSTANCE hInstance;
		HINSTANCE hPreInst;
		LPSTR lpszCmdLine;
		int nCmdShow;

		enum {
			isEscape  =		1 << 0,
			isUseLoading =	1 << 1,
			isLoading =		1 << 2,
			isLaunchar =	1 << 3
		};
#ifdef DEBUG
		CDebug debug;
#endif
		friend int Main(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow);

		friend class CScene;
	};
}