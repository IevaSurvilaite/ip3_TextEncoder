# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Target executables
TARGET_DEMO = main
TARGET_TEST = test

# Static library
MODULE = libtextencoder.a

# Source files
SRC = TextEncoder.cpp ReverseEncoding.cpp LeetSpeakEncoding.cpp
DEMO_SRC = main.cpp
TEST_SRC = test.cpp

# Object files
OBJ = $(SRC:.cpp=.o)
DEMO_OBJ = $(DEMO_SRC:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)

# Default target (build everything)
all: $(MODULE) $(TARGET_DEMO) $(TARGET_TEST)

# Build the static library
$(MODULE): $(OBJ)
	ar rcs $@ $^

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build the demo executable
$(TARGET_DEMO): $(DEMO_OBJ) $(MODULE)
	$(CXX) $(CXXFLAGS) -o $@ $(DEMO_OBJ) $(MODULE)
#	  On Windows, this will create main.exe, on Linux, main

# Build the test executable
$(TARGET_TEST): $(TEST_OBJ) $(MODULE)
	$(CXX) $(CXXFLAGS) -o $@ $(TEST_OBJ) $(MODULE)
# 	  On Windows, this will create test.exe, on Linux, test

# Run tests
run_tests: $(TARGET_TEST)
	./$(TARGET_TEST) # Linux and Windows (if in PATH)

# Clean build artifacts
clean:
	$(RM) $(OBJ) $(DEMO_OBJ) $(TEST_OBJ) $(MODULE) $(TARGET_DEMO).exe $(TARGET_TEST).exe #for windows
	$(RM) $(OBJ) $(DEMO_OBJ) $(TEST_OBJ) $(MODULE) $(TARGET_DEMO) $(TARGET_TEST) #for linux

# Rebuild everything
rebuild: clean all

# Define RM for cross-platform compatibility
RM = $(shell if exist del (echo del /F /Q) else echo rm -f)
