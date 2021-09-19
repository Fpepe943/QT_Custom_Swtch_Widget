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


#include <QStyleOption>
#include "qcswitchwidget.h"

////////////////////////////////////////////////////////////////////////////////////////////////
SwitchBackground::SwitchBackground(QWidget* parent, QColor color, bool rect)
        : QWidget(parent)
        , _rect(rect)
        , _borderradius(12)
        , _color(color)
        , _pencolor(QColor(170, 170, 170))
{
    setFixedHeight(20);

    _gradient = QLinearGradient(0, 25, 70, 0);
    _gradient.setColorAt(0, QColor(154, 194, 50));
    _gradient.setColorAt(0.25, QColor(154, 210, 50));
    _gradient.setColorAt(0.95, QColor(154, 194, 50));

    _gdisabled = QLinearGradient(0, 25, 70, 0);
    _gdisabled.setColorAt(0, QColor(190, 190, 190));
    _gdisabled.setColorAt(0.25, QColor(230, 230, 230));
    _gdisabled.setColorAt(0.95, QColor(190, 190, 190));

    if (_rect)
        _borderradius = 0;

    _enabled = true;
}
SwitchBackground::~SwitchBackground()
{
}
void SwitchBackground::paintEvent(QPaintEvent*)
{
    QPainter* painter = new QPainter;
    painter->begin(this);
    painter->setRenderHint(QPainter::Antialiasing, true);

    QPen pen(Qt::NoPen);
    painter->setPen(pen);
    if (_enabled)
    {
        painter->setBrush(QColor(154, 190, 50));
        painter->drawRoundedRect(0, 0
                , width(), height()
                , 10, 10);

        painter->setBrush(_gradient);
        painter->drawRoundedRect(1, 1, width()-2, height()-2, 8, 8);
    }
    else
    {
        painter->setBrush(QColor(150, 150, 150));
        painter->drawRoundedRect(0, 0
                , width(), height()
                , 10, 10);

        painter->setBrush(_gdisabled);
        painter->drawRoundedRect(1, 1, width() - 2, height() - 2, 8, 8);
    }
    painter->end();
}
void SwitchBackground::setEnabled(bool flag)
{
    _enabled = flag;
}

