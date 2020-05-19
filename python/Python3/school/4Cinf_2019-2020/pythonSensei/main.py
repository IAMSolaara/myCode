import sys as sistema
import os

from requests import *

import requests

"""
array = []
x = 'roberto'
if (x == 'cauli' or x =='ciao'):
    print('giusto')
else:
    print('sbagliato')
String[] cose = new String[10]

for (String el : cose) {

}

cose = ['ciao', 'test', 'testsetest']
for el in cose:
    print(el)

for el in cose:
    el = el * 2
    print(el)

cose21 = range(3, 12, 2)
for el in cose21:
    print(el)

for x in range(3, 5, 12):
    print(x)

done = 3
while (done < 12):
    print(done)
    done += 1

def potenza(x=2, esp=1):
    return x ** esp

print(potenza(12, esp=12))

richiesta = get('https://mentalabs.eu/schoolSchedule/api/?day=Monday')
print(richiesta.json())

coso = {
    'test' : 'testttsetet',
    2 : 'ldksfjghldhfglksdjfgh',
    'ciao' : [1,2,3,4],
    'level1' : {
        'level2': 'scendo'
    }
}

print(coso[2])

array = ['test', 'ciao', 'test']
print(array)

if ('test' in array):
    array.remove('test')

print(array)

"""
class testamento():
    def __init__(self, x=2):
        self.__x = x
        print(self.__x)
    def muoro(self):
        self.__mangle()
        print('sono muorot')
    def getX(self):
        return self.__x
    def __mangle(self):
        self.__x = 135174634909859870928740589
    def tupleTest(self):
        return (self.__x)
    def __str__(self):
        return str(self.__x)

class testamentoDiMorte(testamento):
    def __init__(self):
        super().__init__('brutte cose')
    
    def test(self):
        return super().getX()
    

testino = testamento('ciao')
print(testino.getX())

testino.muoro()
print(testino.getX())

print('ciao {}'.format(15))
print(f'ciao {testino.getX()}')
print("%s e' %x volte burdo" % ("ricco", 7896590894095678))
print('%.2f' % 3454345.13531)

for (r,d,f) in os.walk('.'):
    for x in f:
        if ('a' in f):
            print('a trovata in %s' % f)
"""
tuple = (1,2,3,54)
for x in tuple:
    print(x)

for x in 'testsets':
    print(x)

for x in 12:
    print(x)
for x in range(5):
    print(x)

"""

tdm = testamentoDiMorte()
print(tdm)

#print(tdm.test())

print (3 == 3)