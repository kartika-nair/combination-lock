import http.client
import urllib
import time
#import serial
import pandas as pd

#Assign ThingSpeak read API key to a variable
apiKey = '7JXFPMTKO9CQPDFF'
df = pd.read_csv('dataset.csv')

def readSensors(i): #Read sensor data
    passwd_list = [str(x) for x in df.iloc[i, :]]
    passwd = ''
    for s in passwd_list:
        passwd += s
    return passwd

def uploadReadings(i): #ThingSpeak upload
    passwd = readSensors(i)
    if passwd == '125346':
        print('Access granted')
        params = urllib.parse.urlencode({'field1': 1,'key':apiKey})
    else:
        print('Access denied')
        params = urllib.parse.urlencode({'field1': 0,'key':apiKey})
    headers = {"Content-type": "application/x-www-form-urlencoded","Accept": "text/plain"}
    conn = http.client.HTTPConnection("api.thingspeak.com:80")

    try:
        print("Attempting to contact ThingSpeak")
        conn.request("POST", "/update", params, headers)
        response = conn.getresponse()
        print ("Upload status: ", response.status, response.reason)
        conn.close()

    except:
        print("Connection failed")

i = 0
while True:
    uploadReadings(i)
    i+=1
    time.sleep(15)
    if i == 50:
        break