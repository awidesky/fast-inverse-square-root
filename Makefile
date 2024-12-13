SOURCE = ./src/
TEST = ./test/
BUILD = ./build/
TESTBUILD = ./testbuild/

help:
	@echo Please try goal \"build\" or \"test\".
	@echo \"build\" will build shared and static library into $(BUILD) directory.
	@echo \"test\" will build the library and generate test programs into $(TESTBUILD) directory.

setup:
	mkdir -p $(BUILD)
	mkdir -p $(TESTBUILD)

build: setup $(BUILD)libfastsqrt.so $(BUILD)libfastsqrt.a

$(BUILD)fast_sqrt.o: $(SOURCE)fast_sqrt.c $(SOURCE)fast_sqrt.h
	gcc -c $(SOURCE)fast_sqrt.c -o $@

$(BUILD)libfastsqrt.so: $(BUILD)fast_sqrt.o
	gcc -shared -fpic $(BUILD)fast_sqrt.o -o $@

$(BUILD)libfastsqrt.a: $(BUILD)fast_sqrt.o
	ar -rc $@ $(BUILD)fast_sqrt.o


test: setup $(TESTBUILD)link_compile $(TESTBUILD)link_runtime

$(TESTBUILD)link_compile: $(TEST)link_compile.c $(TEST)testMain.h $(BUILD)fast_sqrt.o
	gcc $(TEST)link_compile.c $(BUILD)fast_sqrt.o -o $@ -lm

$(TESTBUILD)link_runtime: $(TEST)link_runtime.c $(TEST)testMain.h $(BUILD)libfastsqrt.so
	gcc $(TEST)link_runtime.c -o $@ -ldl -lm

clean:
	rm -f $(BUILD)*
	rm -f $(TESTBUILD)*
	rmdir $(BUILD)
	rmdir $(TESTBUILD)