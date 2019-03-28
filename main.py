import serial
import io

# Connect to serial port
ser = serial.serial_for_url('/dev/ttyACM0', 115200, timeout=1)

# if it's not on, open it
if not ser.isOpen():
	ser.open()

# It's alive!!
print("===Connection Start===\n", "Port: " ,ser.name)

# I have no idea what the hell is it, well... it's there
ser.flushInput()
ser.flushOutput()


try:
	while True:
		if not ser.isOpen():
			exit
		data_raw = ser.readline()
		if str(data_raw) != str("b\'\'"):
			data_raw = data_raw.decode('utf-8')
			print("CardByte: ", data_raw)
except:
	print("\n===Connection Closed===")
	ser.close()

