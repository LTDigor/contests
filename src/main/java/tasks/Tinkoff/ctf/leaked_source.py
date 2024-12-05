import secrets
import subprocess
from flask import Flask, render_template, request

app = Flask(__name__)
app.config['SECRET_KEY'] = secrets.token_urlsafe(16)
FLAG = open("/flag1.txt").read()


@app.route('/', methods=['GET', 'POST'])
def index():
    return render_template("index.html")

@app.route('/flag1', methods=['GET', 'POST'])
def flag1():
    equation = request.args.get("equation", None)
    if equation is not None:
        return f"{eval(equation)}"
    else:
        return render_template("flag1.html")

@app.route('/flag2', methods=['GET', 'POST'])
def flag2():
    equation = request.args.get("equation", None)
    if equation is not None:
        return subprocess.check_output(f"echo 'scale=2;{equation}' | bc", shell=True)
    else:
        return render_template("flag2.html")
