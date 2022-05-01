SRCDIR = ./src
INCDIR = ./include
TESTDIR = ./test
EXECDIR = ./exec

# Linked list
LISTINC = $(INCDIR)/linked_list
LISTSRC = $(SRCDIR)/linked_list
LISTTEST = $(TESTDIR)/linked_list

# CDG
CDGINC = $(INCDIR)/cdg
CDGSRC = $(SRCDIR)/cdg
CDGTEST = $(TESTDIR)/cdg

test_list: $(LISTTEST)/list_test.cpp $(LISTSRC)/list_ops.cpp $(SRCDIR)/node.cpp $(LISTINC)/list_ops.hpp $(INCDIR)/node.hpp
	g++ -o $(EXECDIR)/test_list $(LISTTEST)/list_test.cpp $(LISTSRC)/list_ops.cpp $(SRCDIR)/node.cpp


test_cdg: $(CDGTEST)/cdg_test.cpp $(CDGSRC)/cdg.cpp $(LISTSRC)/list_ops.cpp $(SRCDIR)/node.cpp $(CDGINC)/cdg.hpp $(LISTINC)/list_ops.hpp $(INCDIR)/node.hpp
	g++ -o $(EXECDIR)/test_cdg $(CDGTEST)/cdg_test.cpp $(CDGSRC)/cdg.cpp $(LISTSRC)/list_ops.cpp $(SRCDIR)/node.cpp