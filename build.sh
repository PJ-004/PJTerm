#! /bin/bash

if [[ "$main.cpp" && "$settings.h" ]]; then
	echo "Installing..."
	g++ $(pkg-config --cflags --libs Qt6Widgets qtermwidget6) -fPIC -o PJTerm main.cpp
	sudo cp PJTerm /usr/local/bin
	sudo cp PJTerm.desktop ~/.local/share/applications
	echo "Installation Complete"
else
	echo "ERROR: Not all files are present"
fi