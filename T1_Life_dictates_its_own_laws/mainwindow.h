#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QToolButton>
#include <QSpinBox>
#include <QSlider>
#include <QOpenGLWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

private:
    void setupUi();
    void setupActions();

    void updateSliderFromSpinBoxes();

    QAction *m_actionNew = nullptr;
    QAction *m_actionSave = nullptr;
    QAction *m_actionLoad = nullptr;
    QAction *m_actionSaveAs = nullptr;
    QAction *m_actionExit = nullptr;
    QAction *m_actionModeView = nullptr;
    QAction *m_actionModeEdit = nullptr;
    QAction *m_actionEditUndo = nullptr;
    QAction *m_actionEditRedo = nullptr;

    QSpinBox *m_spinBoxStartIndex = nullptr;
    QSpinBox *m_spinBoxEndIndex = nullptr;
    QSpinBox *m_spinBoxCurrentIndex = nullptr;

    QSlider *m_sliderGenerationIndex = nullptr;

    QToolButton *m_toolbuttonPrevFrame = nullptr;
    QToolButton *m_toolbuttonNextFrame = nullptr;
    QToolButton *m_toolbuttonForwardFrame = nullptr;
    QToolButton *m_toolbuttonBackwardFrame = nullptr;
    QToolButton *m_toolbuttonChangeMode = nullptr;

//    QOpenGLWidget *m_openglWidget = nullptr;
    //Untill special OpenGLWidget class will be created i used dummy widget
    QWidget *m_openglWidget = nullptr;

};
#endif // MAINWINDOW_H
