import shutil
import json
import pandas as pd

shutil.copy2('languages.json', 'old_languages.json')
languages_json = pd.read_json('old_languages.json')
languages_csv = pd.read_csv(
    'languages.csv', index_col='Unnamed: 0').transpose()
translations = languages_csv.transpose().to_dict(orient='dict')

for langs in translations:
    print(langs)
    languages_json[langs]['translates'] = translations[langs]

    print(R'Fixing \r\n to \n ---------------------------')
    tmp = dict()
    for k, v in languages_json[langs]['translates'].items():
        tmp[k.replace('\r', '')] = v.replace('\r', '')
    languages_json[langs]['translates'] = tmp
    del tmp

    print(R'Fixing blank value(aka "NaN") ---------------')
    for k, v in languages_json[langs]['translates'].items():
        if not isinstance(v, str):
            print(
                f'lang = {langs}: key = {k} | value = {v} (type = {type(v)})')
            languages_json[langs]['translates'][k] = 'NEED TO BE TRANSLATED'

with open('languages.json', 'w', encoding='utf-8') as file:
    json.dump(languages_json.to_dict(), file, indent=2,
              ensure_ascii=False, allow_nan=False)
