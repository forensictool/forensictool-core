#ifndef __COEX_TASKRUNNER_H__
#define __COEX_TASKRUNNER_H__

#include "coex.h"
#include <QRunnable>

class TaskRunner : public QRunnable {
	public:
		TaskRunner(coex::ITask *pTask);
		virtual void run();
	private:
		coex::ITask *m_pTask;
};


#endif // __COEX_TASKRUNNER_H__
