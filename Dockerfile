FROM        debian:buster

LABEL       authors="tnoulens"

RUN	        apt update && \
            apt upgrade -y && \
            apt install -y curl \
            fish \
            make \
            usermode \
            gcc \
            gcc-multilib \
            valgrind \
            dsniff \
            net-tools \
            tcpdump \
            inetutils-ping && \
            mkdir ping && \
            chmod 777 ping

WORKDIR     /ping/

COPY        . .

RUN        make
