from flask import Flask, jsonify, request, render_template

app = Flask(__name__)

relay_state = "OFF"

@app.route("/")
def home():
    return render_template("index.html")

# ESP32 will call this
@app.route("/relay", methods=["GET"])
def relay():
    return relay_state

# Browser will call this
@app.route("/control", methods=["POST"])
def control():
    global relay_state

    data = request.get_json()

    relay_state = data["state"]

    print("Relay:", relay_state)

    return jsonify({"msg": "updated"})

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000, debug=True)
