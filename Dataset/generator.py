import csv
from itertools import permutations

values = permutations([1,2,3,4,5,6])

with open('dataset.csv', 'a') as dataFile:
	writeFile = csv.writer(dataFile, dialect = 'excel')
	for i in list(values):
		writeFile.writerow(i)
