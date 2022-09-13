from selenium import webdriver
from time import sleep

chromeDriverPath = r"chromedriver.exe"
site = webdriver.ChromeOptions()
browser = webdriver.Chrome(executable_path=chromeDriverPath) 

browser.get('https://popcat.click')
sleep(2)

while 1:
    browser.find_element_by_xpath('//*[@id="app"]/img').click() 
    browser.find_element_by_xpath('//*[@id="app"]/img').click()
    sleep(0.04)