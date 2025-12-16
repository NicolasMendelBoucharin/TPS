# ============================================================================
# Makefile amélioré pour le projet tpq
# ============================================================================
# Compilateur et options
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -g -O2
LDFLAGS = -lm

# Répertoires
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
BIN_NAME = resolution

# Fichiers source et objets
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
HEADERS = $(wildcard $(INC_DIR)/*.hpp) $(wildcard $(INC_DIR)/*.h)

# Cibles phony
.PHONY: all clean rebuild help depend

# ============================================================================
# Règles principales
# ============================================================================

all: $(BIN_NAME)

# Lien de l'exécutable
$(BIN_NAME): $(OBJECTS)
	@echo "Linking $@..."
	@$(CXX) $(CXXFLAGS) -I$(INC_DIR) -o $@ $^ $(LDFLAGS)
	@echo "Build successful: $(BIN_NAME)"

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

# ============================================================================
# Cibles utilitaires
# ============================================================================

clean:
	@echo "Cleaning object files and executable..."
	@rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d
	@rm -f $(BIN_NAME)
	@echo "Clean complete"

rebuild: clean all
	@echo "Rebuild complete"

depend:
	@echo "Generating dependencies..."
	@$(CXX) $(CXXFLAGS) -I$(INC_DIR) -MM $(SOURCES) > depend.mk
	@echo "Dependencies updated"

# Afficher l'aide
help:
	@echo "Cibles disponibles :"
	@echo "  all       - Compile le programme (défaut)"
	@echo "  clean     - Supprime les fichiers objets et l'exécutable"
	@echo "  rebuild   - Recompile complètement"
	@echo "  depend    - Génère les dépendances"
	@echo "  help      - Affiche cette aide"
	@echo ""
	@echo "Usage: make [cible]"

# ============================================================================
# Dépendances (généré par 'make depend')
# ============================================================================
-include depend.mk
