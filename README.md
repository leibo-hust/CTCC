# RCCT
A compiler tool that converts LLVM IR into CIM-executable code.

## Introduction
CTCC is a tool for converting LLVM IR to computing in memory (**CIM**) recognizable and accelerable target code. Its goal is to use ReRAM and accelerate applications without modifying the source code and without source code. Four accelerable patterns are currently supported: matrix-vector multiplication (MVM), matrix-matrix multiplication (MMM), cblas library functions, and bitmap logic operations.  

So far, we have supported many different loop structures, data types and dependencies. The support is shown in the table below.

### All supported forms

| Item        |  Form 1   | Form 2  | Form 3   | Form 4  |
| :--------:  | :-----  | :----  |:-----  | :----  |
| Vector      | float A[6];   |   float A[] = {...};     | float *A= malloc(...); | float *A  = new float[10];  |
| Matrix      |   float W[6][8];   |   float W[] = {...};   | float *W= malloc(...); | float *W  = new float[10]; |
| Loop mode   |    for    |  while  |
| Loop form   |    for(i = 0; i < 10; i++)  |  for(i = 0; i <= 9; i++)  |  while(i < 10) {i++}  |  while(i >= 0) {i--} |
|    |    i = 0; <br> for(; i < 10; i++)  |  i = 0; <br> for(; i <= n; i++)  |
|    |    int n = 10; <br> for(i = 0; i < n; i++)  |  int n = 9; <br> for(i = 0; i <= n; i++)  | int n = 10; <br> while(i < n) {i++} | int n = 9; <br> while(i >= 0) {i--} |
| Loop form sum |    slt (i < 10 / n)   |  sle (i <= 9 / n)  |  sgt (i > -1)  |  sge (i >= 0) |
| Dependence  |   mul = b * c; <br> e = mul + d; (direct)  | mul = b * c; <br> f = mul <br> e = f + d; (indirect) | 
| Date Type  |  int | float | double | short |
| Generic form | c=A * b | C=A * B | cblas_xxxx(alpha=1， beta=0...) | c = a logic b |

## Install
### Step 1: Clone the repository
    git clone https://github.com/RCCT 
    cd RCCT 
    
### Step 2: Build
Just run the makefile to make.

    make


### Step 3: Setup the Environment
Copy **librcct.so** to **/usr/lib** or set the **LD_LIBRARY_PATH** variable.

    cp librcct.so /usr/lib/librcct.so
    
Or

    export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH)


## Usage
We've provided a sample file called **mvm.ll** in the ___IR___ directory. You can compile and run the code directly and see the result of the example: a **mvm_add.ll** file will appear in the ___IR___ directory, which is the newly created file. For your own LLVM IR files, you need to follow these steps.

### Step 1: Get the IR file.
First you need to get the corresponding LLVM IR file.

#### Compile
For compilation, we use **clang/clang++** to compile the source code to LLVM IR(.ll).

    clang/clang++ source.c/cpp -emit-llvm -S -fno-discard-value-names -o source.ll

#### Decompile
For decompilation, we use [McSema](https://github.com/lifting-bits/mcsema) to lift the binary to LLVM IR (.ll). First, you shoud install the McSema, then use the follow command to lift the binary to IR.

    mcsema-dyninst-disass --os linux --arch amd64 --output source.cfg --binary source --entrypoint main --std_defs Docs/linux.txt
    mcsema-lift-9.0 --os linux --arch amd64 --cfg source.cfg --output source.bc --abi_libraries Docs/abi.bc --explicit_args --explicit_args_count 8
    llvm-dis source.bc -o source.ll

### Step 2: Add your source file.
Add the source files (compiled or decompiled LLVM IR (.ll)) you need to convert to the **RCCT** directory.

### Step 3: Modify file name.
Change the ___filename___ variable in ___mian.cpp___ to your own filename. For example, if your source file is: **test.ll**, then change the ___filename___ variable to ___test___.

    string filename = "test";

### Step 4: Specifies the isDecompile variable.
Specifies whether the IR is compiled or decompiled. In **function.h**, there is an **isDecompile variable**. If IR is compiled, then set it to ___false___; if it is decompiled, then set it to ___false___.

     bool isDecompile = false;

### Step 5: Re-make.
Recompile the code and run.

    make
    ./main

At the end of the run, you'll get a new file - ***your filename _add.ll*** (for example: test_add.ll), which is the target file. You can recompile and execute it.

### Step 6: Recompile the target code.
Use the follow command to recompile the target code into an executable program that can run under the **CIM** architecture.

    clang -rdynamic -o source_new.out source_add.ll /usr/local/lib/libmcsema_rt64-9.0.a -Wno-unknown-warning-option -Wno-override-module -Wall -Werror -lm -m64 -lopenblas -lrcct

