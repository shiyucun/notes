#! /usr/bin/env bash

DOCKER_EXEC=$(which docker)
if [[ $? && -z "${DOCKER_EXEC}" ]]; then
  echo "docker not found"
  exit 1
fi

IMAGES=$(docker images)
if [[ $? ]]; then
  if [[ ! "${IMAGES}" =~ "notes-docker" ]]; then
    echo "no notes-docker image found"
    exit 1
  fi
fi

DOCKER_PS=$(docker ps)
if [[ $? ]]; then
  if [[ "${DOCKER_PS}" =~ "notes-docker" ]]; then
    docker stop notes-docker
  fi
fi

DOCKER_PS=$(docker ps -a)
if [[ $? ]]; then
  if [[ "${DOCKER_PS}" =~ "notes-docker" ]]; then
    docker rm notes-docker
  fi
fi

SCRIPTS_DIR=$(cd $(dirname $0); pwd)

docker run -it -d \
  -v "${SCRIPTS_DIR}/..:/notes" \
  --hostname="$(whoami)-notes" \
  --name notes-docker \
  notes-docker:v1.0
