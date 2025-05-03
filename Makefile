# Режим сборки по умолчанию
BUILD_MODE ?= debug
CC = gcc

SRC_DIR := src
OBJ_DIR := build/$(BUILD_MODE)
BIN_DIR := bin/$(BUILD_MODE)

# Валидация BUILD_MODE
ifeq ($(BUILD_MODE),debug)
	CFLAGS := -g -MMD
else ifeq ($(BUILD_MODE),release)
	CFLAGS := -O2 -MMD
else
	$(error ❌ Недопустимый BUILD_MODE='$(BUILD_MODE)'. Используй 'debug' или 'release')
endif

# Источники и объектные файлы
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEPS := $(OBJS:.o=.d)

TARGET := $(BIN_DIR)/app.exe

# Приветствие
ifeq ($(COMPUTERNAME),CHAMION)
GREETING = @echo "Привет, $(COMPUTERNAME), сейчас билдить буду..."
else
GREETING = @echo "ХАКЕР БЛЯТЬ СБИЛДИЛ..."
endif

# Цель по умолчанию
build: check_build_mode $(TARGET)

check_build_mode:
	@echo "🔨 Текущий режим сборки: $(BUILD_MODE)"
	$(GREETING)

$(TARGET): $(OBJS)
	@echo "🔧 Линкуем объектные файлы..."
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "✅ Готово: $@"

# Компиляция .c в .o с созданием .d
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Подключение зависимостей (автогенерация .d файлов)
-include $(DEPS)

.PHONY: rebuild
rebuild: clean build
	@echo "🔄 Проект пересобран"

.PHONY: clean
clean:
	rm -rf bin/*
	rm -rf build/*
	@echo "🧹 Очистка завершена"
