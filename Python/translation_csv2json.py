import shutil
import json
import pandas as pd

shutil.copy2('languages.json', 'old_languages.json')
languages_json = pd.read_json('old_languages.json')
languages_csv = pd.read_csv('languages.csv')
languages_csv = languages_csv.set_index('Unnamed: 0').transpose()
translations = languages_csv.transpose().to_dict(orient='dict')

for langs in translations:
    print(langs)
    languages_json[langs]['translates'] = translations[langs]
    for k, v in languages_json[langs]['translates'].items():
        if not isinstance(v, str):
            print(f'lang = {langs}: key = {k} | value = {v} (type = {type(v)})')
            # print(type(v))  
            languages_json[langs]['translates'][k] = 'NEED TO BE TRANSLATED'
    for v in languages_json[langs]['translates'].values():
        assert(isinstance(v, str))
with open('languages.json', 'w', encoding='utf-8') as file:
    json.dump(languages_json.to_dict(), file, indent=2, ensure_ascii=False)