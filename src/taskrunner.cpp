#include "taskrunner.h"
#include <QThread>
#include <iostream>

TaskRunner::TaskRunner(forensictool::ITask *pTask){
	m_pTask = pTask;
}

void TaskRunner::run(){
	m_pTask->execute();
}
