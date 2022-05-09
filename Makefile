SRCDIR = ./src
INCDIR = ./include
TESTDIR = ./test
EXECDIR = ./exec

# Linked list
LISTINC = $(INCDIR)/linked_list
LISTSRC = $(SRCDIR)/linked_list
LISTTEST = $(TESTDIR)/linked_list

# LL Generator
READERSRC = $(SRCDIR)/reader
READERINC = $(INCDIR)/reader

# CDG
CDGINC = $(INCDIR)/cdg
CDGSRC = $(SRCDIR)/cdg
CDGTEST = $(TESTDIR)/cdg

# CFG
CFGINC = $(INCDIR)/cfg
CFGSRC = $(SRCDIR)/cfg
CFGTEST = $(TESTDIR)/cfg

# CFG
PARSERINC = $(INCDIR)/parser
PARSERSRC = $(SRCDIR)/parser
PARSERTEST = $(TESTDIR)/parser

# test-----------------------
test_list: $(LISTTEST)/list_test.cpp $(LISTSRC)/list_ops.cpp $(SRCDIR)/node.cpp $(LISTINC)/list_ops.hpp $(INCDIR)/node.hpp
	g++ -o $(EXECDIR)/test_list $(LISTTEST)/list_test.cpp $(LISTSRC)/list_ops.cpp $(SRCDIR)/node.cpp

test_cdg: $(CDGTEST)/cdg_test.cpp $(CDGSRC)/cdg.cpp $(LISTSRC)/list_ops.cpp $(SRCDIR)/node.cpp $(CDGINC)/cdg.hpp $(LISTINC)/list_ops.hpp $(INCDIR)/node.hpp
	g++ -o $(EXECDIR)/test_cdg $(CDGTEST)/cdg_test.cpp $(CDGSRC)/cdg.cpp $(LISTSRC)/list_ops.cpp $(SRCDIR)/node.cpp


test_reader: $(INCDIR)/node.hpp $(SRCDIR)/node.cpp $(READERSRC)/ll_generator.cpp $(PARSERSRC)/lex.yy.c $(PARSERINC)/parser_headers.h
	g++ -o $(EXECDIR)/ll_gen $(READERSRC)/ll_generator.cpp $(PARSERSRC)/lex.yy.c $(SRCDIR)/node.cpp

test_cfg: $(INCDIR)/node.hpp $(CFGINC)/cfg.hpp $(CDGINC)/cdg.hpp $(LISTSRC)/list_ops.cpp $(CFGSRC)/cfg.cpp $(CDGSRC)/cdg.cpp $(LISTINC)/list_ops.hpp $(SRCDIR)/node.cpp
	g++ -o $(EXECDIR)/test_cfg $(CFGTEST)/cfg_test.cpp $(CFGSRC)/cfg.cpp $(CDGSRC)/cdg.cpp $(LISTSRC)/list_ops.cpp $(SRCDIR)/node.cpp

# ----------------------------
parser: $(PARSERINC)/parser_headers.h $(PARSERSRC)/Parser.l
	flex -o $(PARSERSRC)/lex.yy.c $(PARSERSRC)/Parser.l

ll_generator.o: $(READERSRC)/ll_generator.cpp $(READERINC)/ll_generator.hpp
	g++ -c $(READERSRC)/ll_generator.cpp

node.o: $(INCDIR)/node.hpp $(SRCDIR)/node.cpp
	g++ -c $(SRCDIR)/node.cpp

list_ops.o: $(LISTSRC)/list_ops.cpp $(LISTINC)/list_ops.hpp
	g++ -c $(LISTSRC)/list_ops.cpp

cdg.o: $(CDGSRC)/cdg.cpp $(CDGINC)/cdg.hpp
	g++ -c $(CDGSRC)/cdg.cpp

cfg.o: $(CFGSRC)/cfg.cpp $(CFGINC)/cfg.hpp
	g++ -c $(CFGSRC)/cfg.cpp

all: main.cpp parser $(PARSERINC)/parser_headers.h ll_generator.o node.o list_ops.o cdg.o cfg.o
	g++ -o cfg_gen main.cpp $(PARSERSRC)/lex.yy.c ll_generator.o node.o list_ops.o cdg.o cfg.o

clean:
	rm ./exec/* *.o