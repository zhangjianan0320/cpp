CC=g++
TARGET=edit
#wildcard 获取当前目录下的所有cpp文件
SOURCE=$(wildcard *.cpp)
#patsubst 替换所有的cpp 为 o
OBJECT=$(patsubst %cpp,%o,$(SOURCE))
$(TARGET):$(SOURCE)
	$(CC) $(SOURCE) -o $@

clean:
	rm edit
