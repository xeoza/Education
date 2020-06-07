class Data:
    x0 = 0
    l = 10           
    R = 0.5          
    Tenv = 300       
    F0 = 100        
    k0 = 0.2         
    kN = 0.5        
    alpha0 = 1e-2   
    alphaN = 9e-3 
    h = 1e-2
    bk = (kN * l) / (kN - k0)
    ak = - k0 * bk
    b_alpha = (alphaN * l) / (alphaN - alpha0)
    a_alpha = - alpha0 * b_alpha
    '''
    l = 10см (Длина стержня)
    R = 0.5см (Радиус стержня)
    Tenv = 300К (Температура окружающей среды)
    F0 = 100 Вт / (см^2 * К) (Плотность теплового потока)
    k0 = 0.1 Вт / (см * К) (Коэффициент теплопроводности в начале стержня)
    kN = 0.2 Вт / (см * К) (Коэффициент теплопроводности в конце стержня)
    α0 = 1e-2 Вт / (см^2 * К) (Коэффициент теплоотдачи в начале стержня)
    αN = 0.9e-2 Вт / (см^2 * К) (Коэффициент теплоотдачи в конце стержня)
    '''

    @staticmethod
    def k(x):
        return Data.ak / (x - Data.bk)

    @staticmethod
    def alpha(x):
        return Data.a_alpha / (x - Data.b_alpha)

    @staticmethod
    def Xn_plus_half(x):
        return (2 * Data.k(x) * Data.k(x + Data.h)) / \
               (Data.k(x) + Data.k(x + Data.h))

    @staticmethod
    def Xn_minus_half(x):
        return (2 * Data.k(x) * Data.k(x - Data.h)) / \
               (Data.k(x) + Data.k(x - Data.h))

    @staticmethod
    def p(x):
        return 2 * Data.alpha(x) / Data.R

    @staticmethod
    def f(x):
        return 2 * Data.alpha(x) / Data.R * Data.Tenv

