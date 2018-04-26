Compile ArticleCitationsTest.cpp with the ArticleCitations.cpp from any
of the subdirectories. You don't need to change the path of the include
of ArticleCitations.h in ArticleCitationsTest.cpp because it is identical
in all subdirectories.

Example command-line for Linux:

>g++ -o Test ArticleCitationsTest.cpp 05_FinalVersion/ArticleCitations.cpp
