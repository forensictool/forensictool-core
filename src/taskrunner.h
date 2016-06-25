#ifndef __FORENSICTOOL_TASKRUNNER_H__
#define __FORENSICTOOL_TASKRUNNER_H__

#include "forensictool.h"
#include <QRunnable>

class TaskRunner : public QRunnable {
	public:
		TaskRunner(forensictool::ITask *pTask);
		virtual void run();
	private:
		forensictool::ITask *m_pTask;
};


#endif // __FORENSICTOOL_TASKRUNNER_H__
