import os

import redis
from flask import Flask

app = Flask(__name__)

# Get Redis host from environment variable
redis_host = os.getenv("REDIS_HOST", "redis")
redis_port = 6379

r = redis.Redis(host=redis_host, port=redis_port, decode_responses=True)


@app.route("/")
def hello():
    count = r.incr("counter")
    return f"Hello World! This page has been viewed {count} times.\n"


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8000)
