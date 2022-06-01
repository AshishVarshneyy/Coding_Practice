'''
Question: read log file and print vendor and its total connection
Input: 
02:55:06:017,,VENDER-STAT,XO,755
02:55:06:017,,VENDER-STAT,XO,755
02:55:06:017,,VENDER-STAT,AO,755


Output: write in file
VendorName: XO, TotalConnections: 1510
VendorName: AO, TotalConnections: 755
'''

if __name__ == "__main__":
    ana_dic = {}

    #Read log file
    with open("Random_shots\Files\log_file", "r") as stream_data:
        for line in stream_data:
            if line.split(',')[3] in ana_dic.keys():
                ana_dic[line.split(',')[3]] = int(ana_dic[line.split(',')[3]]) + int(line.split(',')[4])
            else:
                ana_dic[line.split(',')[3]] = int(line.split(',')[4])
    #Write out file
    with open("Random_shots\Files\log_file_output", "w") as out_stream:
       for key, value in ana_dic.items(): 
        out_stream.write('VendorName: %s, TotalConnections: %s\n' % (key, value))
