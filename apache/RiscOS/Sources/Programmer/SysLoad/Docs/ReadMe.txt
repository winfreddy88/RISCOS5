
SysLoad Help File
=================

This module monitors system activity by placing a pre- and post-filter onto
all tasks. Using a high resolution timer, it monitors:

 a) how long the Wimp has control, i.e. from a task's call to
    Wimp_Poll(Idle) to the next return into a task from Wimp_Poll(Idle)

 b) how long tasks have control, i.e. between exit from one Wimp_Poll(Idle)
    and the next call

You can also ask it to monitor a specific task or list of tasks by giving
their Wimp task handles. In most contexts, this can be determined by calling:

  uint32_t my_handle;
  _swix(Wimp_ReadSysInfo, _IN(0) | _OUT(0), 5, &my_handle);

The statistics returned can be read from system variables or by calling a SWI
in this module and represent the following:

 1) Percentage of time spent in the Wimp (between task execution)
 2) Percentage of time spent in nominated task(s)
 3) Percentage of time spent in any other task(s)

This module sets the following environment variables:

  SysLoad$Sys  - corresponds to statistic (1)
  SysLoad$Task - corresponds to statistic (2)
  SysLoad$Apps - corresponds to statistic (3)

these can be read from a C program using, for example:

  getenv("SysLoad$Task");

The SysLoad module publishes the following SWI calls:


                                                   SysLoad_ReadInfo (0x586C0)

In:

  R0 = flags (unused)

Out:

  R1 = percentage of time spent in Wimp
  R2 = percentage of time spent in applications
  R3 = percentage of time spent in watched task(s)

Purpose:

This SWI reads the current status of the SysLoad statistics. These will be
updated periodically by the module. The rate at which updates occur can be
specified using the SysLoad_MiscOp SWI call.


                                                    SysLoad_AddTask (0x586C1)

In:

  R0 = flags (unused)
  R1 = task handle of task to add to list

Out:

  None

Purpose:

Add a task to the list of those to watch. Takes no action if the task is
already in the list. Will return an error if the list is full (there is a
fixed limit on the number of tasks to watch - currently 64).


                                                 SysLoad_RemoveTask (0x586C2)

In:

  R0 = flags (unused)
  R1 = task handle of task to remove from list

Out:

  None

Purpose:

Remove a task handle from the list of tasks to watch. If not found, simply
returns without taking any action.


                                                     SysLoad_MiscOp (0x586C3)

In:

  R0 = reason code
  Other registers depend upon reason code in R0

Out:

  Registers depend upon reason code in R0 on entry

Purpose:

Perform miscellaneous SysLoad operations, as specified with the reason code
in R0 on entry.

  Reason code 0: set interval

  In:

    R0 = 0 (set interval)
    R1 = interval period in centiseconds

  Out:

    None

  Purpose:

  This MiscOp is used to change the interval during which SysLoad collects
  statistics before they are placed into environment variables and made
  available to SWI SysLoad_ReadInfo.

  The default interval is one second. The minimum interval is ten
  centiseconds and the maximum interval is one minute.

  If a call to this reason code causes a change to the current interval
  setting for the module, all statistics will be reset and collection will
  be restarted given the new interval period. Out of range values are rounded
  into the valid range.


  Reason code 1: flush task list

  In:

    R0 = 1 (flush task list)

  Out:

    None

  Purpose:

  This MiscOp will remove all tasks from the list of those currently being
  watched. If none are being watched, no further action will be taken. The
  statistics for the current interval may still show some activity for the
  watched tasks (whatever was accumulated up to the point of the flush).
