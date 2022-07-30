CC=gcc
SRC=src/
BUILD_FOLDER=build

default: build-folder
	$(CC) $(SRC)*.c -o $(BUILD_FOLDER)/out

build-folder:
	mkdir -p $(BUILD_FOLDER)
