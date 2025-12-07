# Makefile pour projet C++ avec architecture multi-dossiers
# Structure : src/ (sources), include/ (headers), obj/ (objets), bin/ (exécutables)

CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -g -MMD -MP
INCLUDES := -I./include

# Répertoires
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
INCLUDE_DIR := include

# Fichiers source et objets
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
DEPS := $(OBJECTS:.o=.d)
TARGET := $(BIN_DIR)/tpq

# Cibles PHONY (non des fichiers)
.PHONY: all clean run rebuild help

# Cible par défaut
all: $(TARGET)

# Lien des objets pour créer l'exécutable
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	@echo "🔗 Liaison de l'exécutable : $@"
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "✅ Compilation réussie ! Exécutable : $@"

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "⚙️  Compilation : $<"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Création des répertoires s'ils n'existent pas
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Inclusion des fichiers de dépendances
-include $(DEPS)

# Exécute le programme
run: $(TARGET)
	@echo "🚀 Exécution de $(TARGET)..."
	@./$(TARGET)

# Nettoie les fichiers générés
clean:
	@echo "🧹 Nettoyage..."
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "✅ Nettoyage terminé"

# Recompile entièrement (clean + all)
rebuild: clean all

# Affiche l'aide
help:
	@echo "╔════════════════════════════════════════════════════════════════╗"
	@echo "║               Aide du Makefile - Projet TPQ                   ║"
	@echo "╠════════════════════════════════════════════════════════════════╣"
	@echo "║ Cibles disponibles :                                          ║"
	@echo "║   make         : Compile le projet                           ║"
	@echo "║   make run     : Compile et exécute le programme             ║"
	@echo "║   make clean   : Supprime les fichiers générés              ║"
	@echo "║   make rebuild : Nettoie et recompile complètement          ║"
	@echo "║   make help    : Affiche cette aide                         ║"
	@echo "╠════════════════════════════════════════════════════════════════╣"
	@echo "║ Architecture du projet :                                      ║"
	@echo "║   src/        : Fichiers source (.cpp)                       ║"
	@echo "║   include/    : En-têtes (.h)                                ║"
	@echo "║   obj/        : Fichiers objets (.o) générés                 ║"
	@echo "║   bin/        : Exécutables générés                          ║"
	@echo "╚════════════════════════════════════════════════════════════════╝"
