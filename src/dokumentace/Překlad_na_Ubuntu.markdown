# Překlad a instlalace na ubuntu

Popis instalace závislostí potředbých k překladu a instalaci na Ubuntu 16.04.3 LTS xenial

## Git

```bash
sudo apt install -y git
```
## QT

```bash
sudo apt install -y qtdeclarative5-dev
```

## g++-7

```bash
sudo add-apt-repository ppa:jonathonf/gcc-7.1
sudo apt-get update
sudo apt-get install gcc-7 g++-7
```

## Doxygen

```bash
sudo apt install -y  doxygen
sudo apt install -y  graphviz
```

## Cmake 

```bash
cd <adresář instalace Cmake>
wget https://cmake.org/files/v3.10/cmake-3.10.3-Linux-x86_64.sh
chmod +x cmake-3.10.3-Linux-x86_64.sh
./cmake-3.10.3-Linux-x86_64.sh
```

## Stažení projektu

```bash
git clone https://github.com/matlad/FIT_IVS_PROJECT2.git
```

## Překlad a spuštění

```bash
cd FIT_IVS_PROJECT2/src
make CMAKE=<adresář instalace Cmake>/cmake-3.10.3-Linux-x86_64/bin/cmake run
```
