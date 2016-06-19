# сoex-core

The software for computer forensics within the framework of judicial proceedings, and designed to facilitate the collection of information on the suspect computer.

## Build single app:

`$ ./build_app.sh`


## Run single app:

	$ ./bin/coex-cli -i ../coex-testdata/Windows7_Ult/ -o ~/coex.output

	The software for computer forensics within the framework of judicial proceedings, and designed to facilitate the collection of information on the suspect computer.

	  Usage: ./bin/coex-cli [OPTIONS] 

	  OPTIONS:

		-i <path>           - Input folder, required parameter
		-o <path>           - Output folder, optional parameter (default: {homefolder}/coex.output )
		-l                  - List of plugins, optional parameter
		-p <path1;path2>    - Plugins path, optional parameter
		-h/--help           - this help

	  EXAMPLE USAGE:

		$ ./bin/coex-cli -i ~/copywinhard1/ -o ~/copywinhard1.coex/ 

	  VERSION: 0.2.0
