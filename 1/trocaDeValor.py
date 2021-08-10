# ---------------- Utilizando operadores aritmeticos ------------------
print("Utilizando operadores aritmeticos multiplicação e divisão")

a = 3
b = 5

a = a * b 
b = a / b 
a = a / b

print("a : ",a)
print("b : ",b)

print("Utilizando operadores aritmeticos adição e subtração")

a = 3
b = 5

a = b + a 
b = a - b 
a = a - b 

print("a : ",a)
print("b : ",b)


# ---------------- Utilizando classe e objeto ------------------
print("Utilizando classe e objeto")

class Container:

    def __init__(self,a,b):
        self.a = a
        self.b = b
    
    def get_a(self):
        return self.a

    def get_b(self):
        return self.b
    
a = 3
b = 5

c = Container(a,b)

a = c.get_b()
b = c.get_a()

print("a : ",a)
print("b : ",b)

# ---------------- Utilizando função ------------------
print("Utilizando função")

a = 3
b = 5

def troca(a,b):
    return b,a



a,b = troca(a,b)

print("a : ",a)
print("b : ",b)

# ---------------- Utiizando arquivo txt ------------------
print("Utilizando arquivo txt")

a = 3
b = 5

f = open("armazenamento.txt","w")

f.writelines(str(a)+"\n")
f.write(str(b))

f = open("armazenamento.txt","r")

b,a =  f.readlines()

f.close()

print("a : ",a)
print("b : ",b)