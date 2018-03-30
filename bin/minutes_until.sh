#!/bin/bash
echo $(( ($(date -d "$1" +%s) - $(date +%s) )/60 ))
