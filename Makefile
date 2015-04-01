MODELS_FILE_PATH = ./Models
all:
	g++ -I $(MODELS_FILE_PATH) main.cpp Controllers/*.cpp Models/*.cpp Models/*/*.cpp Models/*/*/*.cpp Models/*/*/*/*.cpp Models/*/*/*/*/*.cpp -o ck33.out
