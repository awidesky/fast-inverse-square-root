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

build: setup $(BUILD)libfastInvsqrt.so $(BUILD)libfastInvsqrt.a

$(BUILD)fast_invsqrt.o: $(SOURCE)fast_invsqrt.c $(SOURCE)fast_invsqrt.h
	gcc -c $(SOURCE)fast_invsqrt.c -o $@

$(BUILD)libfastInvsqrt.so: $(BUILD)fast_invsqrt.o
	gcc -shared -fpic $(BUILD)fast_invsqrt.o -o $@

$(BUILD)libfastInvsqrt.a: $(BUILD)fast_invsqrt.o
	ar -rc $@ $(BUILD)fast_invsqrt.o


test: setup $(TESTBUILD)link_compile $(TESTBUILD)link_runtime

$(TESTBUILD)link_compile: $(TEST)link_compile.c $(TEST)testMain.h $(BUILD)fast_invsqrt.o
	gcc $(TEST)link_compile.c $(BUILD)fast_invsqrt.o -o $@

$(TESTBUILD)link_runtime: $(TEST)link_runtime.c $(TEST)testMain.h $(BUILD)libfastInvsqrt.so
	gcc $(TEST)link_runtime.c -o $@ -ldl

clean:
	rm -f $(BUILD)*
	rm -f $(TESTBUILD)*
	rmdir $(BUILD)
	rmdir $(TESTBUILD)