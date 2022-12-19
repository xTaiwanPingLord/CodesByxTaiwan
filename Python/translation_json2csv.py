import os
import shutil
import pandas as pd

language_file = pd.read_json('languages.json')
translations = {}
translations_dataframe = pd.DataFrame({})
for langs in language_file:
    translations[langs] = language_file[langs]["translates"]
    translations_dataframe = pd.concat([
        translations_dataframe,
        pd.json_normalize(language_file[langs]["translates"]).rename(index={0: langs}).transpose()],
        axis=1)

translations_dataframe = translations_dataframe.sort_index()
if os.path.exists('languages.csv'):
    shutil.copy2('languages.csv', 'old_languages.csv')
translations_dataframe.to_csv("languages.csv")