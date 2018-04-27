#pragma once

#include <DxLib.h>
#include <vector>

//#define DEBUG

namespace suken {

	//GameEngine
	struct DrawMode;
	struct Flip;
	class CScene;

	class CInput;
	class CMusic;

	//Object
	class Object;
	template <class Object>
	class Manager;

	//System
	struct SystemSetting;
	class CSystem;

	//Utility
	template<typename T>
	struct Twin;
	typedef Twin<float> Point2D;
	struct Vector2D;

	struct Graph;
	struct Anim;
	struct Font;
	typedef std::vector<Graph> GraphVec;

	class CData;
	struct MCE;

	struct Memory;
	struct CSV;

	/**
	*	@brief�@Main.cpp�ɂ����B
	*/
	SystemSetting Config();
	/**
	*	@brief�@Main.cpp�ɂ����B
	*/
	void Awake();
	/**
	*	@brief�@Main.cpp�ɂ�����
	*/
	void DebugLoopEnter();
	/**
	*	@brief�@Main.cpp�ɂ�����
	*/
	void DebugLoopExit();

	extern CSystem System;

	extern CInput Input;

	extern CMusic Music;

	int Main(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow);
}