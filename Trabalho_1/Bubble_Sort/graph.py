# André Vargas VIllalba Codorniz - 14558436
# Lucas Augusto Moreira Barros - 14590610

import csv
import matplotlib.pyplot as plt



# Caminho do arquivo CSV
caminho_arquivo = './result.csv'

# Inicializar os vetores
n, sort0, sort1, sort2 = [], [], [], []

# Abrir o arquivo CSV e ler suas linhas
with open(caminho_arquivo, newline='') as csvfile:
    leitor_csv = csv.reader(csvfile)
    for linha in leitor_csv:
        # Extrair os valores das quatro colunas
        valor_n = linha[0]
        valor_sort0 = linha[1]
        valor_sort1 = linha[2]
        valor_sort2 = linha[3]

        # Adicionar os valores aos vetores correspondentes
        n.append(valor_n)
        sort0.append(valor_sort0)
        sort1.append(valor_sort1)
        sort2.append(valor_sort2)

# Exibição dos vetores
# print('Coluna 1:', n)
# print('Coluna 2:', sort0)
# print('Coluna 3:', sort1)
# print('Coluna 4:', sort2)

sort0cres    = []
sort0decres  = []
sort0rand    = []
sort0randrep = []

sort1cres    = []
sort1decres  = []
sort1rand    = []
sort1randrep = []

sort2cres    = []
sort2decres  = []
sort2rand    = []
sort2randrep = []

tamanhos = [100, 500, 1000, 5000, 10000]

for i in range(0,len(n), 4):
    
        sort0cres.append(sort0[i])
        sort0decres.append(sort0[i+1])
        sort0rand.append(sort0[i+2])
        sort0randrep.append(sort0[i+3])
        
        sort1cres.append(sort1[i])
        sort1decres.append(sort1[i+1])
        sort1rand.append(sort1[i+2])
        sort1randrep.append(sort1[i+3])
        
        sort2cres.append(sort2[i])
        sort2decres.append(sort2[i+1])
        sort2rand.append(sort2[i+2])
        sort2randrep.append(sort2[i+3])


print(sort0rand)
print(sort1rand)
print(sort2rand)

# Criar uma grade de subplots (2 linhas, 2 colunas)
fig, axs = plt.subplots(2, 2)
        
# Plotagem das retas
axs[0, 0].plot(tamanhos, sort0cres, label='Sort 0')
axs[0, 0].plot(tamanhos, sort1cres, label='Sort 1')
axs[0, 0].plot(tamanhos, sort2cres, label='Sort 2')

# Configurações do gráfico
axs[0, 0].set_title('Crescente')
axs[0, 0].legend()

# Plotagem das retas
axs[0, 1].plot(tamanhos, sort0decres, label='Sort 0')
axs[0, 1].plot(tamanhos, sort1decres, label='Sort 1')
axs[0, 1].plot(tamanhos, sort2decres, label='Sort 2')

# Configurações do gráfico
axs[0, 1].set_title('Decrescente')
axs[0, 1].legend()

# Plotagem das retas
axs[1, 0].plot(tamanhos, sort0rand, label='Sort 0')
axs[1, 0].plot(tamanhos, sort1rand, label='Sort 1')
axs[1, 0].plot(tamanhos, sort2cres, label='Sort 2')

# Configurações do gráfico
axs[1, 0].set_title('Aleatório')
axs[1, 0].legend()

# Plotagem das retas
axs[1, 1].plot(tamanhos, sort0randrep, label='Sort 0')
axs[1, 1].plot(tamanhos, sort1randrep, label='Sort 1')
axs[1, 1].plot(tamanhos, sort2randrep, label='Sort 2')

# Configurações do gráfico
axs[1, 1].set_title('Aleatório Com Repetição')
axs[1, 1].legend()

# Exibição do gráfico
plt.show()