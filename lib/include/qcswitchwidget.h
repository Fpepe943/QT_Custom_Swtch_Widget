//
// Created by filippo on 18/09/21.
//
/***************************************************************************
**                                                                        **
**  QcSwitch, for instrumentation                                         **
**  visualization widget for Qt.                                          **
**  Copyright (C) 2021 Filippo Pepe                                       **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU Lesser General Public License as        **
**  published by the Free Software Foundation, either version 3 of the    **
**  License, or (at your option) any later version.                       **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU Lesser General Public License for more details.                   **
**                                                                        **
**  You should have received a copy of the GNU Lesser General Public      **
**  License along with this program.                                      **
**  If not, see http://www.gnu.org/licenses/.                             **
**                                                                        **
****************************************************************************
**           Author:  Filippo Pepe                                        **
**           Date:    17 sept 2021                                        **
**           Version:  1.0                                                **
****************************************************************************/

#ifndef QCUSTOMSWITCHWIDGET_QCSWITCHWIDGET_H
#define QCUSTOMSWITCHWIDGET_QCSWITCHWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QObject>
#include <QLabel>
#include <QPropertyAnimation>
#include <QAbstractButton>
#include <QMouseEvent>

#if defined(QCSWITCH_COMPILE_LIBRARY)
#  define QCSWITCH_DECL  Q_DECL_EXPORT
#elif defined(QCSWITCH_USE_LIBRARY)
#  define QCSWITCH_DECL Q_DECL_IMPORT
#else
#  define QCSWITCH_DECL
#endif

class QCSWITCH_DECL SwitchBackground : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(SwitchBackground)

public:
    explicit SwitchBackground(QWidget* parent = nullptr, QColor color = QColor(154, 205, 50), bool rect = false);
    ~SwitchBackground() override;

    //-- QWidget methods
    void paintEvent(QPaintEvent* event) override;
    void setEnabled(bool);

private:
    bool            _rect;
    int             _borderradius;
    QColor          _color;
    QColor          _pencolor;
    QLinearGradient _gradient;
    QLinearGradient _gdisabled;

    bool _enabled;
};

class QCSWITCH_DECL SwitchCircle : public QWidget
{
Q_OBJECT
    Q_DISABLE_COPY(SwitchCircle)

public:
    explicit SwitchCircle(QWidget* parent = nullptr, QColor color = QColor(255, 255, 255), bool rect = false);
    ~SwitchCircle() override;

    //-- QWidget methods
    void paintEvent(QPaintEvent* event) override;
    void setEnabled(bool);

private:
    bool            _rect;
    int             _borderradius;
    QColor          _color;
    QColor          _pencolor;
    QRadialGradient _radGradient;
    QLinearGradient _gradient;
    QLinearGradient _gdisabled;

    bool _enabled;
};

class QCSWITCH_DECL SwitchButton : public QWidget
{
    Q_OBJECT
    //Q_DISABLE_COPY(SwitchButton)

public:
    enum Style
    {
        YESNO,
        ONOFF,
        TRUEFALSE,
        EMPTY
    };

public:
    SwitchButton(QWidget *parent = nullptr, Style style = Style::ONOFF);

    ~SwitchButton();

    //-- QWidget methods
    void mousePressEvent(QMouseEvent *) override;
    void paintEvent(QPaintEvent* event) override;
    void setEnabled(bool);

    //-- Setters
    void setValue(bool);

    //-- Getters
    bool value() const;

signals:
    void valueChanged(bool newValue);

private:
    bool _value;
    int  _duration;

    QLinearGradient _gradient1;
    QLinearGradient _gradient2;
    QLinearGradient _gdisabled;

    QColor _pencolor;
    QColor _offcolor;
    QColor _oncolor;
    int    _tol;
    int    _borderradius;

    // This order for definition is important (these widgets overlap)
    QLabel*           _labeloff;
    SwitchBackground* _background;
    QLabel*           _labelon;
    SwitchCircle*     _circle;

    bool _enabled=true;

    QPropertyAnimation* __btn_move;
    QPropertyAnimation* __back_move;
    void _update();


};

class QCSWITCH_DECL ToggleButton :public QAbstractButton
{
Q_OBJECT
    Q_PROPERTY(int mOffset READ offset WRITE setOffset);
public:
    explicit ToggleButton(int trackRadius, int thumbRadius, QWidget* parent = nullptr);
    ~ToggleButton();

    QSize sizeHint() const;

protected:
    void paintEvent(QPaintEvent *) ;
    void resizeEvent(QResizeEvent*) ;
    void mouseReleaseEvent(QMouseEvent  *) ;
    void enterEvent(QEvent *event) ;
    void setChecked(bool checked);

    int offset();
    void setOffset(int value);

private:
    qreal mOffset;
    qreal mBaseOffset;
    qreal mMargin;
    qreal mTrackRadius;
    qreal mThumbRadius;
    qreal mOpacity;
    QPropertyAnimation* mAnimation;

    QHash<bool, qreal> mEndOffset;
    QHash<bool, QBrush> mTrackColor;
    QHash<bool, QBrush> mThumbColor;
    QHash<bool, QColor> mTextColor;
    QHash<bool, QString> mThumbText;

};

#endif //QCUSTOMSWITCHWIDGET_QCSWITCHWIDGET_H
