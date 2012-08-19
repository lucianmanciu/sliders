/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

//#include "slidersgroup.h"
#include "window.h"

Window::Window()
{
//    horizontalSliders = new SlidersGroup(Qt::Horizontal, tr("Simulation"));
//    verticalSliders = new SlidersGroup(Qt::Vertical, tr("Simulation"));

    scene = new QGraphicsScene;
    scene->setSceneRect(-300, -300, 300, 300);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(QPixmap("C:/bin/QtSDK/Examples/4.7/widgets/sliders/images/cheese.jpg"));
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Simulation"));
    view->resize(600, 600);
//    view.show();

//    stackedWidget = new QStackedWidget;
//    stackedWidget->addWidget(horizontalSliders);
//    stackedWidget->addWidget(verticalSliders);

    createControls(tr("Controls"));

    connect(weightLineEdit, SIGNAL(textChanged(QString)),
            temp, SLOT(setValue(QString)));
    connect(temp, SIGNAL(valueChanged(QString)),
            xValueLabel, SLOT(setText(QString)));
//    connect(horizontalSliders, SIGNAL(valueChanged(int)),
//            verticalSliders, SLOT(setValue(int)));
//    connect(verticalSliders, SIGNAL(valueChanged(int)),
//            valueSpinBox, SLOT(setValue(int)));
//    connect(valueSpinBox, SIGNAL(valueChanged(int)),
//            horizontalSliders, SLOT(setValue(int)));

    QHBoxLayout *layout = new QHBoxLayout;
//    layout->addWidget(stackedWidget);
    layout->addWidget(view);
    layout->addWidget(controlsGroup);

    setLayout(layout);

//    minimumSpinBox->setValue(0);
//    maximumSpinBox->setValue(20);
//    valueSpinBox->setValue(5);

    setWindowTitle(tr("Simulated Physics"));
}

