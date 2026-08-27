from flask import Flask, render_templates, request

# request GET 和 POST 都是浏览器发送给服务器的 HTTP request
# get：从服务器获取，查找，搜索某东西  get数据经常出现在url，Flask读取用request.args.get("...")
# post：提交一些数据让服务器处理 post数据出现在表单form中，Flask读取用request.form.get("...")
app = Flask(__name__)

@app.route("/")
def index():

