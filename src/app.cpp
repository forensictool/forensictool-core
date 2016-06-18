#include "core.h"
#include "helpers/config.h"
#include <iostream>
#include <QStringList>
#include <QDir>

void printHelp(QStringList &args){
	std::cout << "\nThe software for computer forensics within the framework of judicial proceedings, and designed to facilitate the collection of information on the suspect computer.\n\n";
	std::cout << "  Usage: " << args[0].toStdString() << " [OPTIONS] \n\n";
	std::cout << "  OPTIONS:\n\n";
	std::cout << "    -i <path>           - Input folder, required parameter\n";
	std::cout << "    -o <path>           - Output folder, optional parameter (default: {homefolder}/coex.output )\n";
	std::cout << "    -l                  - List of plugins, optional parameter\n";
	std::cout << "    -p <path1;path2>    - Plugins path, optional parameter\n";
	std::cout << "    -h/--help           - this help\n";
	std::cout << "\n";
	std::cout << "  EXAMPLE USAGE:\n\n";
	std::cout << "    $ " << args[0].toStdString() << " -i ~/copywinhard1/ -o ~/copywinhard1.coex/ \n";
	std::cout << "\n";
	std::cout << "  VERSION: " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_BUILD << "\n";
	std::cout << "\n";
}

int main(int argc, char* argv[])
{
	QStringList args;
	for(int i = 0; i < argc; i++){
		args << QString(argv[i]);
	}
	
	Core *pCore = new Core();
	pCore->loadPluginsFromSystem();

	Config *pConfig = new Config();
	pConfig->setParameters(args);

	if(args.contains("-l")){
		std::cout << "\n";
		std::cout << "DETECTORS:\n";
		QVector<coex::IDetectorOperationSystem *> detectors = pCore->detectors();
		for(int i = 0; i < detectors.size(); i++){
			std::cout << detectors[i]->name().toStdString() << "\n";
		}
		
		std::cout << "TASKS:\n";
		QVector<coex::ITask *> tasks = pCore->tasks();
		for(int i = 0; i < tasks.size(); i++){
			std::cout << tasks[i]->name().toStdString() << "\n";
		}
		return 0;
	}

	if(args.contains("-h") || args.contains("--help")){
		printHelp(args);
		return -1;
	}
	
	if(!args.contains("-i")){
		std::cerr << "\nERROR: Could not found parameter '-i' please see help '--help'\n\n";
		return -2;
	}
	
	QString inputFolder = "";
	if(args.contains("-i") && args.indexOf("-i") + 1 > args.size()){
		std::cerr << "\nERROR: Could not found path for '-i' please see help '--help'\n\n";
		printHelp(args);
		return -3;
	}else{
		pConfig->setInputFolder(args[args.indexOf("-i") + 1]);
	}
	
	QString outputFolder = QDir::home().absolutePath() + "/coex.output";
	if(args.contains("-o") && args.indexOf("-o") + 1 < args.size()){
		outputFolder = args[args.indexOf("-o") + 1];
	}

	if(args.contains("-p") && args.indexOf("-p") + 1 < args.size()){
		QString p = args[args.indexOf("-p") + 1];
		QStringList paths = p.split(";");
		for(int i = 0; i < paths.size(); i++){
			pCore->loadPluginsByPath(paths[i]);
		}
	}
	
	pConfig->setOutputFolder(outputFolder);    
	pCore->run(pConfig);
	return 0;
}
