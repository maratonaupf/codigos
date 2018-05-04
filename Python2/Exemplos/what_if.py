# -*- coding: utf-8 -*-

ano = int(raw_input("Digite um ano: "))

print "%d eh um ano bissexto?" % ano
if ano % 4 == 0 and ano % 100 != 0:
	print "Sim!"
elif ano % 400 == 0:
	print "Sim!"
else:
	print "Nao."

# Operador ternário: if e else numa linha só
print "Sim" if ano % 4 == 0 and ano % 100 != 0 or ano % 400 == 0 else "Nao"
