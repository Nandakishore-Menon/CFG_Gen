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

test_list: $(LISTTEST)/list_test.cpp $(LISTSRC)/list_ops.cpp $(SRCDIR)/node.cpp $(LISTINC)/list_ops.hpp $(INCDIR)/node.hpp
	g++ -o $(EXECDIR)/test_list $(LISTTEST)/list_test.cpp $(LISTSRC)/list_ops.cpp $(SRCDIR)/node.cpp


test_cdg: $(CDGTEST)/cdg_test.cpp $(CDGSRC)/cdg.cpp $(LISTSRC)/list_ops.cpp $(SRCDIR)/node.cpp $(CDGINC)/cdg.hpp $(LISTINC)/list_ops.hpp $(INCDIR)/node.hpp
	g++ -o $(EXECDIR)/test_cdg $(CDGTEST)/cdg_test.cpp $(CDGSRC)/cdg.cpp $(LISTSRC)/list_ops.cpp $(SRCDIR)/node.cpp

parser: $(PARSERINC)/parser_headers.h $(PARSERSRC)/Parser.l
	flex -o $(EXECDIR)/lex.yy.c $(PARSERSRC)/Parser.l

reader: $(INCDIR)/node.hpp $(SRCDIR)/node.cpp $(READERSRC)/ll_generator.cpp
	g++ -o $(EXECDIR)/ll_gen $(READERSRC)/ll_generator.cpp

# test_cfg: $(INCDIR)/node.hpp $(CFGINC)/cfg.hpp $(CFGINC)/cfg_node.hpp $(LISTSRC)/list_ops.cpp $(CFGSRC)/cfg.cpp $(CFGSRC)/cfg_node.cpp $(LISTSRC)/list_ops.cpp