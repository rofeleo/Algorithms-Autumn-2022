from matplotlib import pyplot as plt

f = open('output.txt', 'r')

x_mouse = []
y_mouse = []
x_cat = []
y_cat = []
all = []

for line in f:
  all.append(line)

f.close()

for i in range(len(all) - 1):
  s = all[i][:-1].split(' ')
  x_mouse.append(float(s[0]))
  y_mouse.append(float(s[1]))
  x_cat.append(float(s[2]))
  y_cat.append(float(s[3]))

# fig = plt.figure()
fig, ax = plt.subplots()

fig.suptitle(all[-1], fontsize=14, fontweight='bold')

figure, axes = plt.subplots() 
cc = plt.Circle((x_cat[-1], y_cat[-1]), 1, fill=False) 
 
axes.set_aspect( 1 ) 
axes.add_artist( cc ) 

plt.plot(x_mouse, y_mouse, x_cat, y_cat, [0], [0], marker='o')



plt.savefig('foo.png')
