#!/usr/bin/env bash

diagram () {
    mkdir -p "$(dirname "$1")"
    echo -n generating "$1"...
    svgbob --stroke-width 1 > "$1"
    echo ok
}

main () {
    local file="$1"; shift || return

    local dir=$(cd $(dirname "$file") && pwd)
    local diagram_file=$(basename "$file")

    cd "$dir"

    source "$diagram_file"
}

declare -A COMMANDS=(
    [main]=main
)

argparse () {
    ${COMMANDS[${1-main}]-${COMMANDS[main]}} "$@"
}

argparse "$@"
