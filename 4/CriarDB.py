import sqlite3

class Criar_banco(object):
    def __init__(self):
        # criando e conectando...
        self.conn = sqlite3.connect('alunos.db')
        # definindo um cursor
        self.cursor = self.conn.cursor()

        self.cursor.execute("""
        CREATE TABLE aluno (
 	        id_aluno INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
 	        dre TEXT NOT NULL, 
 	        curso TEXT NOT NULL,
 	        nome TEXT NOT NULL,
 	        genero TEXT NOT NULL,
 	        data_nascimento TEXT NOT NULL,
 	        altura REAL NOT NULL,
 	        peso REAL NOT NULL,
            cra REAL,
 	        creditos_obtidos TEXT NOT NULL,
            renda REAL
            );
            """)
        print("tabela aluno criada com sucesso!!")

        self.conn.commit()
        print('Banco criado com sucesso!')
        # desconectando
        self.conn.close()




