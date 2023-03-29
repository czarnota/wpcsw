#!/usr/bin/env bash

read -rd '' doc <<'EOF'
catcom - simple cat based script acting as a "terminal"

USAGE

    catcom TTY      Connect to a TTY device

OPTIONS

    -h, --help      Show help

EXAMPLES

Connect to /dev/ttyACM0

    $ catcom /dev/ttyACM0

EOF

old_settings=""
tty=""
child=""

cleanup () {
    stty "$old_settings" < "$tty"
    if [[ -n $child ]]; then
        kill $child
    fi
    echo
    echo catcom: original settings restored
}

main () {
    tty="$1"; shift || { help; return 1; }

    old_settings="$(stty -g < "$tty")"

    trap cleanup EXIT

    stty raw -echo "$@" < "$tty"

    cat "$tty" &
    child=$?
    cat > "$tty"
}

help () {
    echo "$doc"
    echo
}

declare -A COMMANDS=(
    [main]=main
    [--help]=help
    [-h]=help
)

argparse () {
    "${COMMANDS["${1:-main}"]:-${COMMANDS[main]}}" "$@"
}
argparse "$@"

