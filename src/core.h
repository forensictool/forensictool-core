#ifndef __FORENSICTOOL_CORE_H__
#define __FORENSICTOOL_CORE_H__

#include "interfaces/forensictool.h"
#include <QString>
#include <QVector>
#include <QLibrary>

class Core : public forensictool::ICore {
	public:
		Core();
		
		// forensictool::ICore
		virtual void loadPluginsByPath(const QString &fullpathToFolder);
		virtual void loadPluginsFromSystem();
		virtual bool loadPlugin(const QString &fullpathToPlugin);
		virtual QVector<forensictool::ITask *> &tasks();
		virtual QVector<forensictool::IDetectorOperationSystem *> &detectors();
		virtual void setMaxThreads(int nMaxThreads);
		virtual void run(forensictool::IConfig *pConfig);
		
	private:
		QString pathToPluginsSystem();
		QString filter();
		QVector<forensictool::ITask *> m_vTasks;
		QVector<forensictool::IDetectorOperationSystem *> m_vDetectors;
		QVector<QLibrary*> m_vLibraries;
		int m_nMaxThreads;
};

#endif //__FORENSICTOOL_CORE_H__
