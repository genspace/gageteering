import serial

ser = serial.Serial('/dev/ttyUSB0', 9600)
lines = []
while 1: 
    if(ser.in_waiting > 0):
        line = ser.readline().decode("utf-8")
        try:
            lines.append(float(line.strip()))
        except:
            pass
        print(line)
        if len(lines) > 4:
            break
            
print(lines[0])
