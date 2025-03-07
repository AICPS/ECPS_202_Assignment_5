
**Requirements:** This guide assumes you are using a Linux platform or Windows Subsystem for Linux (WSL). Either wise, please setup a linux VM (Ubuntu 24.04 LTS should be enough) for the assignment.

### Clone the following repository and change your directory to the assignment folder
```
git clone https://github.com/AICPS/ECPS_202_Assignment_5.git
cd ECPS_202_Assignment_5
```
### Init submodules
```
git submodule update --init --recursive
```

### Build openplc and matiec
NB: It may require sudoers permission
```
cd openplc
./install.sh linux
cd ../
```


### Compile PLC programs:
- Change your directory to openplc/webserver/scripts
```
cd openplc/webserver/scripts
```
- Use the provided shell script to compile the program.  
Run
```
../compile_program.sh [path to your PLC program written in Structured Text]
``` 

For example, to compile the sample program.
```
./compile_program.sh ../../../st_files/ENERGY.ST
```

If you save your generated code inside the same directory as `ENERGY.ST` with `TempratureController.st` name:
```
./compile_program.sh ../../../st_files/TempratureController.st
```

You will find the resulting binary under the [st_files](./st_files/) directory.
