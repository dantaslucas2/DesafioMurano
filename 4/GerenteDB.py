import sqlite3
import pandas as pd
import math

class Bd_manage(object):

    def __init__(self):
        print("Iniciou o contrutor")
        self.ccon = None
        self.cursor = None
        print("rodou tudo!!")

    #prenche o banco com dados do arquivo .csv
    def preencher_banco(self):
        dados = pd.read_csv('./dados.csv')
        dados.head()

        print(type(dados))

        for i,row in dados.iterrows():
            self.criar_aluno(row['DRE'], row['Curso'], row['nome'], row['Genero'], row['Data de nascimento'], row['Altura'], row['Peso'], row['CRA'], row['Credito'], row['Renda'])
        print("Dados persistidos")


    def conectar_banco(self):
        # criando e conectando...
        self.conn = sqlite3.connect('alunos(backup).db')
        # definindo um cursor
        self.cursor = self.conn.cursor()

    def desconectar(self):
        self.conn.commit()
        print('Dados gravados com sucesso!')
        # desconectando
        self.conn.close()

#------------ Inserir dados ------------
    def criar_aluno(self, dre, curso, nome, genero, data_nascimento, altura, peso, cra, creditos, renda):

        self.conectar_banco()
        self.cursor.execute("""
        INSERT INTO aluno (dre, curso, nome, genero, data_nascimento, altura, peso, cra, creditos_obtidos, renda)
        VALUES (?,?,?,?,?,?,?,?,?,?)
        """,(dre, curso, nome, genero, data_nascimento, altura, peso, cra, creditos, renda))
        print("aluno criado com sucesso!!")
        self.desconectar()

#------------ Buscar ultima inserção ------------
    def ultimo_aluno(self):
        self.conectar_banco()
        self.cursor.execute("""
        SELECT MAX(id_aluno) FROM aluno;
        """)
        flexa = self.cursor.fetchall()
        self.desconectar()
        return flexa[0][0]

#------------ Imprimir dados ------------
    def mostrar_alunos(self):
        self.conectar_banco()
        self.cursor.execute("""
        SELECT * FROM aluno;
        """)
        flexa = self.cursor.fetchall()
        self.desconectar()
        return flexa

#------------ Pesquisar aluno por dre ------------******
    def pesquisar_aluno_dre(self, dre):
        self.conectar_banco()
        self.cursor.execute("""
        SELECT * FROM aluno WHERE dre=?;
        """,(dre, ))
        flexa = self.cursor.fetchall()
        self.desconectar()
        return flexa

#------------ Deletar aluno ------------******
    #Por DRE
    def deletar_aluno(self,dre):
        self.conectar_banco()
        self.cursor.execute("""
        DELETE FROM aluno
        WHERE dre = ?
        """, (dre,))
        self.desconectar()
        print("Aluno Exluido ")

#------------ Alterar dados ------------*********
    def alterar_aluno(self, dre, curso, nome, genero, data_nascimento, altura, peso, cra, creditos, id_aluno):
        self.conectar_banco()
        self.cursor.execute("""
        UPDATE aluno
        SET dre = ?, curso = ? , nome = ?, genero = ?, data_nascimento = ?, altura = ?, peso = ?, cra = ?, creditos = ?
        WHERE id_aluno = ?
        """, (dre, curso, nome, genero, data_nascimento, altura, peso, cra, creditos, id_aluno))
        print("Dados do aluno alterado")
        self.desconectar()

#------------ Consultas ------------*********
    def consulta_mulheres(self):
            self.conectar_banco()
            self.cursor.execute("""
            SELECT COUNT(*) FROM aluno WHERE genero='female';
            """,)
            flexa = self.cursor.fetchall()
            self.desconectar()
            return flexa

    def consulta_cra_engenharia(self):
            self.conectar_banco()
            self.cursor.execute("""
            SELECT AVG (CRA) FROM aluno WHERE curso='Engenharia';
            """,)
            flexa = self.cursor.fetchall()
            self.desconectar()
            return flexa

    # SQLite não possui STDDEV - para calcular desvio padrão
    def consulta_cra_desvio_padrao(self):
            self.conectar_banco()
            self.cursor.execute("""
            SELECT AVG(CRA*CRA) - AVG(CRA)*AVG(CRA) FROM aluno;
            """,)
            flexa = self.cursor.fetchall()
            self.desconectar()

            return math.sqrt(flexa[0][0])

    #------------ Consulta direta ------------*********
    def consulta_direta(self, sql):
            self.conectar_banco()
            self.cursor.execute(sql)
            flexa = self.cursor.fetchall()
            self.desconectar()
            return flexa
