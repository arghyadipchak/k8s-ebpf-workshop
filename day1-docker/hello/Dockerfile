FROM ubuntu:latest

# install app dependencies
RUN apt-get update && apt-get install -y python3 python3-pip
RUN pip install flask==3.1.* --break-system-packages

# copy the flask app
COPY hello.py /

# final configuration and running the application with exposed port
ENV FLASK_APP=hello
EXPOSE 8000
CMD ["flask", "run", "--host", "0.0.0.0", "--port", "8000"]