////////////////////////////////////////////////////////////////////////////////////////////////
SwitchCircle::SwitchCircle(QWidget* parent, QColor color, bool rect)
        : QWidget(parent)
        , _rect(rect)
        , _borderradius(12)
        , _color(color)
        , _pencolor(QColor(120, 120, 120))
{
    setFixedSize(20, 20);

    _radGradient = QRadialGradient(static_cast<int>(width() / 2), static_cast<int>(height() / 2), 12);
    _radGradient.setColorAt(0, QColor(255, 255, 255));
    _radGradient.setColorAt(0.6, QColor(255, 255, 255));
    _radGradient.setColorAt(1, QColor(205, 205, 205));

    _gradient = QLinearGradient(3, 18, 20, 4);
    _gradient.setColorAt(0, QColor(255, 255, 255));
    _gradient.setColorAt(0.55, QColor(230, 230, 230));
    _gradient.setColorAt(0.72, QColor(255, 255, 255));
    _gradient.setColorAt(1, QColor(255, 255, 255));

    _gdisabled = QLinearGradient(3, 18, 20, 4);
    _gdisabled.setColorAt(0, QColor(230, 230, 230));
    _gdisabled.setColorAt(0.55, QColor(210, 210, 210));
    _gdisabled.setColorAt(0.72, QColor(230, 230, 230));
    _gdisabled.setColorAt(1, QColor(230, 230, 230));

    _enabled = true;
}
SwitchCircle::~SwitchCircle()
{
}
void SwitchCircle::paintEvent(QPaintEvent*)
{
    QPainter* painter = new QPainter;
    painter->begin(this);
    painter->setRenderHint(QPainter::Antialiasing, true);

    QPen pen(Qt::NoPen);
    painter->setPen(pen);
    painter->setBrush(_pencolor);

    painter->drawEllipse(0, 0, 20, 20);
    painter->setBrush(_radGradient);
    painter->drawEllipse(1, 1, 18, 18);

    painter->setBrush(QColor(210, 210, 210));
    painter->drawEllipse(2, 2, 16, 16);

    if (_enabled)
    {
        painter->setBrush(_gradient);
        painter->drawEllipse(3, 3, 14, 14);
    }
    else
    {
        painter->setBrush(_gdisabled);
        painter->drawEllipse(3, 3, 14, 14);
    }

    painter->end();
}
void SwitchCircle::setEnabled(bool flag)
{
    _enabled = flag;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

SwitchButton::SwitchButton(QWidget* parent, Style style)
        : QWidget(parent)
        , _value(false)
        , _duration(100)
        , _enabled(true)
{
    _pencolor = QColor(120, 120, 120);

    _gradient1 = QLinearGradient(35, 30, 35, 0);
    _gradient1.setColorAt(0, QColor(210, 210, 210));
    _gradient1.setColorAt(0.25, QColor(255, 255, 255));
    _gradient1.setColorAt(0.82, QColor(255, 255, 255));
    _gradient1.setColorAt(1, QColor(210, 210, 210));

    _gradient2 = QLinearGradient(50, 30, 35, 0);
    _gradient2.setColorAt(0, QColor(230, 230, 230));
    _gradient2.setColorAt(0.25, QColor(255, 255, 255));
    _gradient2.setColorAt(0.82, QColor(255, 255, 255));
    _gradient2.setColorAt(1, QColor(230, 230, 230));

    _gdisabled = QLinearGradient(50, 30, 35, 0);
    _gdisabled.setColorAt(0, QColor(200, 200, 200));
    _gdisabled.setColorAt(0.25, QColor(230, 230, 230));
    _gdisabled.setColorAt(0.82, QColor(230, 230, 230));
    _gdisabled.setColorAt(1, QColor(200, 200, 200));

    _offcolor = QColor(255, 255, 255);
    _oncolor = QColor(154, 205, 50);
    _tol = 0;
    _borderradius = 12;
    _labeloff = new QLabel(this);
    _background = new SwitchBackground(this, _oncolor);
    _labelon = new QLabel(this);
    _circle = new SwitchCircle(this, _offcolor);
    __btn_move = new QPropertyAnimation(this);
    __back_move = new QPropertyAnimation(this);

    __btn_move->setTargetObject(_circle);
    __btn_move->setPropertyName("pos");
    __back_move->setTargetObject(_background);
    __back_move->setPropertyName("size");

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    _labeloff->setText("Off");
    _labelon->setText("On");
    _labeloff->move(27, 3);
    _labelon->move(5, 3);
    setFixedSize(QSize(70, 24));
    if (style == Style::YESNO)
    {
        _labeloff->setText("No");
        _labelon->setText("Yes");
        _labeloff->move(33, 3);
        _labelon->move(8, 3);
        setFixedSize(QSize(70, 24));
    }
    else if (style == Style::TRUEFALSE)
    {
        _labeloff->setText("False");
        _labelon->setText("True");
        _labeloff->move(38, 3);
        _labelon->move(7, 3);
        setFixedSize(QSize(85, 24));
    }
    if (style == Style::EMPTY)
    {
        _labeloff->setText("");
        _labelon->setText("");
        setFixedSize(QSize(55, 24));
    }

    _labeloff->setStyleSheet("color: rgb(120, 120, 120); font-weight: bold;");
    _labelon->setStyleSheet("color: rgb(255, 255, 255); font-weight: bold;");

    _background->resize(20, 20);

    _background->move(2, 2);
    _circle->move(2, 2);
}

SwitchButton::~SwitchButton()
{
    delete _circle;
    delete _background;
    delete _labeloff;
    delete _labelon;
    delete __btn_move;
    delete __back_move;
    //delete ui;
}
void SwitchButton::paintEvent(QPaintEvent*)
{
    QPainter* painter = new QPainter;
    painter->begin(this);
    painter->setRenderHint(QPainter::Antialiasing, true);

    QPen pen(Qt::NoPen);
    painter->setPen(pen);

    painter->setBrush(_pencolor);
    painter->drawRoundedRect(0, 0, width(), height(), 12, 12);

    painter->setBrush(_gradient1);
    painter->drawRoundedRect(1, 1, width() - 2, height() - 2, 10, 10);

    painter->setBrush(QColor(210, 210, 210));
    painter->drawRoundedRect(2, 2, width() - 4, height() - 4, 10, 10);

    if (_enabled)
    {
        painter->setBrush(_gradient2);
        painter->drawRoundedRect(3, 3, width() - 6, height() - 6, 7, 7);
    }
    else
    {
        painter->setBrush(_gdisabled);
        painter->drawRoundedRect(3, 3, width() - 6, height() - 6, 7, 7);
    }
    painter->end();
}
void SwitchButton::mousePressEvent(QMouseEvent*)
{
    if (!_enabled)
        return;

    __btn_move->stop();
    __back_move->stop();

    __btn_move->setDuration(_duration);
    __back_move->setDuration(_duration);

    int hback = 20;
    QSize initial_size(hback, hback);
    QSize final_size(width() - 4, hback);

    int xi = 2;
    int y  = 2;
    int xf = width() - 22;

    if (_value)
    {
        final_size = QSize(hback, hback);
        initial_size = QSize(width() - 4, hback);

        xi = xf;
        xf = 2;
    }

    __btn_move->setStartValue(QPoint(xi, y));
    __btn_move->setEndValue(QPoint(xf, y));

    __back_move->setStartValue(initial_size);
    __back_move->setEndValue(final_size);

    __btn_move->start();
    __back_move->start();

    // Assigning new current value
    _value = !_value;
   // emit valueChanged(_value);
}
void SwitchButton::setEnabled(bool flag)
{
    _enabled = flag;
    _circle->setEnabled(flag);
    _background->setEnabled(flag);
    if (flag)
        _labelon->show();
    else
    {
        if (value())
            _labelon->show();
        else
            _labelon->hide();
    }
    QWidget::setEnabled(flag);
}
void SwitchButton::setValue(bool flag)
{
    if (flag == value())
        return;
    else
    {
        _value = flag;
        _update();
        setEnabled(_enabled);
    }
}
bool SwitchButton::value() const
{
    return _value;
}
void SwitchButton::_update()
{
    int hback = 20;
    QSize final_size(width() - 4, hback);

    int y = 2;
    int xf = width() - 22;

    if (_value)
    {
        final_size = QSize(hback, hback);
        xf = 2;
    }

    _circle->move(QPoint(xf, y));
    _background->resize(final_size);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////

ToggleButton::ToggleButton(int trackRadius, int thumbRadius, QWidget* parent)
        : QAbstractButton(parent)
{
    setCheckable(true);
    setSizePolicy(QSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed));
    mTrackRadius = trackRadius;
    mThumbRadius = thumbRadius;
    mAnimation = new QPropertyAnimation(this);
    mAnimation->setTargetObject(this);

    mMargin = 0 > (mThumbRadius - mTrackRadius) ? 0 : (mThumbRadius - mTrackRadius);
    mBaseOffset = mThumbRadius > mTrackRadius ? mThumbRadius : mTrackRadius;
    mEndOffset.insert(true, 4 * mTrackRadius + 2 * mMargin - mBaseOffset); // width - offset
    mEndOffset.insert(false, mBaseOffset);
    mOffset = mBaseOffset;
    QPalette palette = this->palette();

    if (mThumbRadius > mTrackRadius)
    {
        mTrackColor.insert(true, palette.highlight());
        mTrackColor.insert(false, palette.dark());
        mThumbColor.insert(true, palette.highlight());
        mThumbColor.insert(false, palette.light());
        mTextColor.insert(true, palette.highlightedText().color());
        mTextColor.insert(false, palette.dark().color());
        mThumbText.insert(true, "");
        mThumbText.insert(false, "");
        mOpacity = 0.5;
    }
    else
    {
        mTrackColor.insert(true, palette.highlight());
        mTrackColor.insert(false, palette.dark());
        mThumbColor.insert(true, palette.highlightedText());
        mThumbColor.insert(false, palette.light());
        mTextColor.insert(true, palette.highlight().color());
        mTextColor.insert(false, palette.dark().color());
        mThumbText.insert(true, QChar(0x2714)); // check character
        mThumbText.insert(false, QChar(0x2715)); // uncheck character
        mOpacity = 1.0;
    }
}
ToggleButton::~ToggleButton()
{
    delete mAnimation;
}
QSize ToggleButton::sizeHint() const
{
    int w = 4 * mTrackRadius + 2 * mMargin;
    int h = 2 * mTrackRadius + 2 * mMargin;

    return QSize(w, h);
}
void ToggleButton::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QPainter::RenderHints m_paintFlags = QPainter::RenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    p.setRenderHints(m_paintFlags, true);
    p.setPen(Qt::NoPen);
    bool check = isChecked();
    qreal trackOpacity = mOpacity;
    qreal textOpacity = 1.0;
    qreal thumbOpacity = 1.0;
    QBrush trackBrush;
    QBrush thumbBrush;
    QColor textColor;

    if (this->isEnabled())
    {

        trackBrush = mTrackColor[check];
        thumbBrush = mThumbColor[check];
        textColor = mTextColor[check];
    }
    else
    {
        trackOpacity *= 0.8;
        trackBrush = this->palette().shadow();
        thumbBrush = this->palette().mid();
        textColor = this->palette().shadow().color();
    }

    p.setBrush(trackBrush);
    p.setOpacity(trackOpacity);
    p.drawRoundedRect(mMargin, mMargin, width() - 2 * mMargin, height() - 2 * mMargin, mTrackRadius, mTrackRadius);

    p.setBrush(thumbBrush);
    p.setOpacity(thumbOpacity);
    p.drawEllipse(mOffset - mThumbRadius, mBaseOffset - mThumbRadius, 2 * mThumbRadius, 2 * mThumbRadius);

    p.setPen(textColor);
    p.setOpacity(textOpacity);
    QFont font = p.font();
    font.setPixelSize(1.5*mThumbRadius);
    p.setFont(font);

    p.drawText(QRectF(mOffset - mThumbRadius,
                      mBaseOffset - mThumbRadius,
                      2 * mThumbRadius,
                      2 * mThumbRadius),
               Qt::AlignCenter,
               mThumbText.value(check));
}
void ToggleButton::resizeEvent(QResizeEvent* e)
{
    QAbstractButton::resizeEvent(e);
    mOffset = mEndOffset.value(isChecked());
}
void ToggleButton::mouseReleaseEvent(QMouseEvent  *e)
{
    QAbstractButton::mouseReleaseEvent(e);
    if (e->button() == Qt::LeftButton)
    {
        mAnimation->setDuration(120);
        mAnimation->setPropertyName("mOffset");
        mAnimation->setStartValue(mOffset);
        mAnimation->setEndValue(mEndOffset[isChecked()]);
        mAnimation->start();
    }
}
void ToggleButton::enterEvent(QEvent * event)
{
    setCursor(Qt::PointingHandCursor);
    QAbstractButton::enterEvent(event);
}
void ToggleButton::setChecked(bool checked)
{
    QAbstractButton::setChecked(checked);
    mOffset = mEndOffset.value(checked);
}
int ToggleButton::offset()
{
    return mOffset;
}
void ToggleButton::setOffset(int value)
{
    mOffset = value;
    update();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
