#include "mainwindow.h"

void MainWindow::createUndoStackAndActions() {
    actionUndo->setShortcuts(QKeySequence::Undo);
    actionRedo->setShortcuts(QKeySequence::Redo);
    connect(actionUndo, &QAction::triggered, this, &MainWindow::pix_undo);
    connect(actionRedo, &QAction::triggered, this, &MainWindow::pix_redo);
    actionUndo->setDisabled(true);
    actionRedo->setDisabled(true);
}

/*
 * Simple undo function for Leptonica Pix object
 */
void MainWindow::pix_undo() {
    // first store copy of current PIX image to redoPixStack
    PIX *originalPix = pixClone(pixs);
    redoPixStack.push(originalPix);
    actionRedo->setDisabled(false);

    pixDestroy(&pixs);
    pixs = undoPixStack.top();
    undoPixStack.pop();
    setPixToScene();
    if (undoPixStack.empty()) actionUndo->setDisabled(true);
}

/*
 * Simple redo function for Leptonica Pix object
 */
void MainWindow::pix_redo() {
    // first store copy of current PIX image to undoPixStack
    PIX *originalPix = pixClone(pixs);
    undoPixStack.push(originalPix);
    actionUndo->setDisabled(false);

    pixDestroy(&pixs);
    pixs = redoPixStack.top();
    redoPixStack.pop();
    setPixToScene();
    if (redoPixStack.empty()) actionRedo->setDisabled(true);
}
