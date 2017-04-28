#pragma once

#include"Data.h"

namespace suken {
	struct MCE {
	public:
		struct Layer {
			enum LayerData {
				A = 0,
				B = 1,
				C = 2
			};
		}static  layer;

		MCE();

		MCE(const char* file);

		/**
		*	FILE�Fmcepic�ƁA���̑���mce�t�@�C��������ꏊ���w��
		*	index�Fmce���J�������̏ォ��O�C�P�C�Q....�Ɛ������ԍ�
		*/
		MCE(const char* FILE,unsigned int index);

		~MCE();

		void Set(const char* file);

		MCE& operator =(const char* file);

		int& Get(Layer::LayerData layer, int x, int y);

		int GetWidth();

		int GetHeight();

		int GetEdge();

		std::string GetGraph(Layer::LayerData layer);

		int& operator()(Layer::LayerData layer, int x, int y);

	private:
		int *chip;
		int width;
		int height;
		int edge;
		std::string graph[3];

		int Array(char layer, int x, int y);
	};
}

