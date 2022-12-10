from matplotlib import pyplot as plt



f = open('output.txt', 'r')

x_mouse = []
y_mouse = []
x_cat = []
y_cat = []
all = []

for line in f:
  all.append(line[:-1].split(' '))

for i in range(len(all)):
	for j in range(4):
		all[i][j] = float(all[i][j])

for i in range(len(all)):
  x_mouse.append(all[i][0])
  y_mouse.append(all[i][1])
  x_cat.append(all[i][2])
  y_cat.append(all[i][3])

plt.plot(x_mouse, y_mouse, x_cat, y_cat, marker='o')

plt.savefig('foo.png')