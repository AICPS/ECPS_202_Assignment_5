### Readme for the RAMBO project.

- Sample PLC program written in Structured Test can be found under [st_files](webserver/st_files) directory. 
- Currently I am using the program in [ENERGY.st](webserver/st_files/ENERGY.ST) in our PLC dataset repository.  

- To build the project, please follow the readme file. 

### How To Compile PLC programs:
- Change your directory to webserver
```
cd webserver
```
- To convert iec code to C code. 
Run
```
./iec2c st_files/ENERGY.ST 
```
You will get the following result as a result of converting ST code to C code. 
```
POUS.c
POUS.h
LOCATED_VARIABLES.h
VARIABLES.csv
Config0.c
Config0.h
Res0.c
```

- To compile the ST code directly.

```
./scripts/compile_program.sh ENERGY.ST 
```

- The compiled binary will be stored under [webserver/core](webserver/core) directory with the converted C files. 
- The binary will have the basename of the PLC file. For example for `ENERGY.ST`, it will be `ENERGY`.
- From the converted files, the main logic of the PLC, that means the Funcions and Function blocks that we defined in the ST file can be found in under [POUS.c](webserver/core/POUS.c). I have checked that we can use gdb when running the compiled ST binary and set a breakpoint/debugging point under the functions/function blocks. 
