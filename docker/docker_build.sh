#! /usr/bin/env bash

DIR=$(cd $(dirname $0); pwd)

DOCKERFILE=${DIR}/notes.dockerfile

docker build -f ${DOCKERFILE} -t notes-docker:v1.0 ${DIR}
