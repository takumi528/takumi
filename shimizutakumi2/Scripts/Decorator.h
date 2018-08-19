#pragma once

#include "sukenlib\Utility\Graph.h"

#include "Coord.h"

class AbstractDrawing {
public:
	AbstractDrawing() = default;
	virtual ~AbstractDrawing() = default;
	virtual void Draw() = 0;
};

template<class T>
class Drawing :public AbstractDrawing {
public:
	typedef void (T::* funcPtr)();
	Drawing(T* ptr, funcPtr func) :ptr(ptr), func(func) {}
	~Drawing() = default;
	void Draw() {
		(ptr->*func)();
	}
	void Set(funcPtr func) {
		this->func = func;
	}
private:
	T*const ptr;
	funcPtr func;
};

class GraphHolder :public AbstractDrawing {
public:
	GraphHolder() :GraphHolder(nullptr, nullptr) {}
	GraphHolder(Graph* graph, Coord* c) :graph(graph),c(c), dx(0), dy(0), index(0), turnFlag(false) {}
	virtual ~GraphHolder() = default;

	void Set(int dx, int dy, int index = 0 , bool turnFlag = false) {
		this->dx = dx;
		this->dy = dy;
		this->index = index;
		this->turnFlag = turnFlag;
	}

	void Reset(Graph *graph, Coord *c) {
		this->graph = graph;
		this->c = c;
	}

	void Draw() {
		graph[index](dx + c->x, dy + c->y, turnFlag);
	}

private:
	Graph *graph;
	Coord *c;
	int dx, dy, index;
	bool turnFlag;
};

class AbstractDecorator : AbstractDrawing {
public:
	AbstractDecorator(AbstractDrawing* draw, bool isDeletePtr = false) :draw(draw), isDeletePtr(isDeletePtr) {}
	virtual ~AbstractDecorator() {
		if (isDeletePtr && draw != nullptr) {
			delete draw;
			draw = nullptr;
		}
	}
	virtual void Draw() = 0;
	virtual void Draw(AbstractDrawing* draw) = 0;
	void Set(AbstractDrawing* draw) {
		if (isDeletePtr && this->draw != nullptr) {
			delete this->draw;
			this->draw = nullptr;
		}
		this->draw = draw;
	}
protected:
	AbstractDrawing* draw;
	bool isDeletePtr;
};

template<class T>
class Decorator {
	typedef void (T::* funcPtr)(AbstractDrawing*);
	Decorator(T* ptr, funcPtr func, AbstractDrawing* draw = nullptr, bool isDeletePtr = false) :AbstractDecorator(ptr, isDeletePtr), func(func), draw(draw) {}
	virtual ~Decorator() = default;
	void Draw() {
		(ptr->*func)(draw);
	}
	void Draw(AbstractDrawing* draw) {
		(ptr->*func)(draw);
	}
	void Set(funcPtr func) {
		this->func = func;
	}
private:
	T*const ptr;
	funcPtr func;
};