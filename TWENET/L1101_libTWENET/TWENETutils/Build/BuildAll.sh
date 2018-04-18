#!/bin/sh

  make TWE_CHIP_MODEL=JN5164 TOCONET_DEBUG=0 clean
  make TWE_CHIP_MODEL=JN5164 TOCONET_DEBUG=0 -j 4 all
  [ ! $? = 0 ] && exit 2
  make TWE_CHIP_MODEL=JN5148 TOCONET_DEBUG=0 clean
  make TWE_CHIP_MODEL=JN5148 TOCONET_DEBUG=0 -j 4 all
  [ ! $? = 0 ] && exit 2
  cd ../..

