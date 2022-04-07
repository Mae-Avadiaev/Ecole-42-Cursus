import psycopg2
import pandas as pd
import names
import uuid
conn = psycopg2.connect(dbname='data', user='data', 
                        password='data', host='localhost')
cursor = conn.cursor()
d = {'card_number': [], 'card_holder': [], 'card_type' : [], 'cardvalidto' : [], 'card_pin' : [], 'status_tx' : [], 'amount_money' : [], 'currency_name' : [], 'country_tx' : [], 'internaltxnumber' : []}
df = pd.DataFrame(data=d)
currs = pd.read_html('https://en.wikipedia.org/wiki/List_of_circulating_currencies')
cntrs = pd.read_html('https://en.wikipedia.org/wiki/List_of_ISO_3166_country_codes')
CURRENCIES = currs[0][['State or territory[1]', 'ISO code[2]']]
COUNTRIES = cntrs[0].drop([1])[[['ISO 3166[1]', 'Country name[5]'], ['ISO 3166-1[2]', 'Alpha-3 code[5]']]]
COUNTRIES.columns = COUNTRIES.columns.droplevel()
CURRENCIES = CURRENCIES.rename(columns={'State or territory[1]' : 'Country name'})
COUNTRIES = COUNTRIES.rename(columns = {'Country name[5]': 'Country name'})
RES = COUNTRIES.join(CURRENCIES.set_index('Country name'), on=('Country name')).dropna()
import time
import datetime
from datetime import datetime as dt
CARDTYPE = ('Visa', 'Maestro', 'MIR')
TRANSTATUS = ('DONE', 'PROCESSING', 'CANCELLED')
def fours():
    return(str(random.randint(0,9))+str(random.randint(0,9))+str(random.randint(0,9))+str(random.randint(0,9)))
def bank_num():
    return(fours() + ' ' + fours() + ' ' + fours() + ' ' + fours())
def pin():
    return (str(random.randint(0,9))+str(random.randint(0,9))+str(random.randint(0,9)))
def random_date():
    random.seed()
    d = random.randint(1, int(time.time()))
    return dt.fromtimestamp(d).strftime('%Y-%m-%d')
import random
for i in range(3000000):
    samp = RES.sample()
    card_num = bank_num()
    last_digits = int(card_num[-4:])
    #print("table_name is tx_{}".format(last_digits%30 + 1))
    #print((bank_num(), names.get_last_name()[:10], random.choice(CARDTYPE), random_date(), pin(), random.choice(TRANSTATUS), random.randint(0,9999999), samp['ISO code[2]'].iloc[0] ,samp['Alpha-3 code[5]'].iloc[0]))
    cursor.execute("INSERT INTO tx_{} VALUES (%s,%s,%s,%s,%s,%s,%s,%s,%s,uuid_generate_v4());\n".format(last_digits%30 + 1),(card_num, names.get_last_name()[:10], random.choice(CARDTYPE), random_date(), pin(), random.choice(TRANSTATUS), random.randint(0,9999999), samp['ISO code[2]'].iloc[0][:3] ,samp['Alpha-3 code[5]'].iloc[0][:3]))
    conn.commit()