#!/bin/sh

# Script slouží k doinstalování všech zavislostí pro překlad aplikace
# navrženo pro:
# Distributor ID:	Ubuntu
# Description:	Ubuntu 16.04.3 LTS
# Release:	16.04
# Codename:	xenial


# počíráme s tím že script běží v domovském adresáři
cd ~

# Git
sudo apt install -y git

# QT
sudo apt install -y qtdeclarative5-dev

# g++-7
sudo add-apt-repository ppa:jonathonf/gcc-7.1
sudo apt-get update
sudo apt-get install gcc-7 g++-7

# doxygen
sudo apt install -y  doxygen
sudo apt install -y  graphviz

# Cmake
wget https://cmake.org/files/v3.10/cmake-3.10.3-Linux-x86_64.sh
chmod +x cmake-3.10.3-Linux-x86_64.sh
./cmake-3.10.3-Linux-x86_64.sh


# stazení projektu
git clone https://github.com/matlad/FIT_IVS_PROJECT2.git

# překlad
cd FIT_IVS_PROJECT2/src
make CMAKE=~/cmake-3.10.3-Linux-x86_64/bin/cmake run
