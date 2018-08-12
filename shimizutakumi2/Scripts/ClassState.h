#pragma once

class AbstractFuncHolder {
public:
	AbstractFuncHolder() = default;
	~AbstractFuncHolder() = default;
	virtual bool Main() = 0;
};

template<class T>
class FuncHolder :public AbstractFuncHolder {
public:
	typedef bool (T::* funcPtr)();
	FuncHolder(T* ptr, funcPtr func) :ptr(ptr), func(func) {}
	~FuncHolder() = default;
	bool Main() {
		return (ptr->*func)();
	}
private:
	T*const ptr;
	funcPtr func;
};

class State {
public:
	template<class T>
	State(T *const ptr, bool (T::* func)()) :func(new FuncHolder<T>(ptr, func)), next(nullptr) {}

	~State() {
		if (func != nullptr)
			delete func;
		if (next != nullptr)
			delete next;
	}

	bool Main() {
		if (func->Main()) {
			if (func != nullptr && next != nullptr) {
				delete func;
				func = next;
				next = nullptr;
				return true;
			}
			else {
				throw "Ÿ‚Ìó‘Ô‚ªİ’è‚³‚ê‚È‚¢‚Ü‚Üó‘ÔŠÖ”‚Åfalse‚ª•Ô‚³‚ê‚Ü‚µ‚½";
			}
		}
		return false;
	}

	template<class T>
	bool SetNextState(T *const ptr, bool (T::* func)()) {//SetNextState(this, &Player::Normal)‚Ì‚æ‚¤‚Ég‚¤
		if (next == nullptr) {
			next = new FuncHolder<T>(ptr, func);
			return true;
		}
		return false;
	}
private:
	AbstractFuncHolder *func, *next;
};