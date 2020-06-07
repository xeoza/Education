# TODO: add text of task
from tkinter import *
from tkinter.filedialog import askopenfilename
from mathmodule import *

root = Tk()
root.title("Lab 1")
root.config(width = 600, height = 500)
root.geometry('500x280+550+0')
root.resizable(False, False)

Points = []
scrollbar = Scrollbar(root)
scrollbar.pack(side = RIGHT, fill = Y)

PList = Listbox(root, yscrollcommand = scrollbar.set, font = ("Arial", "14"),
                selectmode = MULTIPLE, width = 10)

Buttons = Frame(root)
top = Toplevel(root)
top.geometry('500x500+0+0')
Canv = Canvas(top, bg = 'White', width = 500, height = 600)
Cords = Frame(Buttons)

xL = Label(Cords, text = "X:")
xV = Entry(Cords, bd = 5, width = 5)
yL = Label(Cords, text = "Y:")
yV = Entry(Cords, bd = 5, width = 5)

Task = ("Task:\nFind a triangle in which the difference between the minimum " +
        "and the maximum number of points that fall " +
        "into each of the six triangles formed " +
        "by the intersection of bisectors is minimal.")

TaskText = Message(Buttons, text = Task, font = ("Arial", "14"))
TaskText.grid(row = 0, column = 0, columnspan = 2)

Answer = Label(Buttons, text = 'Ответ:')
Answer.grid(row = 3, column = 1)

xL.pack(side = LEFT)
xV.pack(side = LEFT)
yL.pack(side = LEFT)
yV.pack(side = LEFT)

scrollbar.config(command = PList.yview)


def place_point():
    global xV
    global yV
    global Points
    global Plist
    
    code = 0
    x = xV.get()
    y = yV.get()
    try:
        float(x)
    except ValueError:
        messagebox.showinfo("ValueError", "Incorrect point x value!")
        xV.icursor(len(x))
        code = 1
    try:
        float(y)
    except ValueError:
        messagebox.showinfo("ValueError", "Incorrect point y value!")
        yV.icursor(len(y))
        code = 1
    if code == 0:
        if [float(x),float(y)] in Points:
            messagebox.showinfo("ValueError", "This point exists already!")
            return
        PList.insert(END,str(x)+';'+str(y))
        Points.append([float(x), float(y)])


def delete_point():
    global Points
    global PList
    cur = PList.curselection()
    if len(cur) == 0:
        PList.delete(len(Points)-1)
        Points = Points[:-1]
    else:
        cur = list(cur)
        cur.sort()
        cur.reverse()
        for i in cur:
            PList.delete(i)
            Points.pop(i)


def load_from_file(f):
    global Points
    global PList
    try:
        lines = [line for line in f]
        for i in lines:
            cur = i.split()
            try:
                tmp = list(map(float,cur))
                if tmp in Points:
                    continue
                Points.append(tmp)
                PList.insert(END,cur[0]+';'+cur[1])
            except:
                messagebox.showinfo("InputError",
                                "Incorrect file!")
                break
    except:
        messagebox.showinfo("InputError",
                            "Incorrect file!")

def LoadFile(): 
    fn = askopenfilename()
    return fn


def load_points(filename="input.txt"):
    try:
        with open(LoadFile(),"r") as f:
            load_from_file(f)
    except FileNotFoundError:
        messagebox.showinfo("FileNotFoundError",
                            "Unable to find an input file!")

        
def find_min_max(arr):
    r1_x = arr[0][0]
    r2_x = arr[0][0]
    r1_y = arr[0][1]
    r2_y = arr[0][1]
    for i in arr:
        r1_x = max(r1_x,i[0])
        r2_x = min(r2_x,i[0])
        r1_y = max(r1_y,i[1])
        r2_y = min(r2_y,i[1])
    return min(r2_x,r2_y),max(r1_x,r1_y)


def draw_point(Canv,x1,y1,t1='',color="red"):
    Canv.create_oval([x1-3,y1+3],[x1+3,y1-3],fill=color)
    Canv.create_text(x1,y1,text=t1,
          font="Verdana 12",anchor="n",justify=LEFT)


