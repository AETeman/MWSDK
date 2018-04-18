#######################################################################################
# CONFIGURATION FILE (SET TWELITE in advance)
######################################################################################

# DEFAULT CHIP SUPPORT LIBRARYR
include ../../../../ChipLib/usever.mk
include ../../../../TWENET/usever.mk

# set chip library version as CFLAGS
_CHIP_LIB1 = $(subst SW, -DMWCHIPLIBCODE=,$(CHIP_LIB))
_CHIP_LIB2 = $(subst V, -DMWCHIPLIBVER=,$(_CHIP_LIB1))
CFLAGS += $(_CHIP_LIB2)

######################################################################################
# Set SDK_BASE_INFORMATION
######################################################################################

### FOR OLDER SDK COMPATIBILITY
ifeq ($(TWE_CHIP_MODEL),JN5164)
  TWELITE=BLUE_TOCONET
else ifeq ($(TWE_CHIP_MODEL),JN5148)
  $(error "ERROR: TWE-Regular,Strong is no more supported.")
endif

### TWE-Lite (RED, JN5169)
ifeq ($(TWELITE),RED)
JENNIC_CHIP		= JN5169
SDK_BASE_DIR   	 	= $(abspath ../../../../ChipLib/$(CHIP_LIB))

CFLAGS += -DEMBEDDED
CFLAGS += -DUSER_VSR_HANDLER

### TWE-Lite (BLUE, JN5164)
else ifeq ($(TWELITE),BLUE)
JENNIC_CHIP		= JN5164
SDK_BASE_DIR   	 	= $(abspath ../../../../ChipLib/$(CHIP_LIB))

CFLAGS += -DEMBEDDED
CFLAGS += -DUSER_VSR_HANDLER

### TWE-Lite (TWELITE, BLUE_TOCONET)
# for older SDK integration
else ifeq ($(TWE_CHIP_MODEL),JN5164)
# BACKWARD SDK COMPATIBILITY
JENNIC_CHIP		= JN5164
SDK_BASE_DIR   	 	= $(abspath ../../../../ChipLib/516x)

CFLAGS += -DEMBEDDED
CFLAGS += -DUSER_VSR_HANDLER

else
$(error "ERROR: No TWE_CHIP_MODEL definition.")
endif


# some other 
DIRUP_LST = $(subst /, ,$(abspath ..))
TARGET_DIR ?= $(word $(words $(DIRUP_LST)), $(DIRUP_LST))

DIRUPUP_LST = $(subst /, ,$(abspath ../..))
PROJNAME ?= $(word $(words $(DIRUPUP_LST)), $(DIRUPUP_LST))
