
# for OS X

all: Test.java Test.cpp
	clang++ -o libtest.jnilib -shared -I/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers/ -I../include -std=c++11 -stdlib=libc++ Test.cpp WrapperTest.cpp
	javac *.java

test: all
	java Test

clean:
	rm *.class *.jnilib

