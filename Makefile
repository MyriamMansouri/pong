	COMPILER = clang++
	SOURCE_LIBS = -Ilib/
	MAC_OPT = -std=c++17 -Llib/ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/libraylib.a
	MAC_OUT = -o "bin/build_mac"
	CFILES = src/*.cpp
build_mac:
	$(COMPILER) $(CFILES) $(SOURCE_LIBS) $(MAC_OUT) $(MAC_OPT)