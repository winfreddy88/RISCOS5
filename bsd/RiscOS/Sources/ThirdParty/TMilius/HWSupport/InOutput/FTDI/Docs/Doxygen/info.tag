<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>
<tagfile>
  <compound kind="page">
    <name>index</name>
    <title></title>
    <filename>index</filename>
  </compound>
  <compound kind="file">
    <name>callback.c</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>callback_8c</filename>
    <includes id="ftdimodhead_8h" name="ftdimodhead.h" local="yes">ftdimodhead.h</includes>
    <includes id="callback_8h" name="callback.h" local="yes">callback.h</includes>
    <class kind="struct">callback_request_list_structure</class>
    <class kind="struct">callback_request_structure</class>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>perform_risc_os_buffer_operation</name>
      <anchor>a1</anchor>
      <arglist>(_kernel_swi_regs *regs, struct risc_os_buffer_info_structure *risc_os_buffer_info)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>callback_teof</name>
      <anchor>a2</anchor>
      <arglist>(struct risc_os_ftdi_structure *risc_os_ftdi, int *external_transfer_result)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>get_buffer_info</name>
      <anchor>a3</anchor>
      <arglist>(int buffer_handle, struct risc_os_buffer_info_structure *risc_os_buffer_info)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>callback_generate</name>
      <anchor>a4</anchor>
      <arglist>(struct risc_os_ftdi_structure *risc_os_ftdi, int io_info, void *pw)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>callback_handler</name>
      <anchor>a5</anchor>
      <arglist>(_kernel_swi_regs *regs_ignore, void *pw)</arglist>
    </member>
    <member kind="variable">
      <type>callback_request_list_structure</type>
      <name>callback_requests</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>callback.h</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>callback_8h</filename>
    <includes id="ftdimodule_8h" name="ftdimodule.h" local="yes">ftdimodule.h</includes>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>get_buffer_info</name>
      <anchor>a0</anchor>
      <arglist>(int buffer_handle, struct risc_os_buffer_info_structure *risc_os_buffer_info)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>callback_generate</name>
      <anchor>a1</anchor>
      <arglist>(struct risc_os_ftdi_structure *risc_os_ftdi, int io_info, void *pw)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>command.c</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>command_8c</filename>
    <includes id="ftdimodhead_8h" name="ftdimodhead.h" local="yes">ftdimodhead.h</includes>
    <includes id="ftdimodule_8h" name="ftdimodule.h" local="yes">ftdimodule.h</includes>
    <class kind="struct">claim_callback_structure</class>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_MAX_CLAIM_CALLBACK_NO</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>determine_vendor_product_id</name>
      <anchor>a4</anchor>
      <arglist>(unsigned int usb_device_number, unsigned int *idVendor, unsigned int *idProduct)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>command_callback_handler</name>
      <anchor>a5</anchor>
      <arglist>(_kernel_swi_regs *regs_ignore, void *pw)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>ftdi_cmd</name>
      <anchor>a6</anchor>
      <arglist>(const char *arg_string, int argc, int cmd_no, void *pw)</arglist>
    </member>
    <member kind="variable">
      <type>@0</type>
      <name>command_claim_callbacks</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>actual_number_of_pending_claims</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>claim_callback_structure</type>
      <name>claim_data</name>
      <anchor>o1</anchor>
      <arglist>[FTDI_MAX_CLAIM_CALLBACK_NO]</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>configuration.c</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>configuration_8c</filename>
    <includes id="configuration_8h" name="configuration.h" local="yes">configuration.h</includes>
    <includes id="ftdi_8h" name="ftdi.h" local="yes">ftdi.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>MAX_CONFIG_FILE_LINE_SIZE</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>get_file_line</name>
      <anchor>a1</anchor>
      <arglist>(FILE *config_file)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>determine_parameter_value_number</name>
      <anchor>a2</anchor>
      <arglist>(char **value)</arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>determine_config_parameter</name>
      <anchor>a3</anchor>
      <arglist>(char **file_line, int *port_number)</arglist>
    </member>
    <member kind="function">
      <type>unsigned long</type>
      <name>get_data_bits_permission</name>
      <anchor>a4</anchor>
      <arglist>(unsigned long parity_type)</arglist>
    </member>
    <member kind="function">
      <type>unsigned long</type>
      <name>get_parity_permission</name>
      <anchor>a5</anchor>
      <arglist>(unsigned long parity_type)</arglist>
    </member>
    <member kind="function">
      <type>unsigned long</type>
      <name>get_stopbits_permission</name>
      <anchor>a6</anchor>
      <arglist>(unsigned long stopbits)</arglist>
    </member>
    <member kind="function">
      <type>unsigned long</type>
      <name>get_flowcontrol_permission</name>
      <anchor>a7</anchor>
      <arglist>(unsigned long flowcontrol_type)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>configuration.h</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>configuration_8h</filename>
    <member kind="function">
      <type>char *</type>
      <name>get_file_line</name>
      <anchor>a0</anchor>
      <arglist>(FILE *config_file)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>determine_parameter_value_number</name>
      <anchor>a1</anchor>
      <arglist>(char **value)</arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>determine_config_parameter</name>
      <anchor>a2</anchor>
      <arglist>(char **file_line, int *port_number)</arglist>
    </member>
    <member kind="function">
      <type>unsigned long</type>
      <name>get_data_bits_permission</name>
      <anchor>a3</anchor>
      <arglist>(unsigned long parity_type)</arglist>
    </member>
    <member kind="function">
      <type>unsigned long</type>
      <name>get_parity_permission</name>
      <anchor>a4</anchor>
      <arglist>(unsigned long parity_type)</arglist>
    </member>
    <member kind="function">
      <type>unsigned long</type>
      <name>get_stopbits_permission</name>
      <anchor>a5</anchor>
      <arglist>(unsigned long stopbits)</arglist>
    </member>
    <member kind="function">
      <type>unsigned long</type>
      <name>get_flowcontrol_permission</name>
      <anchor>a6</anchor>
      <arglist>(unsigned long flowcontrol_type)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>debug.c</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>debug_8c</filename>
    <includes id="debug_8h" name="debug.h" local="yes">debug.h</includes>
    <includes id="ftdimodhead_8h" name="ftdimodhead.h" local="yes">ftdimodhead.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>DEBUG_DATA_SIZE</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>debug_initialize</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>debug_finalize</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>debug_write</name>
      <anchor>a9</anchor>
      <arglist>(unsigned int debug_level, char *info)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>debug_writef</name>
      <anchor>a10</anchor>
      <arglist>(unsigned int debug_level, char *info,...)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>debug_set_level</name>
      <anchor>a11</anchor>
      <arglist>(unsigned int debug_level)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>debug_print</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable">
      <type>@1</type>
      <name>debug_info</name>
      <anchor>a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>level</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>start</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>position</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>size</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char *</type>
      <name>debug_data</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>debug.h</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>debug_8h</filename>
    <member kind="define">
      <type>#define</type>
      <name>DEBUG_LEVEL_NO_DEBUG</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DEBUG_LEVEL_INITIALIZATION</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DEBUG_LEVEL_CONFIGURATION</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DEBUG_LEVEL_REGISTRATION</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DEBUG_LEVEL_STREAM</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DEBUG_LEVEL_TRANSMISSION</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>debug_initialize</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>debug_finalize</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>debug_write</name>
      <anchor>a8</anchor>
      <arglist>(unsigned int debug_level, char *info)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>debug_writef</name>
      <anchor>a9</anchor>
      <arglist>(unsigned int debug_level, char *info,...)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>debug_set_level</name>
      <anchor>a10</anchor>
      <arglist>(unsigned int debug_level)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>debug_print</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>driver.c</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>driver_8c</filename>
    <includes id="error_8h" name="error.h" local="yes">error.h</includes>
    <includes id="serial_8h" name="serial.h" local="yes">serial.h</includes>
    <includes id="callback_8h" name="callback.h" local="yes">callback.h</includes>
    <includes id="driver_8h" name="driver.h" local="yes">driver.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>DeviceFSCallDevice_MonitorTX</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DeviceFSCallDevice_MonitorRX</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>perform_ioctl</name>
      <anchor>a2</anchor>
      <arglist>(struct ftdi_device_structure *ftdi_device, int *ioctl_block)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>driver_internal</name>
      <anchor>a3</anchor>
      <arglist>(struct common_structure *common, _kernel_swi_regs *regs, void *pw)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>driver.h</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>driver_8h</filename>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CALLDEVICE_RESET</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CALLDEVICE_FLOW_CHARS</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CALLDEVICE_MODEM_STATUS</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CALLDEVICE_EVENT_CHAR</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CALLDEVICE_ERROR_CHAR</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CALLDEVICE_LATENCY_TIMER</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CALLDEVICE_BITMODE</name>
      <anchor>a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CALLDEVICE_GET_EEPROM</name>
      <anchor>a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CALLDEVICE_SET_EEPROM</name>
      <anchor>a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CALLDEVICE_EREASE_EEPROM</name>
      <anchor>a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>driver_internal</name>
      <anchor>a10</anchor>
      <arglist>(struct common_structure *common, _kernel_swi_regs *regs, void *pw)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>error.c</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>error_8c</filename>
    <includes id="error_8h" name="error.h" local="yes">error.h</includes>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>initialize_error</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>close_error</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>generate_error</name>
      <anchor>a7</anchor>
      <arglist>(int error_number)</arglist>
    </member>
    <member kind="variable">
      <type>char</type>
      <name>my_space</name>
      <anchor>a0</anchor>
      <arglist>[512]</arglist>
    </member>
    <member kind="variable">
      <type>@2</type>
      <name>message_file</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>void *</type>
      <name>filespace</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>descriptor</name>
      <anchor>o1</anchor>
      <arglist>[5]</arglist>
    </member>
    <member kind="variable">
      <type>char</type>
      <name>file_name</name>
      <anchor>o2</anchor>
      <arglist>[35]</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>error.h</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>error_8h</filename>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_BASE</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_NO_MEMORY</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_NO_CALLBACKS</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_USB_TRANSFER_ABORTED</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_FETCH_PROBLEMS</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_INVALID_BAUDRATE</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_BAUDRATE</name>
      <anchor>a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_INVALID_STOPBITS</name>
      <anchor>a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_INVALID_PARITY</name>
      <anchor>a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_INVALID_DATABITS</name>
      <anchor>a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_DATA</name>
      <anchor>a10</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_INVALID_FLOWCONTROL</name>
      <anchor>a11</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_FLOWCONTROL</name>
      <anchor>a12</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_EVENT_CHAR</name>
      <anchor>a13</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_ERROR_CHAR</name>
      <anchor>a14</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_IOCTL_BLOCK</name>
      <anchor>a15</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_PURGE_BUFFERS</name>
      <anchor>a16</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_READ_PINS</name>
      <anchor>a17</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_SET_PINS</name>
      <anchor>a18</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_IOCTL_INVALID_OP</name>
      <anchor>a19</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_UNSUPPORTED_MODE</name>
      <anchor>a20</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_FTDI_INIT</name>
      <anchor>a21</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_WRITE_CHOICES</name>
      <anchor>a22</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_NO_DEVICE</name>
      <anchor>a23</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_FTDI_RESET</name>
      <anchor>a24</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_READ_MODEM_STATUS</name>
      <anchor>a25</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_GET_LATENCY_TIMER</name>
      <anchor>a26</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_SET_LATENCY_TIMER</name>
      <anchor>a27</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_EEPROM_READ</name>
      <anchor>a28</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_EEPROM_RIGHTS</name>
      <anchor>a29</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_EEPROM_WRITE</name>
      <anchor>a30</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_EEPROM_ERASE</name>
      <anchor>a31</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_DRIVER_WRONG_PARAMS</name>
      <anchor>a32</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_DRIVER_INVALID_COMMAND</name>
      <anchor>a33</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_NO_CLAIM_CALLBACKS</name>
      <anchor>a34</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_ERROR_CLAIM_DOUBLED</name>
      <anchor>a35</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>initialize_error</name>
      <anchor>a36</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>close_error</name>
      <anchor>a37</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>generate_error</name>
      <anchor>a38</anchor>
      <arglist>(int error_number)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ftdi.c</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>ftdi_8c</filename>
    <includes id="ftdi_8h" name="ftdi.h" local="yes">ftdi.h</includes>
    <member kind="function">
      <type>bool</type>
      <name>perform_usb_control_request_to_device</name>
      <anchor>a0</anchor>
      <arglist>(char *device_name, unsigned char bm_request_type, unsigned char brequest, unsigned short wvalue, unsigned short windex, unsigned short wlength, void *buffer)</arglist>
    </member>
    <member kind="function">
      <type>unsigned short</type>
      <name>ftdi_bitbang</name>
      <anchor>a1</anchor>
      <arglist>(ftdi_environment *ftdi)</arglist>
    </member>
    <member kind="function">
      <type>unsigned short</type>
      <name>ftdi_eeprom_size</name>
      <anchor>a2</anchor>
      <arglist>(ftdi_environment *ftdi)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_reset</name>
      <anchor>a3</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_purge_buffer</name>
      <anchor>a4</anchor>
      <arglist>(ftdi_environment *ftdi, int kind_of_buffer, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_purge_buffers</name>
      <anchor>a5</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_set_pins</name>
      <anchor>a6</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char pin, bool set_pin, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_set_flow_control</name>
      <anchor>a7</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char flowcontrol_type, unsigned char xon_char, unsigned char xoff_char, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_set_baudrate</name>
      <anchor>a8</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned long baudrate, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_set_data_property</name>
      <anchor>a9</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char number_bits, unsigned char stopbit_type, unsigned char parity_type, bool tx_on, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_read_modem_status</name>
      <anchor>a10</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char *status_info, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_set_event_char</name>
      <anchor>a11</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char event_char, bool enable_event, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_set_error_char</name>
      <anchor>a12</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char error_char, bool enable_error, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_set_latency_timer</name>
      <anchor>a13</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char timer, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_get_latency_timer</name>
      <anchor>a14</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char *timer_info, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_set_bitmode</name>
      <anchor>a15</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char bit_direction_mask, unsigned char bitmode, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_enable_bitbang</name>
      <anchor>a16</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_enable_io_mode</name>
      <anchor>a17</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_enable_mpsse</name>
      <anchor>a18</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_enable_mcu</name>
      <anchor>a19</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_read_pins</name>
      <anchor>a20</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char *pin_info, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>ftdi_usb_read_eeprom</name>
      <anchor>a21</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char *eeprom_content_base, unsigned short eeprom_content_size, unsigned short eeprom_offset)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_write_eeprom</name>
      <anchor>a22</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char *eeprom_content_base)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_erase_eeprom</name>
      <anchor>a23</anchor>
      <arglist>(ftdi_environment *ftdi)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_init</name>
      <anchor>a24</anchor>
      <arglist>(ftdi_environment *ftdi, int ftdi_chip_type, char *usb_control_reference)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ftdi.h</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>ftdi_8h</filename>
    <class kind="struct">ftdi_environment</class>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CHIP_TYPE_UNKNOWN</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CHIP_TYPE_AM</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CHIP_TYPE_BM</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CHIP_TYPE_2232C</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_PORT_DEFAULT</name>
      <anchor>a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_PORT_SIOA</name>
      <anchor>a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_PORT_SIOB</name>
      <anchor>a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_PORT_PARALLEL</name>
      <anchor>a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_PARITY_NONE</name>
      <anchor>a10</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_PARITY_ODD</name>
      <anchor>a11</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_PARITY_EVEN</name>
      <anchor>a12</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_PARITY_MARK</name>
      <anchor>a13</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_PARITY_SPACE</name>
      <anchor>a14</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_STOPBITS_1</name>
      <anchor>a15</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_STOPBITS_15</name>
      <anchor>a16</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_STOPBITS_2</name>
      <anchor>a17</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_FLOWCONTROL_NONE</name>
      <anchor>a18</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_FLOWCONTROL_RTS_CTS</name>
      <anchor>a19</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_FLOWCONTROL_DTR_DSR</name>
      <anchor>a20</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_FLOWCONTROL_XON_XOFF</name>
      <anchor>a21</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_BUFFER_RX</name>
      <anchor>a22</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_BUFFER_TX</name>
      <anchor>a23</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_PINS_DTR</name>
      <anchor>a24</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_PINS_RTS</name>
      <anchor>a25</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_STATUS_CTS</name>
      <anchor>a26</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_STATUS_DSR</name>
      <anchor>a27</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_STATUS_RI</name>
      <anchor>a28</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_STATUS_RLSD</name>
      <anchor>a29</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_BITMODE_BITBANG_ASYNC</name>
      <anchor>a30</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_BITMODE_MPSSE</name>
      <anchor>a31</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_BITMODE_BITBANG_SYNC</name>
      <anchor>a32</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_BITMODE_MCU_HOST_BUS_EMU</name>
      <anchor>a33</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_BITMODE_FAST_SERIAL</name>
      <anchor>a34</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CONTROL_RESET</name>
      <anchor>a35</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CONTROL_PINS</name>
      <anchor>a36</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CONTROL_FLOW</name>
      <anchor>a37</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CONTROL_BAUDRATE</name>
      <anchor>a38</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CONTROL_DATA</name>
      <anchor>a39</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CONTROL_GET_MODEM_STATUS</name>
      <anchor>a40</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CONTROL_EVENT_CHAR</name>
      <anchor>a41</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CONTROL_ERROR_CHAR</name>
      <anchor>a42</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CONTROL_LATENCY_TIMER</name>
      <anchor>a43</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CONTROL_GET_LATENCY_TIMER</name>
      <anchor>a44</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CONTROL_BITMODE</name>
      <anchor>a45</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CONTROL_GET_PINS</name>
      <anchor>a46</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CONTROL_GET_EEPROM</name>
      <anchor>a47</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CONTROL_EEPROM</name>
      <anchor>a48</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_CONTROL_EREASE_EEPROM</name>
      <anchor>a49</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_MAX_PORTS</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_MAX_BAURATES</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>__packed struct @3</type>
      <name>ftdi_eeprom</name>
      <anchor>a66</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>dummy</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>vendor_id</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>product_id</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>device_realease_no</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>config_descriptor</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>max_power_consumption</name>
      <anchor>o5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>chip_config</name>
      <anchor>o6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>dummy2</name>
      <anchor>o7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned short</type>
      <name>usb_version</name>
      <anchor>o8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>manufacturer_string_offset</name>
      <anchor>o9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>manufacturer_string_size</name>
      <anchor>o10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>product_string_offset</name>
      <anchor>o11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>product_string_size</name>
      <anchor>o12</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>serial_string_offset</name>
      <anchor>o13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>serial_string_size</name>
      <anchor>o14</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>string_data</name>
      <anchor>o15</anchor>
      <arglist>[256]</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_reset</name>
      <anchor>a67</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_purge_buffer</name>
      <anchor>a68</anchor>
      <arglist>(ftdi_environment *ftdi, int kind_of_buffer, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_purge_buffers</name>
      <anchor>a69</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_set_pins</name>
      <anchor>a70</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char pin, bool set_pin, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_set_flow_control</name>
      <anchor>a71</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char flowcontrol_type, unsigned char xon_char, unsigned char xoff_char, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_set_baudrate</name>
      <anchor>a72</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned long baudrate, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_set_data_property</name>
      <anchor>a73</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char number_bits, unsigned char stopbit_type, unsigned char parity_type, bool tx_on, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_read_modem_status</name>
      <anchor>a74</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char *status_info, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_set_event_char</name>
      <anchor>a75</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char event_char, bool enable_event, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_set_error_char</name>
      <anchor>a76</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char error_char, bool enable_error, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_set_latency_timer</name>
      <anchor>a77</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char timer, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_get_latency_timer</name>
      <anchor>a78</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char *timer_info, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_set_bitmode</name>
      <anchor>a79</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char bit_direction_mask, unsigned char bitmode, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_enable_bitbang</name>
      <anchor>a80</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_enable_io_mode</name>
      <anchor>a81</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_enable_mpsse</name>
      <anchor>a82</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_enable_mcu</name>
      <anchor>a83</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_read_pins</name>
      <anchor>a84</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char *pin_info, unsigned char port_number)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>ftdi_usb_read_eeprom</name>
      <anchor>a85</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char *eeprom_content_base, unsigned short eeprom_content_size, unsigned short eeprom_offset)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_write_eeprom</name>
      <anchor>a86</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char *eeprom_content_base)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_usb_erase_eeprom</name>
      <anchor>a87</anchor>
      <arglist>(ftdi_environment *ftdi)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ftdi_init</name>
      <anchor>a88</anchor>
      <arglist>(ftdi_environment *ftdi, int ftdi_chip_type, char *usb_control_reference)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ftdimodhead.h</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>ftdimodhead_8h</filename>
    <member kind="define">
      <type>#define</type>
      <name>CMHG_VERSION</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>Module_Title</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>Module_Help</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>Module_VersionString</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>Module_VersionNumber</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>Module_Date</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>help_PRINT_BUFFER</name>
      <anchor>a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>arg_CONFIGURE_SYNTAX</name>
      <anchor>a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>arg_STATUS</name>
      <anchor>a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>configure_BAD_OPTION</name>
      <anchor>a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>configure_NUMBER_NEEDED</name>
      <anchor>a10</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>configure_TOO_LARGE</name>
      <anchor>a11</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>configure_TOO_MANY_PARAMS</name>
      <anchor>a12</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>CMD_FTDIDriver_Claim</name>
      <anchor>a13</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>CMD_FTDIDriver_DeviceAlias</name>
      <anchor>a14</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>module_init</name>
      <anchor>a15</anchor>
      <arglist>(const char *cmd_tail, int podule_base, void *pw)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>module_final</name>
      <anchor>a16</anchor>
      <arglist>(int fatal, int podule, void *pw)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>module_services</name>
      <anchor>a17</anchor>
      <arglist>(int service_number, _kernel_swi_regs *r, void *pw)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>ftdi_cmd</name>
      <anchor>a18</anchor>
      <arglist>(const char *arg_string, int argc, int cmd_no, void *pw)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>command_callback_handler_entry</name>
      <anchor>a19</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>callback_handler_entry</name>
      <anchor>a20</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>driver_entry</name>
      <anchor>a21</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>command_callback_handler</name>
      <anchor>a22</anchor>
      <arglist>(_kernel_swi_regs *r, void *pw)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>callback_handler</name>
      <anchor>a23</anchor>
      <arglist>(_kernel_swi_regs *r, void *pw)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>driver</name>
      <anchor>a24</anchor>
      <arglist>(_kernel_swi_regs *r, void *pw)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>upcall_handler_entry</name>
      <anchor>a25</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>upcall_handler</name>
      <anchor>a26</anchor>
      <arglist>(_kernel_swi_regs *r, void *pw)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ftdimodule.c</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>ftdimodule_8c</filename>
    <includes id="error_8h" name="error.h" local="yes">error.h</includes>
    <includes id="configuration_8h" name="configuration.h" local="yes">configuration.h</includes>
    <includes id="serial_8h" name="serial.h" local="yes">serial.h</includes>
    <includes id="callback_8h" name="callback.h" local="yes">callback.h</includes>
    <includes id="driver_8h" name="driver.h" local="yes">driver.h</includes>
    <includes id="ftdimodhead_8h" name="ftdimodhead.h" local="yes">ftdimodhead.h</includes>
    <includes id="ftdimodule_8h" name="ftdimodule.h" local="yes">ftdimodule.h</includes>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>deregister_usb_device</name>
      <anchor>a6</anchor>
      <arglist>(struct risc_os_ftdi_structure *risc_os_ftdi)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>deregister_device</name>
      <anchor>a7</anchor>
      <arglist>(struct ftdi_device_structure *ftdi_device)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>register_device_to_fs</name>
      <anchor>a8</anchor>
      <arglist>(struct ftdi_device_structure *ftdi_device)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>register_device</name>
      <anchor>a9</anchor>
      <arglist>(char *device_name, struct risc_os_ftdi_structure *risc_os_ftdi, unsigned long ftdi_port_number)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>register_usb_device</name>
      <anchor>a10</anchor>
      <arglist>(unsigned int usb_device_number, unsigned int idVendor, unsigned int idProduct, char *pendant_extension, char *own_config_extension)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>upcall_handler</name>
      <anchor>a11</anchor>
      <arglist>(_kernel_swi_regs *regs, void *pw)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>driver</name>
      <anchor>a12</anchor>
      <arglist>(_kernel_swi_regs *regs, void *pw)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>module_init</name>
      <anchor>a13</anchor>
      <arglist>(const char *cmd_tail, int podule_base, void *pw)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>module_final</name>
      <anchor>a14</anchor>
      <arglist>(int fatal, int podule, void *pw)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>module_services</name>
      <anchor>a15</anchor>
      <arglist>(int service_number, _kernel_swi_regs *regs, void *pw)</arglist>
    </member>
    <member kind="variable">
      <type>common_structure</type>
      <name>common</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ftdimodule.h</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>ftdimodule_8h</filename>
    <includes id="upcall_8h" name="upcall.h" local="yes">upcall.h</includes>
    <includes id="ftdi_8h" name="ftdi.h" local="yes">ftdi.h</includes>
    <class kind="struct">common_structure</class>
    <class kind="struct">ftdi_device_structure</class>
    <class kind="struct">risc_os_buffer_info_structure</class>
    <class kind="struct">risc_os_ftdi_structure</class>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_NO_FILE_HANDLE</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_NO_DEVICEFS_HANDLE</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_NO_BUFFER_HANDLE</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_MAX_NUMBER_CALLBACK_REQUESTS</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_VALIDATION</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>register_usb_device</name>
      <anchor>a5</anchor>
      <arglist>(unsigned int usb_device_number, unsigned int idVendor, unsigned int idProduct, char *pendant_extension, char *own_config_extension)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>serial.c</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>serial_8c</filename>
    <includes id="error_8h" name="error.h" local="yes">error.h</includes>
    <includes id="configuration_8h" name="configuration.h" local="yes">configuration.h</includes>
    <includes id="serial_8h" name="serial.h" local="yes">serial.h</includes>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>set_baudrate</name>
      <anchor>a0</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned long baudrate, unsigned long port_number)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>set_data_format</name>
      <anchor>a1</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned long data_bits, unsigned long stopbit_type, unsigned long parity_type, unsigned long port_number)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>set_flowcontrol</name>
      <anchor>a2</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned long flowcontrol_type, unsigned long port_number)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>set_event_char</name>
      <anchor>a3</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char event_char, unsigned long port_number)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>set_error_char</name>
      <anchor>a4</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char error_char, unsigned long port_number)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>serial.h</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>serial_8h</filename>
    <includes id="ftdi_8h" name="ftdi.h" local="yes">ftdi.h</includes>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>set_baudrate</name>
      <anchor>a0</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned long baudrate, unsigned long port_number)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>set_data_format</name>
      <anchor>a1</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned long data_bits, unsigned long stopbit_type, unsigned long parity_type, unsigned long port_number)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>set_flowcontrol</name>
      <anchor>a2</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned long flowcontrol_type, unsigned long port_number)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>set_event_char</name>
      <anchor>a3</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char event_char, unsigned long port_number)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>set_error_char</name>
      <anchor>a4</anchor>
      <arglist>(ftdi_environment *ftdi, unsigned char error_char, unsigned long port_number)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>upcall.c</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>upcall_8c</filename>
    <includes id="upcall_8h" name="upcall.h" local="yes">upcall.h</includes>
    <member kind="function">
      <type>int</type>
      <name>upcall_compare_buffer_handle</name>
      <anchor>a0</anchor>
      <arglist>(struct upcall_translation_element_structure *translation_element1, struct upcall_translation_element_structure *translation_element2)</arglist>
    </member>
    <member kind="function">
      <type>upcall_translation_element_structure *</type>
      <name>upcall_find_translation</name>
      <anchor>a1</anchor>
      <arglist>(struct upcall_translation_structure *translation, unsigned int buffer_handle)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>upcall_translation_remove</name>
      <anchor>a2</anchor>
      <arglist>(struct upcall_translation_structure *translation, unsigned int buffer_handle)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>upcall_translation_add</name>
      <anchor>a3</anchor>
      <arglist>(struct upcall_translation_structure *translation, unsigned int buffer_handle, int io_info, struct risc_os_ftdi_structure *risc_os_ftdi)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>upcall_translation_initialize</name>
      <anchor>a4</anchor>
      <arglist>(struct upcall_translation_structure *translation)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>upcall_translation_release</name>
      <anchor>a5</anchor>
      <arglist>(struct upcall_translation_structure *translation)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>upcall.h</name>
    <path>/LanMan98::ROOL/$/Development/TungstenDev/RiscOS/Sources/ThirdParty/TMilius/HWSupport/InOutput/FTDI/</path>
    <filename>upcall_8h</filename>
    <includes id="error_8h" name="error.h" local="yes">error.h</includes>
    <class kind="struct">upcall_translation_element_structure</class>
    <class kind="struct">upcall_translation_structure</class>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_UPCALL_IO_I_DFS</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_UPCALL_IO_I</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_UPCALL_IO_O</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FTDI_UPCALL_TRANSLATION_ELEMENTS_TO_EXPAND</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>upcall_compare_buffer_handle</name>
      <anchor>a4</anchor>
      <arglist>(struct upcall_translation_element_structure *compare_element, struct upcall_translation_element_structure *translation_element)</arglist>
    </member>
    <member kind="function">
      <type>upcall_translation_element_structure *</type>
      <name>upcall_find_translation</name>
      <anchor>a5</anchor>
      <arglist>(struct upcall_translation_structure *translation, unsigned int buffer_handle)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>upcall_translation_remove</name>
      <anchor>a6</anchor>
      <arglist>(struct upcall_translation_structure *translation, unsigned int buffer_handle)</arglist>
    </member>
    <member kind="function">
      <type>_kernel_oserror *</type>
      <name>upcall_translation_add</name>
      <anchor>a7</anchor>
      <arglist>(struct upcall_translation_structure *translation, unsigned int buffer_handle, int io_info, struct risc_os_ftdi_structure *risc_os_ftdi)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>upcall_translation_initialize</name>
      <anchor>a8</anchor>
      <arglist>(struct upcall_translation_structure *translation)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>upcall_translation_release</name>
      <anchor>a9</anchor>
      <arglist>(struct upcall_translation_structure *translation)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>callback_request_list_structure</name>
    <filename>structcallback__request__list__structure.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>no_of_requests</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>callback_request_structure</type>
      <name>request</name>
      <anchor>o1</anchor>
      <arglist>[FTDI_MAX_NUMBER_CALLBACK_REQUESTS]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>callback_request_structure</name>
    <filename>structcallback__request__structure.html</filename>
    <member kind="variable">
      <type>risc_os_ftdi_structure *</type>
      <name>risc_os_ftdi</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>io_info</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>claim_callback_structure</name>
    <filename>structclaim__callback__structure.html</filename>
    <member kind="variable">
      <type>char</type>
      <name>pendant_extension</name>
      <anchor>o0</anchor>
      <arglist>[40]</arglist>
    </member>
    <member kind="variable">
      <type>char</type>
      <name>own_config_extension</name>
      <anchor>o1</anchor>
      <arglist>[40]</arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>usb_device_number</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>idVendor</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>idProduct</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>common_structure</name>
    <filename>structcommon__structure.html</filename>
    <member kind="variable">
      <type>void *</type>
      <name>ws</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ftdi_device_structure *</type>
      <name>first_device</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>upcall_translation_structure</type>
      <name>upcall_translation</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>ftdi_device_structure</name>
    <filename>structftdi__device__structure.html</filename>
    <member kind="variable">
      <type>ftdi_device_structure *</type>
      <name>previous_device</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ftdi_device_structure *</type>
      <name>next_device</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>risc_os_ftdi_structure *</type>
      <name>risc_os_ftdi</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>ftdi_port_number</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char</type>
      <name>device_name</name>
      <anchor>o4</anchor>
      <arglist>[20]</arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>device_driver_handle</name>
      <anchor>o5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ftdi_device_structure::@8</type>
      <name>input</name>
      <anchor>o11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>bool</type>
      <name>stream_valid</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>file_handle</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>devicefs_stream_handle</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>risc_os_buffer_info_structure</type>
      <name>risc_os_buffer_info</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>bytes_requested</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ftdi_device_structure::@9</type>
      <name>output</name>
      <anchor>o13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>bool</type>
      <name>stream_valid</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>file_handle</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>devicefs_stream_handle</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>risc_os_buffer_info_structure</type>
      <name>risc_os_buffer_info</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ftdi_device_structure::@10</type>
      <name>device_list</name>
      <anchor>o16</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>devicefs_device</type>
      <name>device</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>void *</type>
      <name>list_terminator</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>ftdi_environment</name>
    <filename>structftdi__environment.html</filename>
    <member kind="variable">
      <type>char *</type>
      <name>usb_control_reference</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>chip_type</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>number_of_ports</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>configuration_port</name>
      <anchor>o3</anchor>
      <arglist>[FTDI_MAX_PORTS]</arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>actual_bitmode</name>
      <anchor>o4</anchor>
      <arglist>[FTDI_MAX_PORTS]</arglist>
    </member>
    <member kind="variable">
      <type>ftdi_environment::@4</type>
      <name>allowed_configurations</name>
      <anchor>o15</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ftdi_environment::@4::@5</type>
      <name>serial</name>
      <anchor>o0</anchor>
      <arglist>[FTDI_MAX_PORTS]</arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>number_of_baudrates</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>baudrate</name>
      <anchor>o1</anchor>
      <arglist>[FTDI_MAX_BAURATES]</arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>data_bits</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>stopbits</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>parity</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>flowcontrol</name>
      <anchor>o5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>flow_xon_char</name>
      <anchor>o6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>flow_xoff_char</name>
      <anchor>o7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>bool</type>
      <name>eeprom_writeable</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>risc_os_buffer_info_structure</name>
    <filename>structrisc__os__buffer__info__structure.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>handle</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>id</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>void *</type>
      <name>routine</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>void *</type>
      <name>ws</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>risc_os_ftdi_structure</name>
    <filename>structrisc__os__ftdi__structure.html</filename>
    <member kind="variable">
      <type>ftdi_environment</type>
      <name>ftdi</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char</type>
      <name>device_name</name>
      <anchor>o1</anchor>
      <arglist>[20]</arglist>
    </member>
    <member kind="variable">
      <type>ftdi_device_structure *</type>
      <name>devices</name>
      <anchor>o2</anchor>
      <arglist>[FTDI_MAX_PORTS]</arglist>
    </member>
    <member kind="variable">
      <type>risc_os_ftdi_structure::@6</type>
      <name>input</name>
      <anchor>o14</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>file_handle</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>risc_os_buffer_info_structure</type>
      <name>risc_os_buffer_info</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>bool</type>
      <name>callback_requested</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>devicefs_stream_handle</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>usb_stream_handle</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>devdriver_handle</name>
      <anchor>o5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>usb_buffer_size</name>
      <anchor>o6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>buffer</name>
      <anchor>o7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>bytes_buffered</name>
      <anchor>o8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>bytes_processed</name>
      <anchor>o9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>bytes_requested</name>
      <anchor>o10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>risc_os_ftdi_structure::@7</type>
      <name>output</name>
      <anchor>o17</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>file_handle</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>risc_os_buffer_info_structure</type>
      <name>risc_os_buffer_info</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>bool</type>
      <name>callback_requested</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>devicefs_stream_handle</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>usb_buffer_size</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char *</type>
      <name>buffer</name>
      <anchor>o5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>bytes_buffered</name>
      <anchor>o6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>bytes_processed</name>
      <anchor>o7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>upcall_translation_element_structure</name>
    <filename>structupcall__translation__element__structure.html</filename>
    <member kind="variable">
      <type>unsigned int</type>
      <name>buffer_handle</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>risc_os_ftdi_structure *</type>
      <name>risc_os_ftdi</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>io_info</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>upcall_translation_structure</name>
    <filename>structupcall__translation__structure.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>no_of_elements</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>max_no_of_elements</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>upcall_translation_element_structure *</type>
      <name>element</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
  </compound>
</tagfile>
