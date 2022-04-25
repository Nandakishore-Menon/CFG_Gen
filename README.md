# PL Project: Control Flow Graphs Generator

### Nandakishore S Menon | IMT2019057
### Rachna S Kedigehalli | IMT2019069
### Yashovardhan Reddy | IMT2019097
### Lalith Kumar Reddy G | IMT2019509

#

## Problem Description

It is difficult to comprehend the behavior of a program from its source code. It is important to know how a program behaves in different situations in order to prevent errors, crashes and other unexpected runtime behavior. Information about the behaviour of the program can be extracted with static analysis of the code, i.e. by drawing its **control flow graph**, which outlines all possible paths that might be traversed when the program is executed. 

![CFG Example](/images/CFG_Figure.png "CFG Example")

However, doing so by hand can become taxing for large and complex programs and is prone to errors. The problem statement is to construct a tool that would draw the control flow graphs given syntactically correct programs(assuming the programs given to it compiles).

#

## Solution Outline

A block in a code is sequence of instructions is the program which have one entry point and one exit point. A control flow graph is a directed graph which shows the control flow paths in a program using edges between nodes which represent blocks. So the control flow graph shows all possible paths that a program might take while executing. 

We will be building a tool CFG_generator to draw the CFG for a given c program. The tool can generate CFGs for programs which do not have syntax errors and which successfully compile. This tool is implemented in ```C++``` programming language.

#

## References

[Automating Control-Flow Graph Generation from Source Code](https://libraetd.lib.virginia.edu/downloads/4t64gn77x?filename=Le\_Kenneth\_Technical\_Report.pdf): This paper introduces an automated test requirement generation prototype tool, which generates control-flow graphs from program source code. This paper analyzes the quality of generated control-flow graphs by examining the effectiveness of tests derived from control-flow graphs. 

[StatiCFG](https://github.com/coetaur0/staticfg): StatiCFG is a package that can be used to produce control flow graphs (CFGs) for Python 3 programs. The CFGs it generates can be easily visualised with graphviz and used for static analysis. This analysis is actually the main purpose of the module.
