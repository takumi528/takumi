#pragma once

/**
*	@file	Game.h
*	@brief	CScene���p��������A�R�[�h�ʂ���������
*	@author	Photon
*/

#include "Scene.h"

namespace suken {
	/**
	*	@brief�@���ׂẴV�[���̐e�ł��@new CGame() ��FlipScene�ɓ����z�́A�􂢎E����܂�
	*/
	class CGame :private CScene{
	public:
		CGame();

		/**
		*	@brief�@�V�[���؂�ւ����܂��@�ǂ��Ŏg���Ă�����邱�Ƃ͂���܂���
		*/
		void FlipScene(CScene* scene);

		/**
		*	@brief�@�V�[���؂�ւ����܂��@�g�����V�W�������܂��@�ǂ��Ŏg���Ă�����邱�Ƃ͂���܂���
		*/
		void FlipScene(CScene* scene, const char* ruleGraph, unsigned char speed = 10, unsigned char gradate = 1);

		/**
		*	@brief�@�V�[���؂�ւ����܂��@�g�����V�W�������܂��@�ǂ��Ŏg���Ă�����邱�Ƃ͂���܂���
		*/
		void FlipScene(CScene* scene, const char* ruleGraph, const char* ruleGraph2, unsigned char speed = 10, unsigned char gradate = 1);

		/**
		*	@brief�@�V�[���؂�ւ����܂��@�g�����V�W�������܂��@�ǂ��Ŏg���Ă�����邱�Ƃ͂���܂���
		*/
		void FlipScene(CScene* scene, Flip::Type flipType, unsigned char speed = 10);

	private:
		Anim loadingAnim;
		char loadingFlipTime;
		int loadingPosX;
		int loadingPosY;

		void DrawNowLoading();

		bool FlipTransition();

		/**
		*	@brief�@�����ݒ�ł�
		*/
		void Init(CScene* scene);

		/**
		*	@brief�@�����ݒ�ł�
		*/
		void Init(CScene* scene, Flip flip);

		friend class CSystem;
		friend class CDebug;
	};

	extern CGame Game;
}