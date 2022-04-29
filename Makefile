SRCDIR = ./src
INCDIR = ./include
TESTDIR = ./test
EXECDIR = ./exec
LISTINC = $(INCDIR)/linked_list
LISTSRC = $(SRCDIR)/linked_list
LISTTEST = $(TESTDIR)/linked_list

test_list: $(LISTTEST)/list_test.cpp $(LISTSRC)/list_ops.cpp $(SRCDIR)/node.cpp $(LISTINC)/list_ops.hpp $(INCDIR)/node.hpp
	g++ -o $(EXECDIR)/test_list $(LISTTEST)/list_test.cpp $(LISTSRC)/list_ops.cpp $(SRCDIR)/node.cpp