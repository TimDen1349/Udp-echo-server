FROM ubuntu:22.04
RUN apt-get update && apt-get install -y g++ && rm -rf /var/lib/apt/lists/*
WORKDIR /app
COPY client.cpp .
RUN g++ -std=c++11 -o client client.cpp
CMD ["./client"]