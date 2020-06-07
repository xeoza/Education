import smtplib
import sys
import os
from email.mime.application import MIMEApplication
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email.mime.text import MIMEText
from email.utils import COMMASPACE, formatdate
from email import encoders



if __name__ == "__main__":
    gmail_user = "smtplab2019@gmail.com"
    gmail_password = "23142314zzz"
    send_from = gmail_user
    print("Input user to mail: ")
    send_to = input()
    
    print("Input filename: ")
    filename = input()

    part = MIMEBase('application', "octet-stream")
    part.set_payload(open(filename, "rb").read())
    encoders.encode_base64(part)
    part.add_header('Content-Disposition', 'attachment; filename="{}"'.format(filename))

    msg = MIMEMultipart()
    msg['From'] = send_from
    msg['To'] = send_to
    msg['Date'] = formatdate(localtime=True)
    print("Input mail subject: ")
    msg['Subject'] = input()
    print("Input mail body: ")
    body = input()
    body = MIMEText(body)
    msg.attach(body)
    msg.attach(part)

    print("Sending email...")
    try:
        server_ssl = smtplib.SMTP_SSL('smtp.gmail.com', 465)
        server_ssl.ehlo()
        server_ssl.login(gmail_user, gmail_password)
        server_ssl.sendmail(send_from, send_to, msg.as_string())
        server_ssl.close()

        print('Email sent.')
    except Exception:
        print("Error!")
