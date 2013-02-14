********
* OPIM *
********

OPIM source code is compilable under Linux (tested on Ubuntu 8.10).

To compile the server, cd into 'opimServer' and run make.
You'll need to have the following packages installed:
libxml2, libsqlite3, libsqlitewrapped, boost

To compile the client, cd into 'GUI/opimClientGUI' and run make.
You'll need to have all the server's packages installed plus the following:
libqt4-core, libqt4-gui, libqt4-dev, qt4-dev-tools
