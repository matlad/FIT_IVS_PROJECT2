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
BUILD_DIR := $(SRC_DIR)../build/
DOC_DIR := $(SRC_DIR)../dokumentace/
CMAKE_FILE_DIR := $(SRC_DIR)../../FIT_IVS_PROJECT2/
PROJECT_DIR:= $(SRC_DIR)../
RUN_DIR := $(PWD)

## Příkazy závislosti
#####################
CMAKE := cmake

#all (přeloží projekt - včetně programu pro profiling)
all: pre_build
	cd $(BUILD_DIR); make all;

#pack (zabalí projekt tak, aby mohl být odevzdán)
pack: doc package
	rm -rf  $(PROJECT_DIR)archive
	rm $(PROJECT_DIR)/xcecha04_xmatla00_xmitur01_xslade21_plan.zip
	mkdir $(PROJECT_DIR)archive
	mkdir $(PROJECT_DIR)archive/doc
	cp -r $(DOC_DIR)* $(PROJECT_DIR)archive/doc
	mkdir $(PROJECT_DIR)archive/install
	cp $(BUILD_DIR)*.deb $(PROJECT_DIR)archive/install
	mkdir $(PROJECT_DIR)archive/repo
	git clone git@github.com:matlad/FIT_IVS_PROJECT2.git $(PROJECT_DIR)archive/repo
	cd $(PROJECT_DIR)/archive; zip -r ../xcecha04_xmatla00_xmitur01_xslade21_plan.zip .
	rm -rf  $(PROJECT_DIR)archive

#Vytvoří deb balíček
package: pre_build
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
	cd $(SRC_DIR); doxygen $(SRC_DIR)Doxyfile

#run (spustí program)
.PHONY: run
run: Calc
	$(BUILD_DIR)Calc;

#pre_build zavolá Cmake a vygeneruje makefile
.PHONY: pre_build
pre_build:
	if ! [ -d "$(BUILD_DIR)" ]; then mkdir -p "$(BUILD_DIR)"; fi
	cd $(BUILD_DIR); $(CMAKE) $(CMAKE_FILE_DIR);

#Calc přeloží projekt
Calc: pre_build
	cd $(BUILD_DIR); make Calc;

install: pre_build
	cd $(BUILD_DIR); make install;
