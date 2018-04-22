################################################################################
## @file     Makefile
## @encoding UTF-8
## @date     10.4.18
## @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
## Hlavní makefile projektu
################################################################################

## Adresáře (předpokládá se že adresář vždy končí /)
###############
SRC_DIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
BUILD_DIR := $(SRC_DIR)build/
DOC_DIR := $(SRC_DIR)dokumentace/
CMAKE_FILE_DIR := $(SRC_DIR)../../FIT_IVS_PROJECT2/
RUN_DIR := $(PWD)

## Příkazy
############
CMAKE := cmake

#all (přeloží projekt - včetně programu pro profiling)
all: pre_build
	cd $(BUILD_DIR); make all;

#pack (zabalí projekt tak, aby mohl být odevzdán)
pack: pre_build
	cd $(BUILD_DIR); make package;

#test (spustí testy matematické knihovny)
test: pre_build
	cd $(BUILD_DIR); make NumberTest; ./NumberTest;

#clean (smaže všechny soubory, co nemají být odevzdány)
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)*; echo "">> $(BUILD_DIR).gitkeep;\
	rm -rf $(DOC_DIR)*;   echo "">> $(DOC_DIR).gitkeep;
#doc (spustí generování dokumentace)
doc:
	cd $(DOC_DIR); doxygen $(SRC_DIR)Doxyfile

#run (spustí program)
.PHONY: run
run: Calc
	./build/Calc

#pre_build zavolá Cmake a vygeneruje makefile
.PHONY: pre_build
pre_build:
	if ! [ -d "$(BUILD_DIR)" ]; then mkdir -p "$(BUILD_DIR)"; fi
	cd $(BUILD_DIR); $(CMAKE) $(CMAKE_FILE_DIR);

#Calc přeloží projekt
Calc: pre_build
	cd $(BUILD_DIR); make Calc;
