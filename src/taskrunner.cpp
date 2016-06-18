#include "taskrunner.h"
#include <QThread>
#include <iostream>

TaskRunner::TaskRunner(coex::ITask *pTask){
	m_pTask = pTask;
}

void TaskRunner::run(){
	m_pTask->execute();
}
