# "Artistic Style" Makefile

CPPFLAGS = -Wall -Wno-sign-compare -O0 -ggdb
OBJS = \
	ComplexStatement.o \
	Statement.o \
	Twin.o \
	Token.o \
	Parser.o \
	TokenSet.o \
	HtmlTag.o \
	format.o

format: $(OBJS)
	g++ $(CPPFLAGS) -o format  $(OBJS)

.cpp.o:
	g++ $(CPPFLAGS) -c $<
.SUFFIXES: .cpp .c .o

clean:
	del /q *.o