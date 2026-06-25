FROM ubuntu:22.04
RUN apt-get update && apt-get install -y \
    g++ \
    netcat-openbsd \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /app
COPY server.cpp .
RUN g++ -std=c++11 -o server server.cpp
RUN adduser --disabled-password --gecos '' appuser && chown -R appuser:appuser /app
USER appuser
EXPOSE 12345/udp
HEALTHCHECK --interval=30s --timeout=5s --start-period=10s --retries=3 \
  CMD nc -u -z localhost 12345 || exit 1
CMD ["./server"]