#pragma once

/**
*	@file	Graph.h
*	@brief	�Ȃ�����ȕ֗��Ȃ��̂����܂ő��݂��Ȃ������̂��B�֗��ȍ\���� Graph �� Anim �ALoadDivGraph�֐��̃A�����W�@��ǉ����܂�
*	@author	Photon
*/

#include "../Manager.h"

namespace suken {
	/**
	*	@brief�@�摜�̈������ƂĂ��y�ɂȂ�A���������̋��������ł��@�����\���𗝉�����K�v�͂���܂���@DrawGraph()�̈����Ɏg���邵�ALoadGraph()�������邱�Ƃ��ł��܂�
	*/
	struct Graph {
	public:
		/**
		*	@brief�@����̃R���X�g���N�^
		*/
		Graph();

		/**
		*	@brief�@�R���X�g���N�^
		*/
		Graph(const int& handle);

		/**
		*	@brief�@�R���X�g���N�^
		*/
		Graph(const char* file);

		/**
		*	@brief�@�R�s�[�R���X�g���N�^
		*/
		Graph(const Graph& obj);

		/**
		*	@brief�@������Z�q
		*/
		Graph& operator=(const Graph& obj);

		/**
		*	@brief�@������Z�q
		*/
		Graph& operator=(const char* file);

		/**
		*	@brief�@DX���C�u�����̊֐��̈����ɓ���邱�Ƃ��ł��܂�
		*/
		operator int()const;

		/**
		*	@brief�@�f�X�g���N�^
		*/
		~Graph();

		void Set(const int& handle);

		void Set(const char* file);

		Graph& operator=(const int& handle);

		/**
		*	@brief�@�`��@�ʒu��0,0
		*/
		void operator ()()const;

		/**
		*	@brief�@�`��
		*/
		void operator ()(int x, int y, bool turnFlag = false)const;
		/**
		*	@brief�@�`��
		*/
		void operator ()(Vector2D v, bool turnFlag = false)const;

		/**
		*	@brief�@�`��@�ʒu��0,0
		*/
		void Draw()const;

		/**
		*	@brief�@�`��
		*/
		void Draw(int x,int y, bool turnFlag = false)const;
		/**
		*	@brief�@�`��
		*/
		void Draw(Vector2D v, bool turnFlag = false)const;

		/**
		*	@brief�@�`��@��]�p�x�w��
		*/
		void DrawRota(int x, int y,double ExtRate, double angle, bool turnFlag = false)const;
		/**
		*	@brief�@�`��@��]�p�x�w��
		*/
		void DrawRota(Vector2D v, double ExtRate, double angle, bool turnFlag = false)const;

		/**
		*	@brief�@�`��@��]�p�x�w��
		*/
		void DrawRota2(int x, int y,int cx,int cy, double ExtRate, double angle, bool turnFlag = false)const;
		/**
		*	@brief�@�`��@��]�p�x�w��
		*/
		void DrawRota2(Vector2D v, Vector2D center, double angle, double ExtRate, bool turnFlag = false)const;

		/**
		*	@brief�@�`��@��]�p�x�w��
		*/
		void DrawRota3(int x, int y, int cx, int cy, double ExtRateX, double ExtRateY, double angle, bool turnFlag = false)const;
		/**
		*	@brief�@�`��@��]�p�x�w��
		*/
		void DrawRota3(Vector2D v, Vector2D center, double angle, Vector2D ExtRate, bool turnFlag = false)const;

		/**
		*	@brief�@�`��@2�_�̍��W�w��
		*/
		void DrawExtend(int x1, int y1, int x2, int y2)const;
		/**
		*	@brief�@�`��@2�_�̍��W�w��
		*/
		void DrawExtend(Vector2D v1, Vector2D v2)const;

		/**
		*	@brief�@�`��@4�_�̍��W�w��
		*/
		void DrawModi(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)const;
		/**
		*	@brief�@�`��@4�_�̍��W�w��
		*/
		void DrawModi(Vector2D v1, Vector2D v2, Vector2D v3, Vector2D v4)const;

		/**
		*	@brief�@���A�������y�A�ŕԂ�
		*/
		std::pair<int, int> GetSize()const;

	private:
		int handle;
		unsigned char* cnt;

		void AddRef();
		void Release();
	};

	/**
	*	@brief�@�������������̓A�j���[�V�����J�E���^�����K�v�͂Ȃ��̂ł��@LoadDivGraph()�������āA�ϐ����Ɂi�j�����邾���ŏ���ɃA�j���[�V��������̂ł�
	*/
	struct Anim {
	public:
		/**
		*	@brief�@����̃R���X�g���N�^
		*/
		Anim();

		/**
		*	@brief�@�R���X�g���N�^�@�ݒ肷��
		*/
		Anim(GraphVec graph, unsigned char flipTime=10);

		/**
		*	@brief�@�ݒ�
		*/
		void Set(GraphVec graph, unsigned char flipTime = 10);

		/**
		*	@brief�@�摜��vector����Ԃ�
		*/
		GraphVec& GetVec();

		/**
		*	@brief�@�؂�ւ����x��Ԃ�
		*/
		const char GetFlipTime();

		/**
		*	@brief�@�摜�����邾���@�؂�ւ����x�̓f�t�H���g
		*/
		Anim& operator =(GraphVec& vec);

		/**
		*	@brief�@�`��
		*/
		void operator ()(int x, int y, bool isTurn = false, bool isPlusCount = true);

		/**
		*	@brief�@�`��
		*/
		void operator ()(Vector2D vec, bool isTurn = false, bool isPlusCount = true);

