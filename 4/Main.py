from GerenteDB import  Bd_manage
from CriarDB import Criar_banco

#Para criar um banco de dados novo, descomente a seguinte linha
#Criar_banco()
#E no aquivo GerenteDB.py na linha 26 troque o banco a ser utilizado alunos(backup).db para alunos.db
#Se quiser, pode ja preencher o banco para realizar consultas, descomente a seguir
#gerente.preencher_banco()

gerente = Bd_manage()

    #Cadastrar aluno
#gerente.criar_aluno(155,"Engenharia", "Augusto", "male", "16/05/1989", "1.85", "85", "5.8", "100", "group A")


#-------------------------Consultas--------------------------------
#quantos alunos são mulheres
print("Quantidade de alunos do sexo feminino: ",gerente.consulta_mulheres())
#Média CRA do alunos de engenharia
print("Média CRA dos alunos de engenharia: ",gerente.consulta_cra_engenharia())
#Desvio padrão do CRA dos alunos 
print("Desvio padrão do CRA de todos alunos: ",gerente.consulta_cra_desvio_padrao())
#desvio padrão

#Há também a possibilidade de realizar consultas direto por SQL
print(gerente.consulta_direta("SELECT * FROM aluno WHERE nome = 'Ítalo Palhares'"))
#CUIDADO: Não há tratamento para sql injection