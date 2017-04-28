#pragma once

/**
*	@file	Object.h
*	@brief	�}���`�ȃ}�l�[�W���[���e���v���[�g�N���X�Ŏ������܂���
*	@author	Photon
*/

#include <vector>

namespace suken {

	/**
	*	@brief �}�l�[�W���[�𗘗p����I�u�W�F�N�g���p������@�����������Ƃ͏����ĂȂ�
	*/
	class CObject {
	public:
		CObject();

		/**
		*	@brief �I�u�W�F�N�g����
		*/
		void Delete();

		/**
		*	@brief �����t���O�擾
		*/
		bool GetDeleteFlag();

	private:
		bool deleteFlag;
	};

	template<class Ty>
	class ObjectManagerIterator;

	/**
	*	@brief �}���`�}�l�[�W���[�@�C�e���[�^�[�������ASTL��Algorithm���g����(forword_iterator�Ή�)
	*/
	template<class Object>
	class CManager {
	public:
		typedef ObjectManagerIterator<Object> iterator;

		CManager() {}

		/**
		*	@brief	�}�l�[�W���[���̂��ׂẴI�u�W�F�N�g�̎w�肵�������o�֐������s
		*	@param	�I�u�W�F�N�g�̃����o�֐��|�C���^�@(��)�@&Object::�֐���
		*/
		void Do(void(Object::*func)()) {
			for (auto it = Begin(), end = End(); it != end;++it) {
				((*it)->*func)();
			}
		}

		/**
		*	@brief	�I�u�W�F�N�g�o�^
		*/
		void Regist(Object* object) {
			for (auto it = Begin(), end = End(); it != end; ++it) {
				if (*it == nullptr) {
					*it = object;
					return;
				}
			}
			obj.push_back(object);
		}

		/**
		*	@brief	Draw�̏I���ɖ��T�Ăڂ�!
		*/
		void LoopEnd() {
			for (auto it = Begin(), end = End(); it != end; ++it) {
				if (it->GetDeleteFlag()) {
					delete *it;
					*it = nullptr;
				}
			}
		}

		iterator Begin() {
			return iterator(obj, true);
		}

		iterator End() {
			return iterator(obj, false);
		}

		int Size() {
			std::distance(Begin(), End());
		}

		bool Empty() {
			return Begin() == End();
		}

	private:
		std::vector<Object*> obj;
	};

	/**
	*	@brief ����C�e���[�^�[
	*/
	template<class Ty>
	class ObjectManagerIterator :public std::iterator<std::forward_iterator_tag, Ty, std::ptrdiff_t, Ty*, Ty&> {
	private:
		ObjectManagerIterator(std::vector<Ty*>& obj, bool isBegin):obj(obj) {
			if (isBegin) {
				index = 0;
				while (index < obj.size() && obj[index] == nullptr) {
					++index;
				}
			}
			else {
				index = obj.size();
			}
		}
	public:
		ObjectManagerIterator<Ty>& operator++() {
			do {
				++index;
			} while (index < obj.size() && obj[index] == nullptr);

			return *this;
		}
		ObjectManagerIterator<Ty> operator++(int) {
			ObjectManagerIterator<Ty> buf = *this;
			do {
				++index;
			} while (index < obj.size() && obj[index] == nullptr);

			return buf;
		}

		Ty*& operator*() {
			return obj[index];
		}

		Ty* operator->() {
			return obj[index];
		}

		bool operator==(const ObjectManagerIterator<Ty>& iterator) {
			return index == iterator.index;
		}
		bool operator!=(const ObjectManagerIterator<Ty>& iterator) {
			return index != iterator.index;
		}

		std::vector<Ty*>& obj;
		int index;

		friend class CManager<Ty>;
	};
}