# Project name
EXEC=Echecs

# Compiler
<<<<<<< HEAD
<<<<<<< HEAD
IDIR=include include/constraints include/domains include/misc include/objectives include/variables SMFL/include
=======
IDIR=include 
>>>>>>> 6cd0d399de3f0a6eab521848ab49bb956abfd651
IDIRFLAG=$(foreach idir, $(IDIR), -I$(idir))
LIBDIR=lib
LIBDIRFLAG =$(foreach libdir, $(LIBDIR), -L$(libdir))
CXXFLAGS=-std=c++11 -c -g $(IDIRFLAG)
SFMLFLAG= -lX11 -lGLEW -lopenal -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio $(LIBDIRFLAG)

# Linker
LFLAGS=$(IDIRFLAG) $(LIBDIRFLAG)

# Directories
SRCDIR=src src/AbstractFactory src/Dir src/StateVideo src/StateAudio src/Observer
=======
IDIR=include include/constraints include/domains include/misc include/objectives include/variables
IDIRFLAG=$(foreach idir, $(IDIR), -I$(idir))
CXXFLAGS=-std=c++0x -Ofast -W -Wall -Wextra -pedantic -Wno-sign-compare -Wno-unused-parameter $(IDIRFLAG)

# Linker
LFLAGS=$(IDIRFLAG)

# Directories
SRCDIR=src src/constraints src/domains src/misc src/objectives src/variables
>>>>>>> mouvement_pieces
OBJDIR=obj
BINDIR=bin

# Files
SOURCES=$(foreach sdir, $(SRCDIR), $(wildcard $(sdir)/*.cpp))
OBJECTS=$(patsubst %.cpp, $(OBJDIR)/%.o, $(notdir $(SOURCES)))

# For rm
SOURCESTILDE=$(foreach sdir, $(SRCDIR), $(wildcard $(sdir)/*.cpp~))
INCLUDESTILDE=$(foreach idir, $(IDIR), $(wildcard $(idir)/*.hpp~))

vpath %.cpp $(SRCDIR)

# Reminder, 'cause it is easy to forget makefile's fucked-up syntax...
# $@ is what triggered the rule, ie the target before :
# $^ is the whole dependencies list, ie everything after :
# $< is the first item in the dependencies list

# Rules
<<<<<<< HEAD

#script:
#	@./modifVariable.sh

=======
>>>>>>> mouvement_pieces
gcc: clean
gcc: CXX=g++
gcc: LINKER=g++ -o
gcc: CXXFLAGS += -DNDEBUG
gcc: $(BINDIR)/$(EXEC)

gcc-debug: clean
gcc-debug: CXX=g++
gcc-debug: LINKER=g++ -o
gcc-debug: CXXFLAGS += -g
gcc-debug: $(BINDIR)/$(EXEC)

clang: clean
clang: CXX=clang++
clang: LINKER=clang++ -o
clang: CXXFLAGS += -DNDEBUG -stdlib=libc++
clang: $(BINDIR)/$(EXEC)

clang-debug: clean
clang-debug: CXX=clang++
clang-debug: LINKER=clang++ -o
clang-debug: CXXFLAGS += -g -stdlib=libc++
clang-debug: $(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC): $(OBJECTS)
<<<<<<< HEAD
	@$(LINKER) $@ $(LFLAGS) $^ $(SFMLFLAG)
=======
	@$(LINKER) $@ $(LFLAGS) $^
>>>>>>> mouvement_pieces

$(OBJDIR)/%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

<<<<<<< HEAD
.PHONY: gcc gcc-debug clang clang-debug clean

clean:
	rm -fr core *~ $(OBJECTS) $(BINDIR)/$(EXEC) $(SOURCESTILDE) $(INCLUDESTILDE)
=======
.PHONY: gcc gcc-debug clang clang-debug clean 

clean:
	rm -fr core *~ $(OBJECTS) $(BINDIR)/$(EXEC) $(SOURCESTILDE) $(INCLUDESTILDE)

>>>>>>> mouvement_pieces