		/**
		*	@brief�@�`��
		*/
		void Draw(int x, int y, bool turnFlag = false, bool isPlusCount = true);
		/**
		*	@brief�@�`��
		*/
		void Draw(Vector2D v, bool turnFlag = false, bool isPlusCount = true);

		/**
		*	@brief�@�`��@��]�p�x�w��
		*/
		void DrawRota(int x, int y, double ExtRate, double angle, bool turnFlag = false, bool isPlusCount = true);
		/**
		*	@brief�@�`��@��]�p�x�w��
		*/
		void DrawRota(Vector2D v, double ExtRate, double angle, bool turnFlag = false, bool isPlusCount = true);

		/**
		*	@brief�@�`��@��]�p�x�w��
		*/
		void DrawRota2(int x, int y, int cx, int cy, double ExtRate, double angle, bool turnFlag = false, bool isPlusCount = true);
		/**
		*	@brief�@�`��@��]�p�x�w��
		*/
		void DrawRota2(Vector2D v, Vector2D center, double angle, double ExtRate, bool turnFlag = false, bool isPlusCount = true);

		/**
		*	@brief�@�`��@��]�p�x�w��
		*/
		void DrawRota3(int x, int y, int cx, int cy, double ExtRateX, double ExtRateY, double angle, bool turnFlag = false, bool isPlusCount = true);
		/**
		*	@brief�@�`��@��]�p�x�w��
		*/
		void DrawRota3(Vector2D v, Vector2D center, double angle, Vector2D ExtRate, bool turnFlag = false, bool isPlusCount = true);

		/**
		*	@brief�@�`��@2�_�̍��W�w��
		*/
		void DrawExtend(int x1, int y1, int x2, int y2, bool isPlusCount = true);
		/**
		*	@brief�@�`��@2�_�̍��W�w��
		*/
		void DrawExtend(Vector2D v1, Vector2D v2, bool isPlusCount = true);

		/**
		*	@brief�@�`��@4�_�̍��W�w��
		*/
		void DrawModi(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, bool isPlusCount = true);
		/**
		*	@brief�@�`��@4�_�̍��W�w��
		*/
		void DrawModi(Vector2D v1, Vector2D v2, Vector2D v3, Vector2D v4, bool isPlusCount = true);

		/**
		*	@brief�@�A�j���[�V�����J�E���g�𑝂₵�܂�
		*/
		void PlusCount();
	private:
		GraphVec graph;
		unsigned int cnt;
		unsigned char flipTime;
	};

	/**
	*	@brief�@�t�H���g�n���h�����ȒP�Ɏg�����߂̃N���X
	*/
	struct Font {
	public:
		/**
		*	@brief�@����̃R���X�g���N�^
		*/
		Font();

		/**
		*	@brief�@�R���X�g���N�^
		*/
		Font(const char* FontName,int height,int thick = -1,int fontType = -1,int edgeSize = -1,bool isItalic = false);

		/**
		*	@brief�@�R�s�[�R���X�g���N�^
		*/
		Font(const Font& obj);

		/**
		*	@brief�@������Z�q
		*/
		Font& operator=(const Font& obj);

		/**
		*	@brief�@DX���C�u�����̊֐��̈����ɓ���邱�Ƃ��ł��܂�
		*/
		operator int()const;

		/**
		*	@brief�@�f�X�g���N�^
		*/
		~Font();

		void Set(const char* FontName, int height, int thick = -1, int fontType = -1, int edgeSize = -1, bool isItalic = false);

		void Draw(int x, int y, const char* str,unsigned int color = 0, unsigned int edgeColor = 0);

		int GetWidth(const char* str, int strLen);

		int GetHeight();

	private:
		int handle;
		unsigned char* cnt;

		void AddRef();
		void Release();
	};

	///** //�s�������̂ŃR�����g�A�E�g
	//*	@brief�@�摜�𕪊��ǂݍ��݂���̂ɁA�ʓ|�Ȑݒ�͂���܂���@�v�f����vector.size()�Ŋm�F���Ă��������ۏ؂͂��܂���
	//*/
	//GraphVec LoadDivGraph(const char* file,int xSize,int ySize);

	///**
	//*	@brief�@�����ɂƂ����x�N�^�[�ɁA���[�h�����摜��push_back���Ă���܂��@�v�f����vector.size()�Ŋm�F���Ă��������ۏ؂͂��܂���
	//*/
	//void LoadDivGraph(const char* file, int xSize, int ySize, GraphVec& vector);

	///**
	//*	@brief�@�x�N�^�[���g�������Ȃ���łȐl�̂��߂ɁAGraph�̔z��ɓ���Ă����o�[�W���������܂���
	//*/
	//void LoadDivGraph(const char* file, int xSize, int ySize, Graph* handleBuf);

	/**
	*	@brief�@�摜�𕪊��ǂݍ��݂���̂ɁA�ʓ|�Ȑݒ�͂���܂���@�v�f����vector.size()�Ŋm�F���Ă��������ۏ؂͂��܂���
	*/
	GraphVec LoadDivGraph(const char* file, int allNum, int xNum, int yNum,int xSize,int ySize);

	/**
	*	@brief�@�����ɂƂ����x�N�^�[�ɁA���[�h�����摜��push_back���Ă���܂��@�v�f����vector.size()�Ŋm�F���Ă��������ۏ؂͂��܂���
	*/
	void LoadDivGraph(const char* file, int allNum, int xNum, int yNum, int xSize, int ySize, GraphVec& vector);

	/**
	*	@brief�@�x�N�^�[���g�������Ȃ���łȐl�̂��߂ɁAGraph�̔z��ɓ���Ă����o�[�W���������܂���
	*/
	void LoadDivGraph(const char* file, int allNum, int xNum, int yNum, int xSize, int ySize, Graph* handleBuf);
}