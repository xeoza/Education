from PyQt5 import QtWidgets, uic
from PyQt5.QtGui import QPen, QPainter, QColor, QBrush, QImage, QPixmap, QRgba64
from PyQt5.QtCore import Qt
from math import cos, sin, pi, radians, copysign, fabs
import numpy as np
import time


class Window(QtWidgets.QMainWindow):
    def __init__(self):
        QtWidgets.QWidget.__init__(self)
        uic.loadUi("window.ui", self)
        self.scene = QtWidgets.QGraphicsScene(0, 0, 515, 550)
        self.mainview.setScene(self.scene)
        self.image = QImage(515, 550, QImage.Format_ARGB32_Premultiplied)
        self.pen = QPen()
        self.color_line = QColor(Qt.black)
        self.color_bground = QColor(Qt.white)
        self.draw_line.clicked.connect(lambda: draw_line(self))
        self.clean_all.clicked.connect(lambda : clear_all(self))
        self.btn_bground.clicked.connect(lambda: get_color_bground(self))
        self.btn_line.clicked.connect(lambda: get_color_line(self))
        self.draw_sun.clicked.connect(lambda: draw_sun(self))
        self.cda.setChecked(True)


def sign(x):
    if x == 0:
        return 0
    else:
        return x/abs(x)


def lineCDA(win, p1, p2):
    deltaX, deltaY = abs(p1[0] - p2[0]), abs(p1[1] - p2[1]) #x2 - x1, y2 - y1

    length = max(deltaX, deltaY) #выбор dx или dy

    if length == 0: #проверка на вырожденность
        win.image.setPixel(p1[0], p1[1], win.pen.color().rgb())
        return

    dX, dY = (p2[0] - p1[0]) / length, (p2[1] - p1[1]) / length

    x, y = p1[0] + 0.5 * sign(dX), p1[1] + 0.5 * sign(dY)

    while length > 0:
        win.image.setPixel(x, y, win.pen.color().rgb())
        x += dX
        y += dY
        length -= 1


def bresenhamMethodFloat(win, p1, p2):
    if p1 == p2: #вырожденность
        win.image.setPixel(p1[0], p1[1], win.pen.color().rgb())
        return

    dx, dy = p2[0] - p1[0], p2[1] - p1[1]
    sx, sy = sign(dx), sign(dy)
    dx, dy = abs(dx), abs(dy)
    x, y = p1[0], p1[1]

    isChange = False
    if dy > dx: #проверка на обмен
        dx, dy = dy, dx
        isChange = True

    h = dy / dx #тангенс угла наклона 
    e = h - 0.5
    i = 1
    while i <= dx:
        win.image.setPixel(x, y, win.pen.color().rgb())
        if e >= 0:
            if isChange is False:
                y += sy
            else:
                x += sx
            e -= 1

        if e < 0:
            if isChange is False:
                x += sx
            else:
                y += sy
            e += h
        i+=1


def bresenhamMethodInt(win, p1, p2):
    if p1 == p2:
        win.image.setPixel(p1[0], p1[1], win.pen.color().rgb())
        return

    dx, dy = p2[0] - p1[0], p2[1] - p1[1]
    sx, sy = sign(dx), sign(dy)
    dx, dy = abs(dx), abs(dy)
    x,y = p1[0], p1[1]

    isChange = False
    if dy > dx:
        dx, dy = dy, dx
        isChange = True

    e = 2 * dy - dx
    i = 1
    while i <= dx:
        win.image.setPixel(x, y, win.pen.color().rgb())
        if e >= 0:
            if isChange == 0:
                y += sy
            else:
                x += sx
            e -= 2 * dx

        if e < 0:
            if isChange == 0:
                x += sx
            else:
                y += sy
            e += (2 * dy)
        i += 1


