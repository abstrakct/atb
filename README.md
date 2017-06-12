This is a small hobby project that aims to create a CLI program to access real time bus data in Trondheim, Norway.
It is in EXTREMELY early stages, and not really useful for anyone yet. Maybe one day it will be!
It's basically just a test / proof of concept so far.

So far it can look up the coming departures at a bus stop specified by a node ID.
You must provide the node ID as a command line argument.

example:
./atbcli 16010005

atbcli makes heavy use of this work by mpolden:
https://github.com/mpolden/atbapi
Thanks! 

This API exports the XML data from the AtB public API to sane JSON.
libjson is then responsible for parsing the JSON data.
