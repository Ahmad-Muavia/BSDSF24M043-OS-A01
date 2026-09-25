# Operating Systems Programming Assignment – 01

**Student:** Ahmad Muavia  
**Roll No:** BSDSF24M043  
**Course:** Operating Systems  
**Project:** BSDSF24M043-OS-A01  

---

# Feature-2: Multi-file Project using Make Utility

## Question 1  Explain the linking rule in this part's Makefile: `$(TARGET): $(OBJECTS)`. How does it differ from a Makefile rule that links against a library?

The rule:

```makefile
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

means that the final executable depends directly on all the object files. The source files are first compiled into object files, and then those object files are linked together to create the executable.

When linking against a library, the linker uses options such as:
$(CC) $(MAIN_OBJECT) -L../lib -lmyutils -o $(TARGET)

Here, -L../lib tells the linker where to search for the library, while -lmyutils tells it to link with libmyutils.

Therefore, the multi-file build links object files directly, while the library build links the main program with a separately created library.

## Q2. What is a git tag and why is it useful in a project? What is the difference between a simple tag an#d an annotated tag?

A Git tag is a named reference to a specific commit. It is useful for marking important versions or stable points in a project's history, especially release versions.

A lightweight tag is simply a name pointing to a commit. An annotated tag is stored as a separate Git object and contains additional information such as the tag message, tagger, and date.

Annotated tags are more suitable for official releases because they contain additional release information.

## Q3. What is the purpose of creating a "Release" on GitHub? What is the significance of attaching binaries like your client executable to it?

A GitHub Release provides a versioned and downloadable form of a project. It is associated with a Git tag and can contain release notes and compiled files.

Attaching a binary such as bin/client allows users or instructors to download and run the already-compiled program without compiling the source code themselves. It also provides a clear record of the binary distributed for that particular version.

# Feature-3: Creating and Using Static Library

## Q1. Compare the Makefile from Part 2 and Part 3. What are the key differences in the variables and rules that enable the creation of a static library?

In Part 2, all object files were directly linked together to create:

bin/client

In Part 3, the library functions were first compiled into object files and then combined into:

lib/libmyutils.a

using ar and ranlib.

The Makefile introduced a library variable:

LIBRARY = ../lib/libmyutils.a

and separate library object files:

LIB_OBJECTS = $(OBJDIR)/mystrfunctions.o \
              $(OBJDIR)/myfilefunctions.o

The library was then linked with the main program using:

-L../lib -lmyutils

The resulting executable was:

bin/client_static
## Q2. What is the purpose of the ar command? Why is ranlib often used immediately after it?

The ar command is used to create and manage archive files.

In this project, it was used to combine:

mystrfunctions.o
myfilefunctions.o

into:

libmyutils.a

The ranlib command creates or updates the symbol index inside the archive. This index allows the linker to efficiently find the required symbols and object files inside the static library.

## Q3. When you run nm on your client_static executable, are the symbols for functions like mystrlen present? What does this tell you about how static linking works?

Yes, symbols for functions such as mystrlen are present in the statically linked executable.

This shows that the required object code from libmyutils.a was included in the executable during the linking process.

Therefore, the static executable contains the required library code and does not need libmyutils.a at runtime.

# Feature-4: Creating and Using Dynamic Library

## Q1. What is Position-Independent Code (-fPIC) and why is it a fundamental requirement for creating shared libraries?

Position-Independent Code (PIC) is machine code that can execute correctly regardless of where it is loaded into memory.

The -fPIC compiler option tells GCC to generate position-independent code.

This is important for shared libraries because the operating system can load the same .so library at different memory addresses for different processes without modifying the library code.

In this project, -fPIC was used when compiling the object files that were used to create:

libmyutils.so
## Q2. Explain the difference in file size between your static and dynamic clients. Why does this difference exist?

The measured sizes in this project were approximately:

client_static    17K
client_dynamic   16K

The static executable contains the required library code inside the executable itself.

The dynamic executable does not contain a copy of the library code. Instead, it contains references to the shared library:

libmyutils.so

The shared library is loaded separately at runtime.

Therefore, the dynamic executable can be smaller because the library code is stored separately instead of being copied into the executable.

## Q3. What is the LD_LIBRARY_PATH environment variable? Why was it necessary to set it for your program to run, and what does this tell you about the responsibilities of the operating system's dynamic loader?

LD_LIBRARY_PATH is an environment variable that tells the dynamic loader which additional directories to search for shared libraries.

It was necessary because our custom:

libmyutils.so

was stored inside the project's lib/ directory rather than a standard system library directory.

By adding the project's lib/ directory to LD_LIBRARY_PATH, the dynamic loader was able to find and load libmyutils.so.

This demonstrates that the dynamic loader is responsible for locating and loading shared libraries required by a program at runtime.

In the final dynamic build, the executable also contained the following RUNPATH:

$ORIGIN/../lib

This allowed client_dynamic to locate libmyutils.so relative to the executable's location.

# Feature-5: Creating and Accessing Man Pages

Feature-5 does not contain separate REPORT.md questions. However, the required documentation and installation work was completed.

Six man pages were created for the project's functions:

mystrlen
mystrcpy
mystrncpy
mystrcat
wordCount
mygrep

Each man page contains the required sections:

.TH
.SH NAME
.SH SYNOPSIS
.SH DESCRIPTION
.SH AUTHOR

The Makefile was also modified to include an install target.

The installation process copies:

bin/client

to:

/usr/local/bin/client

and installs the man pages into:

/usr/local/share/man/man3

The installation was tested using:

sudo make install

The executable was successfully run using:

client

and the man page was successfully accessed using:

man mygrep

The project therefore provides both an executable installation method and standard Linux documentation.
