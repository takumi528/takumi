#pragma once

#include <list>
#include <memory>

class Task {
public:
	Task() :isAvailable(true) {}
	~Task() = default;

	void SetIsAvailable(bool flag) {
		isAvailable = flag;
	}

	bool GetIsAvailable() {
		return isAvailable;
	}

	virtual void Main() = 0;
private:
	bool isAvailable;
};

class TaskManager {
public:
	typedef std::unique_ptr<Task> TaskPtr;
	TaskManager() = default;
	~TaskManager() = default;

	void RegisterTask(Task* task) {
		this->task.push_back(TaskPtr(task));
	}

	void Main() {
		Task *ptr;
		for (auto it = task.begin(), end = task.end(); it != end; ++it) {
			ptr = it->get();
			if (ptr->GetIsAvailable()) {
				ptr->Main();
			}
		}
	}
private:
	std::list<TaskPtr> task;
};