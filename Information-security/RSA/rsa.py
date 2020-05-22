import crypto
import sys
sys.modules['Crypto'] = crypto
from Crypto.Util import number
from random import randrange


class RSA(object):
    def __init__(self, p=None, q=None, bits=8):
        if not p:
            p = number.getPrime(bits)
        if not q:
            q = number.getPrime(bits)
        self.p = p if number.isPrime(p) else exit(-1)
        self.q = q if number.isPrime(q) else exit(-1)
        self.n = p * q # Вычисляется их произведение n=p*q, которое называется модулем.
        self.phi = (p - 1) * (q - 1) # Вычисляется значение функции Эйлера от числа n: 
        self.e = self.get_e(self.phi, bits) # Выбирается целое число, взаимно простое со значением функции phi(n)
        self.d = self.get_d(self.e, self.phi) # Вычисляется число d, мультипликативно обратное к числу e по модулю phi(n)
        # Пара (e,n) публикуется в качестве открытого ключа RSA (англ. RSA public key).
        # Пара (d,n) играет роль закрытого ключа RSA (англ. RSA private key) и держится в секрете.
    def crypt(self, char, key):
        #if char == splitter:
        #    return splitter
        '''
        С = M**e mod N
        M’ = C**d mod N
        '''
        return char**key % self.n

    def encrypt_string(self, string):
        res = ""
        for char in string:
            ch = self.crypt(ord(char), self.d)
            #print("Char->char: ", char, ch)
            res += chr(ch)
            #print(char, type(char))
        return res

    def decrypt_string(self, string):
        res = ""
        for char in string:
            ch = self.crypt(ord(char), self.e)
            #print("char->dchar: ", ord(char), ch)
            res += chr(ch)
        return res

    @staticmethod
    def get_d(e, phi):
        return number.inverse(e, phi) # e**-1 mod phi
        #return e**-1 % phi
        
#a*x+b*y=gcd(a,b) x=d, gcd = e, phi - некая k
#if a==0 -> x=0,y=1 -> return b
#int x1 y1
#int d = gcd(b%a,a,x1,y1)
#x=y-(b/a)*x
#y=x1
#return d

    @staticmethod
    def get_e(phi, bits=192):
        # (e*d) mod fi == 1
        while True:
            result = randrange(2,255)
            modulus = number.GCD(result, phi)
            if modulus == 1:
                return result

    @staticmethod
    def get_greatest_common_divisor(a, b):
        while b != 0:
            a, b = b, a % b
        return a
