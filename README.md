# forensictool-core

The software for computer forensics within the framework of judicial proceedings, and designed to facilitate the collection of information on the suspect computer.

## Build single app:

`$ ./build_app.sh`


## Run single app:

	$ ./bin/forensictool-cli -i ../forensictool-testdata/Windows7_Ult/ -o ~/forensictool.output

	The software for computer forensics within the framework of judicial proceedings, and designed to facilitate the collection of information on the suspect computer.

	  Usage: ./bin/forensictool-cli [OPTIONS] 

	  OPTIONS:

		-i <path>           - Input folder, required parameter
		-o <path>           - Output folder, optional parameter (default: {homefolder}/forensictool.output )
		-l                  - List of plugins, optional parameter
		-p <path1;path2>    - Plugins path, optional parameter
		-h/--help           - this help

	  EXAMPLE USAGE:

		$ ./bin/forensictool-cli -i ~/copywinhard1/ -o ~/copywinhard1.forensictool/

	  VERSION: 0.2.0
