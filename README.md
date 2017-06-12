# atbcli

This is a small hobby project that aims to create a CLI program to access real time bus data in Trondheim, Norway.
It is in EXTREMELY early stages, and not really useful for anyone yet. Maybe one day it will be!
It's basically just a test / proof of concept so far.

So far it can look up the coming departures at a bus stop specified by a node ID.
You must provide the node ID as a command line argument.

example:

atbcli 16010005

## Thanks
atbcli probably wouldn't exist if not for this work by mpolden:
https://github.com/mpolden/atbapi

This API exports the XML data from the AtB public API to sane JSON.
libjson is then responsible for parsing the JSON data.

## Compilation
It should work to clone the repository and type 'make' in the top directory of the repository.

## Dependencies
* curl
* libcurlpp
* jsoncpp

## Future goals/ideas
* Get all publicly available data through the XML/SOAP API provided by AtB (atbapi by mpolden seems to export a limited subset?)
* Store that data in a structured and logical way
* Make it flexible and easy to use for everyone
* Nice UI (ascii/text based probably)
* Rewrite in python? Other language?