void Window::createControls(const QString &title)
{
    controlsGroup = new QGroupBox(title);
//    minimumLabel = new QLabel(tr("Minimum value:"));
//    maximumLabel = new QLabel(tr("Maximum value:"));
//    valueLabel = new QLabel(tr("Current value:"));
    quantityLabel = new QLabel(tr("Quantity:"));
    weightLabel = new QLabel(tr("Weight:"));
    temperatureLabel = new QLabel(tr("Temperature:"));
    pressureLabel = new QLabel(tr("Pressure:"));
    volumeLabel = new QLabel(tr("Volume:"));
    quantityColLabel = new QLabel(tr("Quantity"));
    weightColLabel = new QLabel(tr("Weight"));
    temperatureColLabel = new QLabel(tr("Temperature"));
    pressureColLabel = new QLabel(tr("Pressure"));
    volumeColLabel = new QLabel(tr("Volume"));
    xLabel = new QLabel(tr("X - >"));;
    xValueLabel = new QLabel(tr("100 N"));
    temp = new ProxyLineEdit();

    quantityLineEdit = new QLineEdit;
    quantityLineEdit->setFixedWidth(75);
    quantityLineEdit->setMaxLength(6);
    weightLineEdit = new QLineEdit;
    weightLineEdit->setFixedWidth(75);
    weightLineEdit->setMaxLength(6);
    temperatureLineEdit = new QLineEdit;
    temperatureLineEdit->setFixedWidth(75);
    temperatureLineEdit->setMaxLength(6);
    outputTextEdit = new QTextEdit;

//    invertedAppearance = new QCheckBox(tr("Inverted appearance"));
//    invertedKeyBindings = new QCheckBox(tr("Inverted key bindings"));

//    minimumSpinBox = new QSpinBox;
//    minimumSpinBox->setRange(-100, 100);
//    minimumSpinBox->setSingleStep(1);

//    maximumSpinBox = new QSpinBox;
//    maximumSpinBox->setRange(-100, 100);
//    maximumSpinBox->setSingleStep(1);

//    valueSpinBox = new QSpinBox;
//    valueSpinBox->setRange(-100, 100);
//    valueSpinBox->setSingleStep(1);

    simulateButton = new QPushButton("Simulate", this);
    abortButton = new QPushButton("Abort", this);
    abortButton->setEnabled(0);
    sortButton = new QPushButton("Sort", this);
    sortButton->setEnabled(0);

    sortCombo = new QComboBox;
    sortCombo->addItem(tr("Q"));
    sortCombo->addItem(tr("W"));
    sortCombo->addItem(tr("T"));

    pressureSlider = new QSlider(Qt::Horizontal, this);
    volumeSlider = new QSlider(Qt::Horizontal, this);

//    connect(orientationCombo, SIGNAL(activated(int)),
//            stackedWidget, SLOT(setCurrentIndex(int)));
//    connect(minimumSpinBox, SIGNAL(valueChanged(int)),
//            horizontalSliders, SLOT(setMinimum(int)));
//    connect(minimumSpinBox, SIGNAL(valueChanged(int)),
//            verticalSliders, SLOT(setMinimum(int)));
//    connect(maximumSpinBox, SIGNAL(valueChanged(int)),
//            horizontalSliders, SLOT(setMaximum(int)));
//    connect(maximumSpinBox, SIGNAL(valueChanged(int)),
//            verticalSliders, SLOT(setMaximum(int)));
//    connect(invertedAppearance, SIGNAL(toggled(bool)),
//            horizontalSliders, SLOT(invertAppearance(bool)));
//    connect(invertedAppearance, SIGNAL(toggled(bool)),
//            verticalSliders, SLOT(invertAppearance(bool)));
//    connect(invertedKeyBindings, SIGNAL(toggled(bool)),
//            horizontalSliders, SLOT(invertKeyBindings(bool)));
//    connect(invertedKeyBindings, SIGNAL(toggled(bool)),
//            verticalSliders, SLOT(invertKeyBindings(bool)));

    QGridLayout *controlsLayout = new QGridLayout;
    controlsLayout->addWidget(quantityLabel, 0, 0);
    controlsLayout->addWidget(temperatureLabel, 1, 0);
    controlsLayout->addWidget(pressureLabel, 2, 0);
    controlsLayout->addWidget(volumeLabel, 3, 0);
    controlsLayout->addWidget(weightLabel, 0, 2);
    controlsLayout->addWidget(xLabel, 1, 2, Qt::AlignCenter);
    controlsLayout->addWidget(xValueLabel, 1, 3, Qt::AlignCenter);
//    controlsLayout->addWidget(quantityColLabel, 5, 0, Qt::AlignCenter);
//    controlsLayout->addWidget(weightColLabel, 5, 1, Qt::AlignCenter);
//    controlsLayout->addWidget(temperatureColLabel, 5, 2, Qt::AlignCenter);
//    controlsLayout->addWidget(pressureColLabel, 5, 3, Qt::AlignCenter);
//    controlsLayout->addWidget(volumeColLabel, 5, 4, Qt::AlignCenter);
    controlsLayout->addWidget(simulateButton, 4, 0);
    controlsLayout->addWidget(abortButton, 4, 1);
    controlsLayout->addWidget(sortButton, 4, 3);
    controlsLayout->addWidget(sortCombo, 4, 2, Qt::AlignRight);
    controlsLayout->addWidget(quantityLineEdit, 0, 1, Qt::AlignLeft);
    controlsLayout->addWidget(weightLineEdit, 0, 3, Qt::AlignLeft);
    controlsLayout->addWidget(temperatureLineEdit, 1, 1, Qt::AlignLeft);
    controlsLayout->addWidget(outputTextEdit, 6, 0, 8, 4);
//    controlsLayout->addWidget(minimumSpinBox, 0, 1);
//    controlsLayout->addWidget(maximumSpinBox, 1, 1);
//    controlsLayout->addWidget(valueSpinBox, 2, 1);
//    controlsLayout->addWidget(invertedAppearance, 0, 2);
//    controlsLayout->addWidget(invertedKeyBindings, 1, 2);
    controlsLayout->addWidget(pressureSlider, 2, 1, 1, 3);
    controlsLayout->addWidget(volumeSlider, 3, 1, 1, 3);
    controlsGroup->setLayout(controlsLayout);
}

int Window::getWeight()
{
    if (weightLineEdit)
    {
        int tempWeight = weightLineEdit->text().toInt();
        if (tempWeight<0)
            tempWeight=100;
        else
            tempWeight=tempWeight*10+100;
        return tempWeight;
    }

    return 100;
}

void ProxyLineEdit::setValue(const QString &v)
{
    int newValue = v.toInt();
    if (newValue<0)
        newValue=100;
    else
        newValue=newValue*10+100;
    emit valueChanged(QString::number(newValue)+=" N");
}

