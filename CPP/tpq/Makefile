# Makefile pour projet C++ avec exécutable à la racine

CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -g -MMD -MP
INCLUDES := -I./include

# Répertoires
SRC_DIR := src
OBJ_DIR := obj
INCLUDE_DIR := include

# Fichiers source et objets
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
DEPS := $(OBJECTS:.o=.d)
TARGET := resolution

# Cibles PHONY (non des fichiers)
.PHONY: all clean run rebuild help test

# Cible par défaut
all: $(TARGET)

# Lien des objets pour créer l'exécutable à la racine
$(TARGET): $(OBJECTS) | $(OBJ_DIR)
	@echo "🔗 Liaison de l'exécutable : $@"
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "✅ Compilation réussie ! Exécutable : ./$@"

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "⚙️  Compilation : $<"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Création du répertoire obj s'il n'existe pas
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Inclusion des fichiers de dépendances
-include $(DEPS)

# Exécute le programme avec tests internes
run: $(TARGET)
	@echo "🚀 Exécution de ./$(TARGET)..."
	@./$(TARGET)

# Lance les tests automatiques sur les fichiers du dossier test_files/
test: $(TARGET)
	@echo "🧪 Lancement des tests automatiques..."
	@echo ""
	@echo "════════════════════════════════════════════════════════════════"
	@echo "Test 1: Rationnels 5*5 + algo Gauss"
	@echo "════════════════════════════════════════════════════════════════"
	@./$(TARGET) test_files/data_5_qq_gauss.txt test_files/laplacien1D_rationnel_5mailles.txt test_files/vecteur_5_qq.txt
	@echo ""
	@echo "════════════════════════════════════════════════════════════════"
	@echo "Test 2: Rationnels 5*5 + LU"
	@echo "════════════════════════════════════════════════════════════════"
	@./$(TARGET) test_files/data_5_qq_LU.txt test_files/laplacien1D_rationnel_5mailles.txt test_files/vecteur_5_qq.txt
	@echo ""
	@echo "════════════════════════════════════════════════════════════════"
	@echo "Test 3: Rationnels 5*5 + grad"
	@echo "════════════════════════════════════════════════════════════════"
	@./$(TARGET) test_files/data_5_qq_grad.txt test_files/laplacien1D_rationnel_5mailles.txt test_files/vecteur_5_qq.txt
	@echo ""
	@echo "════════════════════════════════════════════════════════════════"
	@echo "Test 4: Rationnels 100*100 + algo Gauss"
	@echo "════════════════════════════════════════════════════════════════"
	@./$(TARGET) test_files/data_100_qq_gauss.txt test_files/laplacien1D_rationnel_100mailles.txt test_files/vecteur_100_qq.txt
	@echo ""
	@echo "════════════════════════════════════════════════════════════════"
	@echo "Test 5: Rationnels 100*100 + LU"
	@echo "════════════════════════════════════════════════════════════════"
	@./$(TARGET) test_files/data_100_qq_LU.txt test_files/laplacien1D_rationnel_100mailles.txt test_files/vecteur_100_qq.txt
	@echo ""
	@echo "════════════════════════════════════════════════════════════════"
	@echo "Test 6: Rationnels 100*100 + Gradient"
	@echo "════════════════════════════════════════════════════════════════"
	@./$(TARGET) test_files/data_100_qq_grad.txt test_files/laplacien1D_rationnel_100mailles.txt test_files/vecteur_100_qq.txt
	@echo ""
	@echo "════════════════════════════════════════════════════════════════"
	@echo "Test 7: Double 100*100 + algo Gauss"
	@echo "════════════════════════════════════════════════════════════════"
	@./$(TARGET) test_files/data_100_double_gauss.txt test_files/laplacien1D_double_100mailles.txt test_files/vecteur_100_double.txt
	@echo ""
	@echo "════════════════════════════════════════════════════════════════"
	@echo "Test 8: Double 100*100 + LU"
	@echo "════════════════════════════════════════════════════════════════"
	@./$(TARGET) test_files/data_100_double_LU.txt test_files/laplacien1D_double_100mailles.txt test_files/vecteur_100_double.txt
	@echo ""
	@echo "════════════════════════════════════════════════════════════════"
	echo "Test 9: Double 100*100 + Gradient"
	@echo "════════════════════════════════════════════════════════════════"
	@./$(TARGET) test_files/data_100_double_grad.txt test_files/laplacien1D_double_100mailles.txt test_files/vecteur_100_double.txt
	@echo ""
	@echo "════════════════════════════════════════════════════════════════"
	@echo "✅ Tous les tests sont terminés !"
	@echo "════════════════════════════════════════════════════════════════"

# Nettoie les fichiers générés
clean:
	@echo "🧹 Nettoyage..."
	rm -rf $(OBJ_DIR) $(TARGET)
	@echo "✅ Nettoyage terminé"

# Recompile entièrement (clean + all)
rebuild: clean all

# Affiche l'aide
help:
	@echo "╔════════════════════════════════════════════════════════════════╗"
	@echo "║               Aide du Makefile - Projet AX=B                   ║"
	@echo "╠════════════════════════════════════════════════════════════════╣"
	@echo "║ Cibles disponibles :                                           ║"
	@echo "║   make          : Compile le projet                            ║"
	@echo "║   make run      : Compile et exécute les tests internes        ║"
	@echo "║   make test     : Lance tous les tests automatiques            ║"
	@echo "║   make clean    : Supprime les fichiers générés                ║"
	@echo "║   make rebuild  : Nettoie et recompile complètement            ║"
	@echo "║   make help     : Affiche cette aide                           ║"
	@echo "╠════════════════════════════════════════════════════════════════╣"
	@echo "║ Usage après compilation :                                      ║"
	@echo "║                                                                ║"
	@echo "║   ./resolution fichier_donnees.txt fichier_matrice.txt \       ║"
	@echo "║               fichier_vecteur.txt                              ║"
	@echo "╚════════════════════════════════════════════════════════════════╝"
