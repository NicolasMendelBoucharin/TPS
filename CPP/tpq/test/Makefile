# Makefile pour les tests unitaires
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
INCLUDES = -I../include

# Fichiers source
SRCS = tests.cpp ../src/qq.cpp ../src/vect.cpp ../src/matrice.cpp ../src/datas.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = tests

# Règles
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "✓ Tests compilés avec succès!"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

run: $(TARGET)
	@echo "Exécution des tests..."
	@./$(TARGET)

clean:
	rm -f $(TARGET) tests.o ../src/qq.o ../src/vect.o ../src/matrice.o ../src/datas.o

.PHONY: all run clean
