# Real Age Check for 18+ and 21+ just read the age return

def openFile():
    goodFile = False
    while goodFile == False:
        fname = input("Enter name of data file: ")
        # Begin exception handling
        try:
            # Try to open the file using the name given
            dataFile = open(fname, 'r')
            # If the name is valid, set Boolean to true to exit loop
            goodFile = True
        except IOError:
            # If the name is not valid - IOError exception is raised
            print("Invalid filename, please try again ... ")
    return dataFile

def importTimeShit () :
	from datetime import datetime, timedelta
	ini_time_for_now = datetime.now()
	ini_time_for_now = str(ini_time_for_now)
	print ("initial_date", str(ini_time_for_now))
	ini_time_for_now = ini_time_for_now.split(' ',len (ini_time_for_now))
	currentDate = ini_time_for_now[0]
	currentDate = currentDate.split('-', len(currentDate))
	currentDate = currentDate[1], currentDate[2], currentDate [0]
	currentDateHMS = ini_time_for_now[1]
	return currentDate, currentDateHMS

# January Febuary March April May June July August September October November December
#  01      02      03    04    05  06   07   08     09        10      11       12

def getAge () :
	Age = input ('Input the age (in years) : ')
	Age = str(Age)
	DOB = input ('Input the Date of Birth (MM-DD-YYYY) : ')
	DOB = str(DOB)
	DOB = DOB.split('-', len(DOB))
	return Age, DOB

def testAge (currentDate, Age, DOB) :
	years = str(int(currentDate [2]) - int(DOB [2]))
	months = str(int(currentDate [0]) - int(DOB [0]))
	days = str(int(currentDate [1]) - int(DOB [1]))
	#print(years, months, days)
	if int(months) < 0 :
		EstiAge = str(int(years) - 1)
	elif (int(months) == 0) and (int(days) < 0) :
		EstiAge = str(int(years) - 1)
	else :
		EstiAge = years
	#print(EstiAge)

	if EstiAge == Age :
		AcuracyDOB = True
	else :
		AcuracyDOB = False
	return AcuracyDOB, EstiAge

def PrintResults (Age, AcuracyDOB, EstiAge) :
	if AcuracyDOB == True :
		print ('Age:',Age , 'verified =', AcuracyDOB)
		if int(Age) >= 21 :
			print ('21+')
		elif int(Age) >= 18 :
			print ('18+')
		elif int(Age) >= 16 :
			print ('16+')
		else :
			print ('Verified Minor')
			print ('Kick em (^w^)')
	elif AcuracyDOB == False :
		print ('verified =', AcuracyDOB)
		print ('real age :', EstiAge)
	return

def core () :
	running = True
	currentDate, currentDateHMS = importTimeShit ()
	Age, DOB = getAge ()
	AcuracyDOB, EstiAge = testAge (currentDate, Age, DOB)
	PrintResults (Age, AcuracyDOB,EstiAge)
	return

core ()

# January Febuary March April May June July August September October November December
#  01      02      03    04    05  06   07   08      09        10      11       12


#FPlnz
#BLst & WLst by usr?
#fle modi?
#Rept Loop?

# file_path = "new_file.txt"
#use milti-error checks
# with open(file_path, 'w') as file:
#     file.write("Hello, this is a new text file created using open() function.")
# print(f"File '{file_path}' created successfully.")