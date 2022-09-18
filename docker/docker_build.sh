#! /usr/bin/env bash

DIR=$(cd $(dirname $0); pwd)

echo ${DIR}

DOCKERFILE=${DIR}/notes.dockerfile

docker build -f ${DOCKERFILE} -t notes-docker:v1.0 ${DIR}
