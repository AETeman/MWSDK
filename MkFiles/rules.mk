##############################################################################
# TOCOS Makefile (rule section)
##############################################################################

##############################################################################
# VERSION
CFLAGS += -DVERSION_MAIN=$(VERSION_MAIN)
CFLAGS += -DVERSION_SUB=$(VERSION_SUB)
CFLAGS += -DVERSION_VAR=$(VERSION_VAR)

##############################################################################
# Configure for the selected chip or chip family
include $(SDK_BASE_DIR)/Chip/Common/Build/config.mk
include $(SDK_BASE_DIR)/Platform/Common/Build/Config.mk
include $(SDK_BASE_DIR)/Stack/Common/Build/Config.mk

##############################################################################
# strip space for some values
space:=
space+=
STRIPPED_TARGET_SUFF=$(subst $(space),,$(TARGET_SUFF))
STRIPPED_OBJDIR_SUFF=$(subst $(space),,$(OBJDIR_SUFF))

##############################################################################
# Target
ifneq ($(SUBNAME),)
  TARGET = $(PROJNAME)_$(SUBNAME)
else
  TARGET = $(PROJNAME)_$(TARGET_DIR)
endif

ifneq ($(APP_TOCONET_BASE),)
TARGET_BIN = $(TARGET)_$(TWELITE)$(STRIPPED_TARGET_SUFF)_$(MONONET_VER)_V$(VERSION_MAIN)-$(VERSION_SUB)-$(VERSION_VAR)
else
TARGET_BIN = $(TARGET)_$(TWELITE)$(STRIPPED_TARGET_SUFF)_$(VERSION_MAIN)-$(VERSION_SUB)-$(VERSION_VAR)
endif

##############################################################################
# Objects

ifeq ($(DEBUG),HW)
OBJDIR   = objs_$(TWELITE)$(STRIPPED_OBJDIR_SUFF)_hdbg
else
OBJDIR   = objs_$(TWELITE)$(STRIPPED_OBJDIR_SUFF)
endif

APPOBJS_BASE = $(APPSRC:.c=.o)
APPOBJS = $(APPSRC:%.c=$(OBJDIR)/%.o)

##############################################################################
# Application include path
ifneq ($(APP_COMMON_SRC_DIR_ADD1),)
INCFLAGS += -I$(APP_COMMON_SRC_DIR_ADD1)
endif
ifneq ($(APP_COMMON_SRC_DIR_ADD2),)
INCFLAGS += -I$(APP_COMMON_SRC_DIR_ADD2)
endif
ifneq ($(APP_COMMON_SRC_DIR_ADD3),)
INCFLAGS += -I$(APP_COMMON_SRC_DIR_ADD3)
endif
ifneq ($(APP_COMMON_SRC_DIR_ADD4),)
INCFLAGS += -I$(APP_COMMON_SRC_DIR_ADD4)
endif
 
##############################################################################
# Application dynamic dependencies
APPDEPS = $(APPOBJS:.o=.d)

#########################################################################
# Linker
LDLIBS := $(addsuffix _$(JENNIC_CHIP_FAMILY),$(APPLIBS)) $(LDLIBS)

#########################################################################
# Main Section

.PHONY: all clean
# Path to directories containing application source 
vpath % $(APP_SRC_DIR):$(APP_COMMON_SRC_DIR):$(ADDITIONAL_SRC_DIR):$(APP_STACK_SRC_DIR_ADD1):$(APP_STACK_SRC_DIR_ADD2):$(APP_COMMON_SRC_DIR_ADD1):$(APP_COMMON_SRC_DIR_ADD2):$(APP_COMMON_SRC_DIR_ADD3):$(APP_COMMON_SRC_DIR_ADD4)

all: objdir $(TARGET_BIN).$(TARGET_TYPE) $(ADDITIONAL_LIBS)

objdir:
	-mkdir -p $(OBJDIR)

-include $(APPDEPS)
%.d:
	rm -f $*.o

$(OBJDIR)/%.o: %.S
	$(info Assembling $< ...)
	$(CC) -c -o $(subst Source,Build,$@) $(CFLAGS) $(INCFLAGS) $< -MD -MF $(OBJDIR)/$*.d -MP
	@echo

$(OBJDIR)/%.o: %.c 
	$(info Compiling $< ...)
	$(CC) -c -o $(subst Source,Build,$@) $(CFLAGS) $(INCFLAGS) $< -MD -MF $(OBJDIR)/$*.d -MP
	@echo

$(OBJDIR)/$(TARGET_BIN).elf: $(APPOBJS) $(addsuffix _$(JENNIC_CHIP_FAMILY).a,$(addprefix $(COMPONENTS_BASE_DIR)/Library/lib,$(APPLIBS))) 
	$(info Linking $@ ...)
	$(CC) -Wl,--gc-sections -Wl,-u_AppColdStart -Wl,-u_AppWarmStart $(LDFLAGS) -T$(LINKCMD) -o $@ \
		 $(APPOBJS) $(ADDITIONAL_OBJS) $(ADDITIONAL_LIBS) \
		 -Wl,--start-group $(addprefix -l,$(LDLIBS))  $(ADDITIONAL_LIBS) -Wl,--end-group \
		 -Wl,-Map,$(OBJDIR)/$(TARGET)_$(TWELITE)$(BIN_SUFFIX).map

$(TARGET_BIN).bin: $(OBJDIR)/$(TARGET_BIN).elf 
	${SIZE} $<
	@echo
	$(info Generating binary ...)
	$(OBJCOPY) -S -O binary $< $@
	
$(TARGET_BIN).a: $(APPOBJS)
	rm -f $(TARGET).a
	$(AR) $(ARFLAGS) $@ $(APPOBJS) $(ADDITIONAL_OBJS)

#########################################################################

clean:
	@rm -rf $(OBJDIR) $(TARGET_BIN)
	
#########################################################################
