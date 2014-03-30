
# for OS X

all: Test.java Test.cpp
	clang++ -o libtest.jnilib -shared -I/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers/ -I../ -std=c++11 Test.cpp
	javac Test.java

test: all
	java Test

clean:
	rm *.class *.jnilib

