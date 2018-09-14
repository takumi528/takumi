#pragma once

/**
*	@file	Input.h
*	@brief	���͏����Ǘ������@Event. �Ə����Ă������o�Ȃ���
*	@author	Photon
*/

#include "../Manager.h"
#include <DxLib.h>

namespace suken {
	/**
	*	@brief�@���͂��Ǘ�����N���X
	*/
	class CInput {
	public:
		struct Key {
			enum KeyCode {
				BACK = KEY_INPUT_BACK,
				TAB = KEY_INPUT_TAB,
				RETURN = KEY_INPUT_RETURN,

				LSHIFT = KEY_INPUT_LSHIFT,
				RSHIFT = KEY_INPUT_RSHIFT,
				LCONTROL = KEY_INPUT_LCONTROL,
				RCONTROL = KEY_INPUT_RCONTROL,
				ESCAPE = KEY_INPUT_ESCAPE,
				SPACE = KEY_INPUT_SPACE,
				PGUP = KEY_INPUT_PGUP,
				PGDN = KEY_INPUT_PGDN,
				END = KEY_INPUT_END,
				HOME = KEY_INPUT_HOME,
				LEFT = KEY_INPUT_LEFT,
				UP = KEY_INPUT_UP,
				RIGHT = KEY_INPUT_RIGHT,
				DOWN = KEY_INPUT_DOWN,
				INSERT = KEY_INPUT_INSERT,
				_DELETE = KEY_INPUT_DELETE,

				MINUS = KEY_INPUT_MINUS,
				YEN = KEY_INPUT_YEN,
				PREVTRACK = KEY_INPUT_PREVTRACK,
				PERIOD = KEY_INPUT_PERIOD,
				SLASH = KEY_INPUT_SLASH,
				LALT = KEY_INPUT_LALT,
				RALT = KEY_INPUT_RALT,
				SCROLL = KEY_INPUT_SCROLL,
				SEMICOLON = KEY_INPUT_SEMICOLON,
				COLON = KEY_INPUT_COLON,
				LBRACKET = KEY_INPUT_LBRACKET,
				RBRACKET = KEY_INPUT_RBRACKET,
				AT = KEY_INPUT_AT,
				BACKSLASH = KEY_INPUT_BACKSLASH,
				COMMA = KEY_INPUT_COMMA,
				CAPSLOCK = KEY_INPUT_CAPSLOCK,
				PAUSE = KEY_INPUT_PAUSE,

				NUMPAD0 = KEY_INPUT_NUMPAD0,
				NUMPAD1 = KEY_INPUT_NUMPAD1,
				NUMPAD2 = KEY_INPUT_NUMPAD2,
				NUMPAD3 = KEY_INPUT_NUMPAD3,
				NUMPAD4 = KEY_INPUT_NUMPAD4,
				NUMPAD5 = KEY_INPUT_NUMPAD5,
				NUMPAD6 = KEY_INPUT_NUMPAD6,
				NUMPAD7 = KEY_INPUT_NUMPAD7,
				NUMPAD8 = KEY_INPUT_NUMPAD8,
				NUMPAD9 = KEY_INPUT_NUMPAD9,
				MULTIPLY = KEY_INPUT_MULTIPLY,
				ADD = KEY_INPUT_ADD,
				SUBTRACT = KEY_INPUT_SUBTRACT,
				DECIMAL = KEY_INPUT_DECIMAL,
				DIVIDE = KEY_INPUT_DIVIDE,
				NUMPADENTER = KEY_INPUT_NUMPADENTER,

				F1 = KEY_INPUT_F1,
				F2 = KEY_INPUT_F2,
				F3 = KEY_INPUT_F3,
				F4 = KEY_INPUT_F4,
				F5 = KEY_INPUT_F5,
				F6 = KEY_INPUT_F6,
				F7 = KEY_INPUT_F7,
				F8 = KEY_INPUT_F8,
				F9 = KEY_INPUT_F9,
				F10 = KEY_INPUT_F10,
				F11 = KEY_INPUT_F11,
				F12 = KEY_INPUT_F12,

				A = KEY_INPUT_A,
				B = KEY_INPUT_B,
				C = KEY_INPUT_C,
				D = KEY_INPUT_D,
				E = KEY_INPUT_E,
				F = KEY_INPUT_F,
				G = KEY_INPUT_G,
				H = KEY_INPUT_H,
				I = KEY_INPUT_I,
				J = KEY_INPUT_J,
				K = KEY_INPUT_K,
				L = KEY_INPUT_L,
				M = KEY_INPUT_M,
				N = KEY_INPUT_N,
				O = KEY_INPUT_O,
				P = KEY_INPUT_P,
				Q = KEY_INPUT_Q,
				R = KEY_INPUT_R,
				S = KEY_INPUT_S,
				T = KEY_INPUT_T,
				U = KEY_INPUT_U,
				V = KEY_INPUT_V,
				W = KEY_INPUT_W,
				X = KEY_INPUT_X,
				Y = KEY_INPUT_Y,
				Z = KEY_INPUT_Z,
				NUM0 = KEY_INPUT_0,
				NUM1 = KEY_INPUT_1,
				NUM2 = KEY_INPUT_2,
				NUM3 = KEY_INPUT_3,
				NUM4 = KEY_INPUT_4,
				NUM5 = KEY_INPUT_5,
				NUM6 = KEY_INPUT_6,
				NUM7 = KEY_INPUT_7,
				NUM8 = KEY_INPUT_8,
				NUM9 = KEY_INPUT_9
			};
		}key;
		struct Mouse {
			enum MouseCode {
				L = 0,
				R = 1,
				M = 2
			};
		}mouse;

