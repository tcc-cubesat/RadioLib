#!/bin/bash

function handle_interrupt {
    echo "Loop interrupted. Exiting..."
    exit 0
}

trap handle_interrupt SIGINT # SIGINT = Signal Interrupt

while true
  do
  sudo build/rpi-sx1276
  sleep 0.5
done