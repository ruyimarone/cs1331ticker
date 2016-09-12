import os, csv
from datetime import datetime
os.chdir(os.path.expanduser('~/cs1331ticker/ticker/'))
now = datetime.today()
#now = datetime(2016, 9, 12, 12, 0) 
onduty = ""
with open('officeHours.csv') as csvfile:
    reader = csv.reader(csvfile, delimiter=',')

    for row in reader:
        #print(row)
        if ":" in row[0] and int(row[0].split(":")[0]) == now.hour:
            if int(row[0].split(":")[1]) <= now.minute:
                if 0 <= now.weekday() <= 4:
                    onduty = row[now.weekday() + 1]

os.system('./makeduty.sh ' + onduty)

