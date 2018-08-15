#!/bin/sh
set -x
cd ~abf/src/dymo-labelmanager
./txt2img -f ~abf/.fonts/AlteHaasGroteskBold.ttf "$1"
sudo ./imgprint txt2img.png