		/**
		*	@brief	�R���X�g���N�^
		*/
		CInput();

		/**
		*	@brief	�w�肳�ꂽ�L�[�̓��͏��擾
		*	@param	Input.key�`
		*	@return	������Ă���ԁ@true
		*/
		bool GetKeyDown(Key::KeyCode keyCode);

		/**
		*	@brief	�L�[�̓��͏��擾
		*	@return	������Ă���ԁ@true
		*/
		bool GetKeyDown();

		/**
		*	@brief	�w�肳�ꂽ�L�[�̓��͏��擾
		*	@param	Input.key�`
		*	@return	�����ꂽ�u�ԁ@true
		*/
		bool GetKeyEnter(Key::KeyCode keyCode);

		/**
		*	@brief	�L�[�̓��͏��擾
		*	@return	�����ꂽ�u�ԁ@true
		*/
		bool GetKeyEnter();

		/**
		*	@brief	�w�肳�ꂽ�L�[�̓��͏��擾
		*	@param	Input.key�`
		*	@return	�����ꂽ�u�ԁ@true
		*/
		bool GetKeyExit(Key::KeyCode keyCode);

		/**
		*	@brief	�L�[�̓��͏��擾
		*	@return	�����ꂽ�u�ԁ@true
		*/
		bool GetKeyExit();

		/**
		*	@brief	�w�肳�ꂽ�L�[�̓��͏��擾
		*	@param	Input.key�`
		*	@return	�����ꂽ/�����ꂽ�@��Ԃ���̃t���[�����@��/���@�̒l�̑傫���ŕԂ�
		*/
		int GetKeyCount(Key::KeyCode keyCode);

		/**
		*	@brief	�}�E�X�̓��͏��擾
		*	@param	Input.mouse�`
		*	@return	������Ă���ԁ@true
		*/
		bool GetMouseDown(Mouse::MouseCode mouseCode);
		/**
		*	@brief	�}�E�X�̓��͏��擾
		*	@param	Input.mouse�`�@�͈͎w��
		*	@return	������Ă���ԁ@true
		*/
		bool GetMouseDown(Mouse::MouseCode mouseCode, int x1, int y1, int x2, int y2);

		/**
		*	@brief	�}�E�X�̓��͏��擾
		*	@return	������Ă���ԁ@true
		*/
		bool GetMouseDown();
		/**
		*	@brief	�}�E�X�̓��͏��擾
		*	@param	�͈͎w��
		*	@return	������Ă���ԁ@true
		*/
		bool GetMouseDown(int x1, int y1, int x2, int y2);

		/**
		*	@brief	�}�E�X�̓��͏��擾
		*	@return	������Ă��Ȃ��ԁ@true
		*/
		bool GetMouseOver();
		/**
		*	@brief	�}�E�X�̓��͏��擾
		*	@param	�͈͎w��
		*	@return	������Ă��Ȃ��ԁ@true
		*/
		bool GetMouseOver(int x1, int y1, int x2, int y2);

		/**
		*	@brief	�}�E�X�̓��͏��擾
		*	@param	Input.mouse�`
		*	@return	�����ꂽ�u�ԁ@true
		*/
		bool GetMouseEnter(Mouse::MouseCode mouseCode);
		/**
		*	@brief	�}�E�X�̓��͏��擾
		*	@param	Input.mouse�`�@�͈͎w��
		*	@return	�����ꂽ�u�ԁ@true
		*/
		bool GetMouseEnter(Mouse::MouseCode mouseCode, int x1, int y1, int x2, int y2);

		/**
		*	@brief	�}�E�X�̓��͏��擾
		*	@return	�����ꂽ�u�ԁ@true
		*/
		bool GetMouseEnter();
		/**
		*	@brief	�}�E�X�̓��͏��擾
		*	@param	�͈͎w��
		*	@return	�����ꂽ�u�ԁ@true
		*/
		bool GetMouseEnter(int x1, int y1, int x2, int y2);

		/**
		*	@brief	�}�E�X�̓��͏��擾
		*	@param	Input.mouse�`
		*	@return	�����ꂽ�u�ԁ@true
		*/
		bool GetMouseExit(Mouse::MouseCode mouseCode);
		/**
		*	@brief	�}�E�X�̓��͏��擾
		*	@param	Input.mouse�`�@�͈͎w��
		*	@return	�����ꂽ�u�ԁ@true
		*/
		bool GetMouseExit(Mouse::MouseCode mouseCode, int x1, int y1, int x2, int y2);

		/**
		*	@brief	�}�E�X�̓��͏��擾
		*	@return	�����ꂽ�u�ԁ@true
		*/
		bool GetMouseExit();
		/**
		*	@brief	�}�E�X�̓��͏��擾
		*	@param	�͈͎w��
		*	@return	�����ꂽ�u�ԁ@true
		*/
		bool GetMouseExit(int x1, int y1, int x2, int y2);

		/**
		*	@brief	�}�E�X�̓��͏��擾
		*	@return	X���W
		*/
		int GetMouseX();

		/**
		*	@brief	�}�E�X�̓��͏��擾
		*	@return	Y���W
		*/
		int GetMouseY();

		/**
		*	@brief	�}�E�X�̓��͏��擾
		*	@return	�x�N�g��
		*/
		Twin<int> GetMouseVector();

		/**
		*	@brief	�}�E�X�̓��͏��擾
		*	@return �}�E�X�z�C�[���̓��͏��
		*/
		int GetMouseWheel();

	private:
		int keyInput[256];

		int mouseX;
		int mouseY;
		int mouseWheel;
		bool mouseInput[3];
		bool mouseInputLast[3];

		void Loop();
		friend class CSystem;
	};
}