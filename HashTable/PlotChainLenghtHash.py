import matplotlib.pyplot as plt
import numpy as np

# Values

N=64;

# Read Files
in_file = open("Exp1.txt", "rb") 
Data = in_file.read()
in_file.close()

# Transform the data stream
string = Data.replace(',', ' ')

#X = np.fromstring(string, dtype=np.unit16) 

# X = X.astype(np.float64)
#print string
X = string.split()

results = [int(i) for i in X]

results = np.mat(results)

results = results.reshape(N,2)

bins = results[:,0]

values = results[:,1]

width = 1.0/1.5

plt.bar(bins,values,width, color="blue");

plt.grid()

plt.show()

