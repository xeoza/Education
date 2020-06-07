# Python version 3.6
import sys,copy
from PyQt5.QtWidgets import *
from PyQt5.QtWidgets import QPushButton
from PyQt5.QtGui import QPainter,QColor,QPen,QCursor,QImage,QPixmap
from PyQt5.QtCore import Qt,QObject,QPoint

WIDTH = 500
HIGHT = 480

edges = []
edges_slave = []

def sign(x):
    if (x > 0):
        return 1
    elif (x < 0):
        return -1
    else:
        return 0
        

class Example(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()
        

    def fill_invert(self):
        color_fill = self.colormain
        color_background = QColor(255,255,255).rgb()
        for rebr in edges:
            old = -1
            old_sy = -1
            flag = False
            for j in range(len(rebr)-1):
                x1 = rebr[j][0]
                y1 = rebr[j][1]
                x2 = rebr[j+1][0]
                y2 = rebr[j+1][1]

                dx = int(x2 - x1)
                dy = int(y2 - y1)
                sx = sign(dx)
                sy = sign(dy)
                dx = abs(dx)
                dy = abs(dy)

                if (j == 0):
                    first_sy = sy
                elif (j == len(rebr)-2):
                    if (sy < 0 and first_sy < 0 or sy > 0 and first_sy > 0):
                        flag = True

                if (sy == 0):
                    continue

                if (sy < 0 and old_sy > 0 or sy > 0 and old_sy < 0):
                    old = -1
                old_sy = sy

                swap = False
                if (dy <= dx):
                    swap = False
                else:
                    swap = True
                    dx,dy = dy,dx
    
                e = int(2*dy-dx)
                x = int(x1)
                y = int(y1)
            
                color = QColor(0,0,0)

                for i in range(dx+1):
                    slave_x = x
                    if (old != y):
                        if flag and y ==  rebr[0][1]:
                            continue
                        while slave_x < WIDTH:
                                current_color = self.image.pixelColor(slave_x,y)
                                if current_color.rgb() == color_background:
                                    self.image.setPixel(int(slave_x),int(y),color_fill)
                                else:
                                    self.image.setPixel(int(slave_x),int(y),color_background)
                                slave_x += 1
                        old = y
                    QApplication.processEvents()
                    if (e>=0):
                        if (swap):
                            x += sx
                        else:
                            y +=sy
                        e = e-2*dx
                    if (e < 0): 
                        if (swap):
                            y +=sy
                        else:
                            x += sx
                        e = e+2*dy
                    self.repaint()
                main_old =y2
            

    def Bresenham(self,x1,y1,x2,y2,color = QColor(0,0,0).rgb()):
            dx = int(x2 - x1)
            dy = int(y2 - y1)
            sx = sign(dx)
            sy = sign(dy)
            dx = abs(dx)
            dy = abs(dy)    

            swap = False
            if (dy <= dx):
                swap = False
            else:
                swap = True
                dx,dy = dy,dx
        
    
            e = int(2*dy-dx)
            x = int(x1)
            y = int(y1)
            
            for i in range(dx+1):
                self.image.setPixel(x,y,color)
                if (e>=0):
                    if (swap):
                        x += sx
                    else:
                        y +=sy
                    e = e-2*dx
                if (e < 0): 
                    if (swap):
                        y +=sy
                    else:
                        x += sx
                    e = e+2*dy


    def initUI(self):      
        self.setGeometry(100,100, 800, 500)
        self.setWindowTitle('Points')
        self.Group = QHBoxLayout(self)
        self.v = QVBoxLayout()
        self.GraphView = QGraphicsView(self)
        self.scene = QGraphicsScene(self)
        self.image = QImage(WIDTH,HIGHT - 20,QImage.Format_RGB32)

        self.Group.addWidget(self.GraphView)
        self.Group.addLayout(self.v)
        self.image.fill(Qt.white)
        
        self.GraphView.setGeometry(10,10,WIDTH,HIGHT )
        self.GraphView.setStyleSheet("background-color: white")
        self.scene.addPixmap(QPixmap.fromImage(self.image))

        self.GraphView.setScene(self.scene)        

        self.fill_butt = QPushButton('Fill', self)
        self.fill_butt.resize(self.fill_butt.sizeHint())

        self.table = QTableWidget(self)
        self.table.setColumnCount(2)
        self.table.setHorizontalHeaderLabels(["x","y"])
        self.v.addWidget(self.table)

        v1 = QHBoxLayout()
        
        self.clear = QPushButton('Clear', self)
        self.clear.resize(self.fill_butt.sizeHint())
        v1.addWidget(self.clear)
        
        self.Add = QPushButton('Add', self)
        self.Add.resize(self.fill_butt.sizeHint())
        v1.addWidget(self.Add)
        self.v.addLayout(v1)
        self.v.addWidget(self.fill_butt)

        self.color_button = QPushButton(self)
        self.color_button.setGeometry(800,100,40,20)

        self.v.addWidget(self.color_button)
        
        self.colormain = QColor(0,255,0).rgb()
        self.color_button.setStyleSheet('QPushButton{background-color:'+QColor(0,255,0).name()+'}')
        self.capslock = False

        self.color_button.clicked.connect(lambda: self.GetColor())
        self.Add.clicked.connect(lambda: self.ShowDialog())
        self.fill_butt.clicked.connect(lambda: self.Fill())
        self.clear.clicked.connect(lambda: self.Clear())
        self.show()
    

    def keyPressEvent(self, QKeyEvent):
        if QKeyEvent.key() == 16777252:
            self.capslock = not self.capslock
    

    def GetColor(self):
        color = QColorDialog.getColor()
        self.colormain = color.rgb()
        hexcolor = color.name()
        self.color_button.setStyleSheet('QPushButton{background-color:'+hexcolor+'}')


    def Fill(self):
        self.fill_invert()
        self.draw_borders()
        
   
    def ShowDialog(self):
        text, ok = QInputDialog.getText(self, 'Input Dialog', 'Enter X Y:')
        if ok:
            text = text.split()
            x = int(text[0])
            y = int(text[1])
            i = len(edges_slave)
            if i:
                self.Bresenham(edges_slave[i-1][0],edges_slave[i-1][1],x,y)
            edges_slave.append([x,y])
            self.table_appender([x,y])


    def Clear(self):
        edges.clear()
        edges_slave.clear()
        self.table.setRowCount(0)
        self.image.fill(Qt.white)


    def draw_borders(self):
        for j in range(len(edges)):
            for i in range(len(edges[j])-1):
                self.Bresenham(edges[j][i][0],edges[j][i][1],edges[j][i+1][0],edges[j][i+1][1])
        self.repaint()
        

    def mousePressEvent(self, QMouseEvent):
        if (QMouseEvent.button() == Qt.LeftButton):
            cord = QMouseEvent.pos()
            
            y = cord.y()
            x = cord.x()
            if (x >= 10 and y>=10 and y<=HIGHT and x<=WIDTH):
                x -= 10
                y -= 10
                i = len(edges_slave)

                if self.capslock and i:
                    if y != edges_slave[i-1][1]:
                        der = (x - edges_slave[i-1][0])/(y - edges_slave[i-1][1])
                    else:
                        der  = 2
                    if abs(der) <= 1:
                        x = edges_slave[i-1][0]
                    else:
                        y = edges_slave[i-1][1]

                if i:
                    self.Bresenham(edges_slave[i-1][0],edges_slave[i-1][1],x,y)
                edges_slave.append([x,y])
                self.table_appender([x,y])

        elif (QMouseEvent.button() == Qt.RightButton):
            i = len(edges_slave)
            if i:
                x = edges_slave[0][0]
                y = edges_slave[0][1]
                self.Bresenham(edges_slave[i-1][0],edges_slave[i-1][1],x,y)
                edges_slave.append([x,y])
            edges.append(copy.deepcopy(edges_slave))
            edges_slave.clear()
            self.table_appender(['end','end'])
            

    def table_appender(self,coord):
        N = self.table.rowCount()
        self.table.setRowCount(N+1)
        self.table.setItem(N,0,QTableWidgetItem(str(coord[0])))
        self.table.setItem(N,1,QTableWidgetItem(str(coord[1])))


    def paintEvent(self, e):
        self.scene.clear()
        self.scene.addPixmap(QPixmap.fromImage(self.image))
            
                     
if __name__ == '__main__':
    app = QApplication(sys.argv)
    MainWindow = Example()   
    MainWindow.show()        
    sys.exit(app.exec_())
