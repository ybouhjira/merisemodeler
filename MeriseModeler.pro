#------------------------------------------------------------------------------
#
# Youssef Bouhjira
# Mohamed DOULFAKAR
#------------------------------------------------------------------------------
# Projet de Fin d'Etudes
# Ecole Supérieure de Technologie d'Essaouira
#------------------------------------------------------------------------------
# 2013 - 2012
#
#------------------------------------------------------------------------------

# Modules Qt inclues
QT       += core widgets svg

# indique au compilateur d'utiliser le C++11
CONFIG += c++11

# Permet d'utiliser des fichiers sources ayant le meme nom
CONFIG += object_parallel_to_source

# Executable
TARGET = MeriseModeler

# Type d'application à compiler
TEMPLATE = app

# Fichier de ressource
RESOURCES += ressourceFile.qrc

# Indiquer les fichier sources et headers
SOURCES += main.cpp

include(logic/logic.pri)
include(graphic/graphic.pri)
include(ui/ui.pri)
include(exporter/exporter.pri)
include(command/command.pri)
include(model/model.pri)
