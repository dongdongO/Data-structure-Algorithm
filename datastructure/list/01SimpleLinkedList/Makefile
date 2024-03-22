# 컴파일러 설정
CC=gcc
# 컴파일 옵션
CFLAGS=-Wall -Werror
# 빌드할 실행 파일 이름
TARGET=program

# 기본 타겟 설정
all: $(TARGET)

# 실행 파일 빌드 규칙
$(TARGET): main.c SLinkedList.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c SLinkedList.c

# 'make clean' 실행 시 빌드 결과물 정리
clean:
	rm -f $(TARGET)
