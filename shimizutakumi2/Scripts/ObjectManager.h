#pragma once

template<class T>
class Factory {
public:
	Factory() = default;
	~Factory() = default;
	virtual std::shared_ptr<T> Create(std::vector<int>& index) = 0;
};

//汎用オブジェクト管理クラス
template<class T>
class ObjectManager {
public:
	typedef std::shared_ptr<T> TPtr;
	typedef std::list<TPtr> TList;
	ObjectManager() :factory(nullptr) {}
	~ObjectManager() {
		if (this->factory != nullptr)
			delete this->factory;
	}

	void SetFactory(Factory<T>* factory) {
		if (this->factory != nullptr)
			delete this->factory;
		this->factory = factory;
	}

	bool Create(std::vector<int>& request) {
		if (factory != nullptr) {
			buffer.push_back(factory->Create(request));
			return true;
		}
		return false;
	}

	void Create(std::shared_ptr<T> ptr) {
		buffer.push_back(ptr);
	}

	TList& GetList() {
		return list;
	}

	TList& GetRecent() {
		return recent;
	}

	void Update() {
		/*for (auto it = list.begin(), end = list.end(); it != end;) {
			if (it->use_count() == 1) {
				it = list.erase(it);
			}
			else {
				++it;
			}
		}*/
		recent = buffer;
		if (!buffer.empty()) {
			list.splice(list.end(), buffer);
			buffer.clear();
		}
	}

	void Do(void (T::* func)()) {
		for (auto it = list.begin(), end = list.end(); it != end; ++it) {
			(it->get()->*func)();
		}
	}

private:
	TList list, buffer, recent;
	Factory<T>* factory;
};

template<class T>
using OM = ObjectManager<T>;