def draw_line(x1,y1,x2,y2,f1,f2,t1,t2):
    global Canv

    w = Canv.winfo_width()*0.8
    h = Canv.winfo_height()*0.8
    d = min(w,h)
    
    x1 = (x1+0.12)*d
    x2 = (x2+0.12)*d
    y1 = Canv.winfo_height() - (y1+0.1)*d
    y2 = Canv.winfo_height() - (y2+0.1)*d

    Canv.create_line(x1,y1,x2,y2)

    if f1:
        draw_point(Canv,x1,y1,t1,"red")
    if f2:
        draw_point(Canv,x2,y2,t2,"red")


def normalize(arr, minv1, maxv1):
    for i in range(len(arr)):
        arr[i][0] -= minv1
        arr[i][1] -= minv1
    
    for i in range(len(arr)):
        arr[i][0] /= (maxv1 - minv1)
        arr[i][1] /= (maxv1 - minv1)

    return arr


def draw(event=None):
    global Points
        
    if len(Points) < 3 and len(Points) != 0:
         messagebox.showinfo("Warning!",
                            "Слишком мало точек!")
         return
    
    points = [i.copy() for i in Points]
    
    res, p = make_count(points)
    if Canv.winfo_height() < top.winfo_height():
        Canv.config(height = top.winfo_height())
    if Canv.winfo_width() < top.winfo_width():
        Canv.config(width = top.winfo_width())
    
    h = Canv.winfo_height()
    w = Canv.winfo_width()

    Canv.delete('all')
    
    if res == [] and len(Points) > 2:
        messagebox.showinfo("Warning!",
                            "Все точки лежат на одной прямой!")
    if res == []:
        return
    
    minv1, maxv1 = find_min_max(res[:3])

    t_res = ['({:.3g};{:.3g})'.format(i[0],i[1]) for i in res]
    t_p = ['({:.3g};{:.3g})'.format(i[0],i[1]) for i in p]
    
    Answer.config(text = 'Ответ:\n'+t_res[0]+' '+t_res[1]+' '+t_res[2])
    
    norm_res = normalize(res, minv1, maxv1)
    norm_p = normalize(p, minv1, maxv1)

    # Drawing lines
    draw_line(norm_res[0][0],norm_res[0][1],
              norm_res[1][0],norm_res[1][1],
              0,1,'',t_res[1])
    draw_line(norm_res[1][0],norm_res[1][1],
              norm_res[2][0],norm_res[2][1],
              0,1,'',t_res[2])
    draw_line(norm_res[2][0],norm_res[2][1],
              norm_res[0][0],norm_res[0][1],
              0,1,'',t_res[0])
  
    draw_line(norm_res[2][0],norm_res[2][1],
              norm_res[5][0],norm_res[5][1],
              0,1,'',t_res[5])
    draw_line(norm_res[0][0],norm_res[0][1],
              norm_res[3][0],norm_res[3][1],
              0,1,'',t_res[3])
    draw_line(norm_res[1][0],norm_res[1][1],
              norm_res[4][0],norm_res[4][1],
              0,1,'',t_res[4])

    # Drawing dots
    draw_line(norm_res[6][0],norm_res[6][1],
              norm_res[6][0],norm_res[6][1],
              0,1,'',t_res[6])
    for i in range(len(norm_p)):
        draw_line(norm_p[i][0],norm_p[i][1],
                  norm_p[i][0],norm_p[i][1],
                  0,1,'',t_p[i])
        

AddPointButton = Button(Buttons, text = "Add point",
                        command = place_point, width = 18)
DeletePointButton = Button(Buttons, text = "Delete point",
                           command = delete_point, width = 18)
DrawButton = Button(Buttons, text = "Draw",
                    command = draw, width = 18)
LoadButton = Button(Buttons, text = "Load",
                    command = load_points, width = 18)

Cords.grid(row = 1, column = 0)
AddPointButton.grid(row = 2, column = 0)
DeletePointButton.grid(row = 2, column = 1)
DrawButton.grid(row = 1, column = 1)
LoadButton.grid(row = 3, column = 0)

PList.pack(side = RIGHT, fill = Y)
Canv.pack()
Buttons.pack(side = TOP, fill = X)

# Drawing while scaling
top.bind('<Button-1>',draw)
top.bind('<Configure>',draw)

top.mainloop()
root.mainloop()
