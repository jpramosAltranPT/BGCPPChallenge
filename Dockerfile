# A basic apache server. To use either add or bind mount content under /var/www
FROM gcc:4.9
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN g++ -o myapp app.cpp
CMD ["./myapp"]
