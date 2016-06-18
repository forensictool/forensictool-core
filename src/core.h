#ifndef __COEX_CORE_H__
#define __COEX_CORE_H__

#include "interfaces/coex.h"
#include <QString>
#include <QVector>
#include <QLibrary>

class Core : public coex::ICore {
	public:
		Core();
		
		// coex::ICore
		virtual void loadPluginsByPath(const QString &fullpathToFolder);
		virtual void loadPluginsFromSystem();
		virtual bool loadPlugin(const QString &fullpathToPlugin);
		virtual QVector<coex::ITask *> &tasks();
		virtual QVector<coex::IDetectorOperationSystem *> &detectors();
		virtual void setMaxThreads(int nMaxThreads);
		virtual void run(coex::IConfig *pConfig);
		
	private:
		QString pathToPluginsSystem();
		QString filter();
		QVector<coex::ITask *> m_vTasks;
		QVector<coex::IDetectorOperationSystem *> m_vDetectors;
		QVector<QLibrary*> m_vLibraries;
		int m_nMaxThreads;
};

#endif //__COEX_CORE_H__
