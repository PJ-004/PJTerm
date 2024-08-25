/*
    This terminal was built largely through the guide given by DonnieWest at CodeKoalas,
    which you can find here: https://codekoalas.com/blog/build-your-own-minimal-terminal
*/

#include <QApplication>
#include <QKeySequence>
#include <QDesktopServices>
#include <QMainWindow>

#include <QtDebug>

#include "qtermwidget.h"
#include "settings.h"

void activateUrl(const QUrl &url, bool fromContextMenu) {
    if (QApplication::keyboardModifiers() & Qt::ControlModifier || fromContextMenu) {
        QDesktopServices::openUrl(url);
    }
}

int main(int argc, char *argv[]) {

    // Initializing the terminal window
    QApplication app(argc, argv);
    QMainWindow *mainWindow = new QMainWindow();
    QTermWidget *console = new QTermWidget();
    setenv("TERM", "konsole-256color", 1);

    // Fonts
    QFont font = QApplication::font();
    font.setFamily(FONT);
    font.setPointSize(FONT_SIZE);
    console->setTerminalFont(font);

    // Adding URL and copy paste support
    QObject::connect(console, &QTermWidget::urlActivated,  mainWindow, activateUrl);
    QObject::connect(console, &QTermWidget::termKeyPressed, mainWindow,
		    [=](const QKeyEvent *key) -> void {
                         if (key -> modifiers() & Qt::ControlModifier &&
			     key -> modifiers() & Qt::ShiftModifier &&
			     key -> key() == Qt::Key_C) {
                             console -> copyClipboard();
			 }
                    });
    QObject::connect(console, &QTermWidget::termKeyPressed, mainWindow,
		    [=](const QKeyEvent *key) -> void {
                         if (key -> modifiers() & Qt::ControlModifier &&
			     key -> modifiers() & Qt::ShiftModifier &&
			     key -> key() == Qt::Key_V) {
                             console -> pasteClipboard();
                         }
		    });
    QObject::connect(console, SIGNAL(finished()), mainWindow, SLOT(close()));
   
    // Setting terminal attributes
    console->setColorScheme(COLOR_SCHEME); 			// Changing the color scheme
    console->setScrollBarPosition(QTermWidget::ScrollBarRight); // Adding a scroll bar
    console->setTerminalOpacity(OPACITY); 			// Transparency
    mainWindow->resize(1000, 500); 				// Terminal Size

    // Executing the program
    mainWindow->setCentralWidget(console);
    mainWindow->show();
    return app.exec();
}
