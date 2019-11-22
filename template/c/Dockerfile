FROM openfaas/classic-watchdog:0.18.1 as watchdog

FROM alpine:3.10 as builder

# Build handler
RUN apk add --no-cache gcc musl-dev
COPY function function

WORKDIR /function

RUN gcc *.c -static -o handler \
    && chmod +x handler \
    && ./handler

FROM alpine:3.10 as final

# Add non root user
RUN addgroup -S app && adduser -S -g app app
RUN mkdir -p /home/app

WORKDIR /home/app

COPY --from=watchdog /fwatchdog /usr/bin/fwatchdog
COPY --from=builder  /function/handler   .

RUN chown -R app /home/app

USER app

ENV fprocess="./handler"
# Set to true to see request in function logs
ENV write_debug="false"

EXPOSE 8080

HEALTHCHECK --interval=3s CMD [ -e /tmp/.lock ] || exit 1

CMD ["fwatchdog"]
