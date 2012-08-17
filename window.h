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

#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QSlider>
#include <QString>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QComboBox;
class QGroupBox;
class QLabel;
//class QSpinBox;
class QStackedWidget;
class QPushButton;
class QLineEdit;
class QTextEdit;
class QSlider;
class QString;
QT_END_NAMESPACE
class SlidersGroup;
class ProxyLineEdit;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();
    int getWeight();

private:
    void createControls(const QString &title);

    SlidersGroup *horizontalSliders;
    SlidersGroup *verticalSliders;
    QStackedWidget *stackedWidget;

    QGroupBox *controlsGroup;
    QLabel *quantityLabel;
    QLabel *weightLabel;
    QLabel *temperatureLabel;
    QLabel *pressureLabel;
    QLabel *volumeLabel;
    QLabel *quantityColLabel;
    QLabel *weightColLabel;
    QLabel *temperatureColLabel;
    QLabel *pressureColLabel;
    QLabel *volumeColLabel;
    QLabel *xLabel;
    QLabel *xValueLabel;
//    QLabel *minimumLabel;
//    QLabel *maximumLabel;
//    QLabel *valueLabel;
//    QCheckBox *invertedAppearance;
//    QCheckBox *invertedKeyBindings;
//    QSpinBox *minimumSpinBox;
//    QSpinBox *maximumSpinBox;
//    QSpinBox *valueSpinBox;
    QString *str;
    QPushButton *simulateButton;
    QPushButton *abortButton;
    QPushButton *sortButton;
    QComboBox *sortCombo;
    QLineEdit *quantityLineEdit;
    QLineEdit *weightLineEdit;
    QLineEdit *temperatureLineEdit;
    QTextEdit *outputTextEdit;
    QSlider *pressureSlider;
    QSlider *volumeSlider;
    ProxyLineEdit *temp;
};

class ProxyLineEdit : public QObject
{
Q_OBJECT
public:

signals:
void valueChanged(QString);

public slots:
void setValue(const QString &);
};

#endif
