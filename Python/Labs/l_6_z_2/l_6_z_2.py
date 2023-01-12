from lz2_for import l2_z2_for
from lz2_while import l2_z2_while
n = int(input("n = "))
x = int(input('x = '))

print('Ряд посчитанный через for: ' + str(l2_z2_for(n, x)))
print('Ряд посчитанный через while: ' + str(l2_z2_while(n, x)))
