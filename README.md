# ChibiOS HAL Board Support Layer

This repository contains a board support layer built on top of the [ChibiOS HAL](http://www.chibios.org/).

## Getting ChibiOS

Because ChibiOS is hosted as an SVN repository, it cannot be included as a git submodule. (There is a GitHub mirror, but it does not correctly pull in all of the SVN externals and so cannot be used).

To pull ChibiOS into this project, run the `get_chibios.sh` script located at the root of this directory. This script will download and extract the archive file for the targeted version of ChibiOS into `lib/chibios`.

Before running `get_chibios.sh`, you'll need to make sure you have 7zip installed (`sudo apt install p7zip-full`).