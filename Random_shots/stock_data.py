import json
from re import S
import requests
import pandas as pd
import smtplib
from email.message import EmailMessage


class Stock:
    def __init__(self):
        self.SENDER_EMAIL = "EMAIL"
        self.APP_PASSWORD = "GENERATE CODE" #https://myaccount.google.com/apppasswords?rapt=AEjHL4OX1l6ne9lsFwOxkY1gn0HPT1nMEw-g6tIkokuExxWRtvOS1Us-fLVOxcYi2cB4y5cDJKLVknSmRFokmTDAnYNlt1RF1A

    def fetch_data(self, url, para=None):
        data = json.loads(requests.get(url, params=para).text)
        return data
        
    def cal_pref(self, start_date, end_date, email_mode):
        niftyList = self.fetch_data("https://api.informedinvestorr.com/assignment/python/niftyList")
        start_stock_price = self.fetch_data("https://api.informedinvestorr.com/assignment/python/dailyPrices", {'selected_date': start_date})
        close_stock_price = self.fetch_data("https://api.informedinvestorr.com/assignment/python/dailyPrices", {'selected_date': end_date})
        
        nifty50_list = [nifty50 for nifty50 in niftyList['fincode_list']]

        nifty50_start_stock_price_list = [stock_data for stock_data in start_stock_price['data_list'] if stock_data['fincode'] in nifty50_list]
        nifty50_close_stock_price_list = [stock_data for stock_data in close_stock_price['data_list'] if stock_data['fincode'] in nifty50_list]

        stock_pref = []
        for i in range(50):
            temp = {}
            temp["fincode"] = nifty50_start_stock_price_list[i]["fincode"] 
            temp["symbol"] = nifty50_start_stock_price_list[i]["symbol"]
            temp["closing_start"] = nifty50_start_stock_price_list[i]["close"]
            temp["closing_end"] = nifty50_close_stock_price_list[i]["close"]
            diff = float(float(nifty50_close_stock_price_list[i]["close"])-float(nifty50_start_stock_price_list[i]["close"]))
            temp["performance"] = round((diff/float(nifty50_start_stock_price_list[i]["close"]))*100, 1)
            stock_pref.append(temp)
        
        if email_mode:
            # dataframe
            df = pd.DataFrame.from_dict(stock_pref)
            # Create a Pandas Excel writer using XlsxWriter as the engine.
            writer = pd.ExcelWriter('stock_pref.xlsx', engine='xlsxwriter')
            # Convert the dataframe to an XlsxWriter Excel object.
            df.to_excel(writer, sheet_name='Sheet1', index=False)
            # Close the Pandas Excel writer and output the Excel file.
            writer.save()
            self.send_mail_with_excel("EMAIL", "stock_pref", "excel attachment", "stock_pref.xlsx")
        else:
            for i in range(50):
                print(stock_pref[i])
    
    def send_mail_with_excel(self, recipient_email, subject, content, excel_file):
        msg = EmailMessage()
        msg['Subject'] = subject
        msg['From'] = self.SENDER_EMAIL
        msg['To'] = recipient_email
        msg.set_content(content)

        with open(excel_file, 'rb') as f:
            file_data = f.read()
        msg.add_attachment(file_data, maintype="application", subtype="xlsx", filename=excel_file)

        with smtplib.SMTP_SSL('smtp.gmail.com', 465) as smtp:
            smtp.login(self.SENDER_EMAIL, self.APP_PASSWORD)
            smtp.send_message(msg)
        


if __name__ == "__main__":
    obj = Stock()
    start_date = '2022-01-01'
    end_date = '2022-01-22'
    email_mode = False
    obj.cal_pref(start_date, end_date, email_mode)    