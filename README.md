# Remind

A command-line utility for creating quick reminders in Linux via `systemd-run` and `notify-send'.

## Requirements
- The 'g++` compiler
- Initialization system `systemd' (installed by default in Arch Linux)
- `libnotify' (for notification output)

## Assembly and installation

1. Clone the repository:
``bash
git clone https://github.com/AnderFan/remind.git
cd remind

## Using

remind 2026-07-14 12:00:00 "Lunch"

// or in Russian format:

remind 07.14.2026 12:00:00 "Heading" "Reminder text"

// This is how the abbreviated format is supported.

remind 07.14 12:00 "Hi" "I`m remider!"

// and

remind 14-07 09:42 "Iso_shor" "I`m so short!"
