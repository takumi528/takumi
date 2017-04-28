#pragma once

/**
*	@file	Object.h
*	@brief	マルチなマネージャーをテンプレートクラスで実現しました
*	@author	Photon
*/

#include <vector>

namespace suken {

	/**
	*	@brief マネージャーを利用するオブジェクトが継承する　たいしたことは書いてない
	*/
	class CObject {
	public:
		CObject();

		/**
		*	@brief オブジェクト消去
		*/
		void Delete();

		/**
		*	@brief 消去フラグ取得
		*/
		bool GetDeleteFlag();

	private:
		bool deleteFlag;
	};

	template<class Ty>
	class ObjectManagerIterator;

	/**
	*	@brief マルチマネージャー　イテレーターを持ち、STLのAlgorithmが使える(forword_iterator対応)
	*/
	template<class Object>
	class CManager {
	public:
		typedef ObjectManagerIterator<Object> iterator;

		CManager() {}

		/**
		*	@brief	マネージャー内のすべてのオブジェクトの指定したメンバ関数を実行
		*	@param	オブジェクトのメンバ関数ポインタ　(例)　&Object::関数名
		*/
		void Do(void(Object::*func)()) {
			for (auto it = Begin(), end = End(); it != end;++it) {
				((*it)->*func)();
			}
		}

		/**
		*	@brief	オブジェクト登録
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
		*	@brief	Drawの終わりに毎週呼ぼう!
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
	*	@brief 自作イテレーター
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