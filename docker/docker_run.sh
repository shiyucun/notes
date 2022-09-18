#! /usr/bin/env bash

docker stop notes-docker

docker rm notes-docker

docker run -it -d -v /Users/shiyucun/workspace/github_repos/repos/notes:/notes --hostname=$(hostname)-notes --name notes-docker notes-docker:v1.0