def bresenhamMethodSmooth(win, p1, p2):
    if p1 == p2:
        win.image.setPixel(p1[0], p1[1], win.pen.color().rgb())
        return

    win.pen.setColor(win.color_line)
    dx, dy = p2[0] - p1[0], p2[1] - p1[1]
    sx, sy = sign(dx), sign(dy)
    dx, dy = abs(dx), abs(dy)
    x, y = p1[0], p1[1]

    h = (dy / dx) if dx != 0 else 0

    i_max = 256

    isChange = False
    if dy > dx:
        dx, dy = dy, dx
        isChange = True
        if h:
            h = 1 / h

    h *= i_max
    e = i_max/2
    w = i_max - h #  пороговое значени
    i = 1
    while i <= dx:

        new = QColor()
        new.setRgb(0, 0, 0, alpha=255 - e)
        win.pen.setColor(new)
        win.image.setPixel(x, y, win.pen.color().rgba())
      
        if e <= w:
            if isChange:
                y += sy
            else:
                x += sx
            e += h
        else:
            x += sx
            y += sy
            e -= w
        i += 1



def draw_line(win):
    bx, by = win.begin_x.value(), win.begin_y.value()
    ex, ey = win.end_x.value(), win.end_y.value()
    is_standart = False
    win.image.fill(win.color_bground)
    if win.cda.isChecked():
        start = time.clock()
        lineCDA(win, [bx, by], [ex, ey])
        end = time.clock()
    if win.br_float.isChecked():
        start = time.clock()
        bresenhamMethodFloat(win, [bx, by], [ex, ey])
        end = time.clock()
    if win.br_int.isChecked():
        start = time.clock()
        bresenhamMethodInt(win, [bx, by], [ex, ey])
        end = time.clock()
    if win.br_smooth.isChecked():
        start = time.clock()
        bresenhamMethodSmooth(win, [bx, by], [ex, ey])
        end = time.clock()
    if win.lib.isChecked():
        is_standart = True
        start = time.clock()
        win.scene.addLine(bx, by, ex, ey, win.pen)
        end = time.clock()

    if not is_standart:
        pix = QPixmap(511, 511)
        pix.convertFromImage(win.image)
        win.scene.addPixmap(pix)

    win.label.setText("{0:.3f}msc".format((end - start)*1000))


def draw_sun(win):
    d = win.spin_dia.value()
    spin = win.spin_angle.value()
    bx, by = 255, 255
    win.image.fill(win.color_bground)
    is_standart = False
    for i in np.arange(0, 360, spin):
        ex = cos(radians(i)) * d + 255
        ey = sin(radians(i)) * d + 255

        if win.cda.isChecked():
            start = time.clock()
            lineCDA(win, [bx, by], [ex, ey])
            end = time.clock()
        if win.br_float.isChecked():
            start = time.clock()
            bresenhamMethodFloat(win, [bx, by], [ex, ey])
            end = time.clock()
        if win.br_int.isChecked():
            start = time.clock()
            bresenhamMethodInt(win, [bx, by], [ex, ey])
            end = time.clock()
        if win.br_smooth.isChecked():
            start = time.clock()
            bresenhamMethodSmooth(win, [bx, by], [ex, ey])
            end = time.clock()
        if win.lib.isChecked():
            is_standart = True
            start = time.clock()
            win.scene.addLine(bx, by, ex, ey, win.pen)
            end = time.clock()

    if not is_standart:
        pix = QPixmap(511, 511)
        pix.convertFromImage(win.image)
        win.scene.addPixmap(pix)

    win.label.setText("{0:.3f}msc".format((end - start) * 1000))


def get_color_bground(win):
    color = QtWidgets.QColorDialog.getColor(initial=Qt.white, title='Цвет фона',
                                            options=QtWidgets.QColorDialog.DontUseNativeDialog)
    if color.isValid():
        win.color_bground = color
        win.image.fill(color)
        s = QtWidgets.QGraphicsScene(0, 0, 10, 10)
        s.setBackgroundBrush(color)
        win.bground_color.setScene(s)
        win.scene.setBackgroundBrush(color)


def get_color_line(win):
    color = QtWidgets.QColorDialog.getColor(initial=Qt.black, title='Цвет линии',
                                            options=QtWidgets.QColorDialog.DontUseNativeDialog)
    if color.isValid():
        win.color_line = color
        win.pen.setColor(color)
        s = QtWidgets.QGraphicsScene(0, 0, 10, 10)
        s.setBackgroundBrush(color)
        win.line_color.setScene(s)


def clear_all(win):
    win.image.fill(Qt.color0)
    win.scene.clear()


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    w = Window()
    w.show()
    sys.exit(app.exec_())
