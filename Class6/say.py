# 报错
import pyttsx3

engine = pyttsx3.init()
name = input("请问你叫什么名字？")
engine.say(f"你好，{name}")
engine.runAndWait()

