FROM gcc:latest

COPY . /CLab

WORKDIR /CLab/

RUN gcc -o main main.c

CMD [“./main]