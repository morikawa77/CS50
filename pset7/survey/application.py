import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


@app.route("/form", methods=["POST"])
def post_form():
    # Backend form validation 
    if not request.form.get("heroName") or not request.form.get("realName") or not request.form.get("heroTeam") or not request.form.get("mainVillain") or not request.form.get("race"):
        return render_template("error.html", message="You need to fill all fields of the form.")
    # Opens csv file and append a line
    with open("survey.csv", "a") as file:
        writer = csv.DictWriter(file, fieldnames=["heroName", "realName", "heroTeam", "mainVillain", "race"])
        writer.writerow({"heroName": request.form.get("heroName"), "realName": request.form.get("realName"), "heroTeam": request.form.get(
            "heroTeam"), "mainVillain": request.form.get("mainVillain"), "race": request.form.get("race")})
        # Redirect route to /sheet
        return redirect("/sheet")


@app.route("/sheet")
def get_sheet():
    # opens csv file to read 
    with open("survey.csv", "r") as file:
        reader = csv.DictReader(file)
        # create a list with csv data
        heroes = list(reader)
    return render_template("sheet.html", heroes=heroes)
