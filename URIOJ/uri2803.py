# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2803 - Estados do Norte

northStates = [
    'acre', 'amapa', 'amazonas', 'para', 'rondonia', 'roraima', 'tocantins'
]

def main():
    state = input()
    print('Regiao Norte' if state in northStates else 'Outra regiao')
    
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
