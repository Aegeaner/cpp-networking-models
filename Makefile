.PHONY: all build clean rebuild test

BUILD_DIR = build

all: build

build:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake ..
	cd $(BUILD_DIR) && cmake --build .

clean:
	rm -rf $(BUILD_DIR)
	rm -rf bin/
	rm -rf lib/

rebuild: clean build

test: build
	@echo "Running tests..."
	# Add test execution here (e.g., ctest)
