#! /bin/bash

if [[ "$main.cpp" && "$settings.h" ]]; then
	echo "Installing..."
	g++ $(pkg-config --cflags --libs Qt6Widgets qtermwidget6) -fPIC -o PJTerm main.cpp
	echo "We need to create a symlink"
	sudo ln -sf PJTerm /usr/local/bin/
	echo "Install Complete"
else
	echo "ERROR: Not all files are present"
fi
