#include "mainwindow.h"

#include <QMenuBar>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    setupUi();
    setupActions();
}

void MainWindow::setupUi()
{
    setMinimumSize({1200, 700});
    QMenuBar *menubar = new QMenuBar(this);
    QMenu *menuFile = new QMenu("File", this);
    m_actionNew = menuFile->addAction("New");
    m_actionLoad = menuFile->addAction("Load");
    m_actionSave = menuFile->addAction("Save");
    m_actionSaveAs = menuFile->addAction("Save As");
    m_actionExit = menuFile->addAction("Exit");
    QMenu *menuEdit = new QMenu("Edit", this);
    m_actionEditUndo = menuEdit->addAction("Undo");
    m_actionEditRedo = menuEdit->addAction("Redo");
    QMenu *menuMode = new QMenu("Mode", this);
    m_actionModeView = menuMode->addAction("View");
    m_actionModeEdit = menuMode->addAction("Edit");
    QMenu *menuOptions = new QMenu("Options", this);
    menubar->addMenu(menuFile);
    menubar->addMenu(menuEdit);
    menubar->addMenu(menuMode);
    menubar->addMenu(menuOptions);
    this->setMenuBar(menubar);

    QVBoxLayout *m_layout = new QVBoxLayout;
    QHBoxLayout *m_layoutControl = new QHBoxLayout;

    m_spinBoxStartIndex = new QSpinBox;
    m_spinBoxStartIndex->setMinimum(0);
    m_spinBoxStartIndex->setMaximum(25);
    m_spinBoxEndIndex = new QSpinBox;
    m_spinBoxEndIndex->setMinimum(0);
    m_spinBoxCurrentIndex = new QSpinBox;
    m_spinBoxCurrentIndex->setMinimum(0);
    m_sliderGenerationIndex = new QSlider(Qt::Orientation::Horizontal);
    m_sliderGenerationIndex->setRange(0, 25);
    m_toolbuttonBackwardFrame = new QToolButton;
    m_toolbuttonBackwardFrame->setText("B");
    m_toolbuttonForwardFrame = new QToolButton;
    m_toolbuttonForwardFrame->setText("F");
    m_toolbuttonNextFrame = new QToolButton;
    m_toolbuttonNextFrame->setText("N");
    m_toolbuttonPrevFrame = new QToolButton;
    m_toolbuttonPrevFrame->setText("P");
    m_toolbuttonChangeMode = new QToolButton;
    m_toolbuttonChangeMode->setText("M");

    m_layoutControl->addWidget(m_spinBoxStartIndex);
    m_layoutControl->addWidget(m_sliderGenerationIndex, 1);
    m_layoutControl->addWidget(m_spinBoxEndIndex);
    m_layoutControl->addWidget(m_spinBoxCurrentIndex);
    m_layoutControl->addWidget(m_toolbuttonPrevFrame);
    m_layoutControl->addWidget(m_toolbuttonBackwardFrame);
    m_layoutControl->addWidget(m_toolbuttonForwardFrame);
    m_layoutControl->addWidget(m_toolbuttonNextFrame);

    m_openglWidget = new QWidget;

    QVBoxLayout *layoutOpengl = new QVBoxLayout;
    layoutOpengl->addWidget(m_toolbuttonChangeMode);
    layoutOpengl->addStretch(1);
    layoutOpengl->setAlignment(Qt::AlignRight);
    m_openglWidget->setLayout(layoutOpengl);
    layoutOpengl->setContentsMargins({0, 0, 0, 0});

    m_layout->addWidget(m_openglWidget, 1);
    m_layout->addLayout(m_layoutControl);
    m_layout->setContentsMargins({2, 2, 2, 2});

    QWidget *centarlWidget = new QWidget;
    centarlWidget->setLayout(m_layout);
    setCentralWidget(centarlWidget);
}

void MainWindow::setupActions()
{
    QObject::connect(m_sliderGenerationIndex, &QSlider::valueChanged, m_spinBoxCurrentIndex, &QSpinBox::setValue);
    QObject::connect(m_spinBoxCurrentIndex, &QSpinBox::editingFinished, this, &MainWindow::updateSliderFromSpinBoxes);
    QObject::connect(m_spinBoxStartIndex, &QSpinBox::editingFinished, this, &MainWindow::updateSliderFromSpinBoxes);
    QObject::connect(m_spinBoxEndIndex, &QSpinBox::editingFinished, this, &MainWindow::updateSliderFromSpinBoxes);
}

void MainWindow::updateSliderFromSpinBoxes()
{
    if (m_spinBoxStartIndex->value() > m_spinBoxEndIndex->value())
        m_spinBoxEndIndex->setValue(m_spinBoxStartIndex->value());

    m_sliderGenerationIndex->setRange(m_spinBoxStartIndex->value(), m_spinBoxEndIndex->value());
    m_sliderGenerationIndex->setValue(m_spinBoxCurrentIndex->value());
    m_spinBoxStartIndex->setMaximum(m_spinBoxEndIndex->value());
    m_spinBoxEndIndex->setMinimum(m_spinBoxStartIndex->value());
}
