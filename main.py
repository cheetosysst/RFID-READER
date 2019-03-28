import serial
import io

# Connect to serial port
ser = serial.serial_for_url('/dev/ttyACM0', 115200, timeout=1) # baud rate set as high as your board supports, the speed is incredibly slow

# if it's not on, open it
if not ser.isOpen():
	ser.open()

# It's alive!!
print("===Connection Start===\n", "Port: " ,ser.name)

# I have no idea what the hell is it, well... it's there. Stack overflow, you know
ser.flushInput()
ser.flushOutput()

# I hate reading unnecesary error message while exiting, that's why here is a "try"
try:
	while True:
		if not ser.isOpen(): # Now I realize it's not essential, remove in future version
			exit
		
		# Get serial message
		data_raw = ser.readline()
		
		# Process raw data
		if str(data_raw) != str("b\'\'"):
			data_raw = data_raw.decode('utf-8')
			print("CardByte: ", data_raw) # print 
except:
	print("\n===Connection Closed===")
	ser.close()

