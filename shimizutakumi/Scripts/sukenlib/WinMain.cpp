#include "../Suken.h"
#include <DxLib.h>

/**
*	@file	WinMain.cpp
*	@brief	�ՎU�Ƃ��Ă�
*	@author	Photon
*/

suken::CSystem suken::System;

suken::CGame suken::Game;

suken::CInput suken::Input;

int suken::Main(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow) {

	System.Start(hInstance, hPreInst, lpszCmdLine, nCmdShow);

#ifdef DEBUG
	System.debug.Awake();
#endif

	System.Awake(Config());						//	�������BMain��Awake�������ŌĂ�ł�

#ifdef DEBUG
	System.debug.Start();
#endif

	while (!DxLib::ProcessMessage() && !System.GetIsEscape()) {
		System.Loop();
	}

	System.End();
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow) {
	return suken::Main(hInstance, hPreInst, lpszCmdLine, nCmdShow);
}