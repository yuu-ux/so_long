FROM ubuntu:22.04

ARG UID=501
ARG DOCKER_USER=user

RUN apt-get update && apt-get install -y \
    make gcc git xorg libxext-dev libbsd-dev \
    && useradd -m -u ${UID} ${DOCKER_USER} \
    && git config --global --add safe.directory /so_long \
    && git config --global --add safe.directory /so_long/lib/libft

USER ${DOCKER_USER}
