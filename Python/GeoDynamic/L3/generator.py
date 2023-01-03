link_top = 'dat/test4/TOPres.2df'
link_bottom = 'dat/test4/BOTTOMres.2df'
link_res = 'res/res4.grdecl'

top_z = open(link_top, 'r')
bottom_z = open(link_bottom, 'r')
res = open(link_res, 'w')

a = 5
b = 5
step_x = 5.0
step_y = 5.0
origin_x = 5.0
origin_y = 5.0
grid = (a - 1) * (b - 1)
current_x = origin_x
current_y = origin_y + (b * step_y)

for i in range(4):
    top_z.readline()
    bottom_z.readline()


def toFixed(numObj, digits=0):
    return f"{numObj:.{digits}f}"


def getTop_z():
    str = top_z.readline()
    if str == 'NAN\n':
        str = '0.000'
    return float(str)


def getBottom_z():
    str = bottom_z.readline()
    if str == 'NAN\n':
        str = '0.000'
    return float(str)


print('SPECGRID', file=res)
print(str(b - 1) + ' ' + str(a - 1) + ' 1  1 F /\n', file=res)
print('COORD', file=res)

for i in range(a):
    for j in range(b):
        print('    ' + str(toFixed(current_x, 3)) + '    ' +
              str(toFixed(current_y, 3)) + '    ' + str(toFixed(getTop_z(), 3)) + '    ' + str(toFixed(current_x, 3)) + '    ' +
              str(toFixed(current_y, 3)) + '    ' + str(toFixed(getBottom_z(), 3)), file=res)
        current_x += step_x
    current_x = origin_x
    current_y -= step_y

print('    /', file=res)
print('ZCORN', file=res)

top_z.close()
bottom_z.close()
top_z = open(link_top, 'r')
bottom_z = open(link_bottom, 'r')

for i in range(4):
    top_z.readline()
    bottom_z.readline()

for i in range(grid):
    val = toFixed(getTop_z(), 3)
    print('    ' + str(val) + '    ' + str(val) +
          '    ' + str(val) + '    ' + str(val), file=res)

for i in range(grid):
    val = toFixed(getBottom_z(), 3)
    print('    ' + str(val) + '    ' + str(val) +
          '    ' + str(val) + '    ' + str(val), file=res)

print('    /', file=res)
print('ACTNUM', file=res)

tempStr = ''

for i in range(a - 1):
    for j in range(b - 1):
        tempStr += ' 1'
    print(tempStr, file=res)
    tempStr = ''

print('/', file=res)

# TODO add PERMX and PORO

top_z.close()
bottom_z.close()
res.close()
