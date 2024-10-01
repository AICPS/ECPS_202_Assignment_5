#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

// FUNCTION_BLOCK T_PLC_US_BLOCK
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(UDINT,T_PLC_US)

  // FB private variables - TEMP, private and located variables
  __DECLARE_EXTERNAL(INT,PLC_TICKS_PER_SEC)
  __DECLARE_EXTERNAL(DINT,PLC_SYS_TICK_CNT)
  __DECLARE_VAR(BOOL,DEBUG)
  __DECLARE_VAR(INT,N)
  __DECLARE_VAR(UDINT,OFFSET)
  __DECLARE_VAR(DWORD,TEMP)
  __DECLARE_VAR(BOOL,MODE)
  __DECLARE_VAR(UDINT,FAKTOR)
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(UDINT,V_PLC_TICKS_PER_SEC)
  __DECLARE_VAR(UDINT,BASE)

} T_PLC_US_BLOCK;

void T_PLC_US_BLOCK_init__(T_PLC_US_BLOCK *data__, BOOL retain);
// Code part
void T_PLC_US_BLOCK_body__(T_PLC_US_BLOCK *data__);
// FUNCTION_BLOCK T_PLC_MS_BLOCK
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(UDINT,T_PLC_MS)

  // FB private variables - TEMP, private and located variables
  __DECLARE_EXTERNAL(INT,PLC_TICKS_PER_SEC)
  __DECLARE_EXTERNAL(DINT,PLC_SYS_TICK_CNT)
  __DECLARE_VAR(BOOL,DEBUG)
  __DECLARE_VAR(INT,N)
  __DECLARE_VAR(UDINT,OFFSET)
  __DECLARE_VAR(DWORD,TEMP)
  __DECLARE_VAR(BOOL,MODE)
  __DECLARE_VAR(UDINT,FAKTOR)
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(UDINT,V_PLC_TICKS_PER_SEC)
  __DECLARE_VAR(UDINT,BASE)

} T_PLC_MS_BLOCK;

void T_PLC_MS_BLOCK_init__(T_PLC_MS_BLOCK *data__, BOOL retain);
// Code part
void T_PLC_MS_BLOCK_body__(T_PLC_MS_BLOCK *data__);
// FUNCTION_BLOCK INTEGRATE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,E)
  __DECLARE_VAR(REAL,X)
  __DECLARE_VAR(REAL,K)
  __DECLARE_VAR(REAL,Y)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,X_LAST)
  __DECLARE_VAR(BOOL,INIT)
  T_PLC_MS_BLOCK T_PLC_MS;
  __DECLARE_VAR(UDINT,LAST)
  __DECLARE_VAR(UDINT,TX)

} INTEGRATE;

void INTEGRATE_init__(INTEGRATE *data__, BOOL retain);
// Code part
void INTEGRATE_body__(INTEGRATE *data__);
// FUNCTION_BLOCK FT_INT_BLOCK
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,K)
  __DECLARE_VAR(BOOL,RUN)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,OUT_MIN)
  __DECLARE_VAR(REAL,OUT_MAX)
  __DECLARE_VAR(REAL,OUT)
  __DECLARE_VAR(BOOL,LIM)

  // FB private variables - TEMP, private and located variables
  INTEGRATE INTEG;

} FT_INT_BLOCK;

void FT_INT_BLOCK_init__(FT_INT_BLOCK *data__, BOOL retain);
// Code part
void FT_INT_BLOCK_body__(FT_INT_BLOCK *data__);
// FUNCTION_BLOCK FT_DERIV
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,K)
  __DECLARE_VAR(BOOL,RUN)
  __DECLARE_VAR(REAL,OUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,OLD)
  __DECLARE_VAR(UDINT,TX)
  __DECLARE_VAR(UDINT,LAST)
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(REAL,TC)
  T_PLC_US_BLOCK T_PLC_US;

} FT_DERIV;

void FT_DERIV_init__(FT_DERIV *data__, BOOL retain);
// Code part
void FT_DERIV_body__(FT_DERIV *data__);
// FUNCTION_BLOCK FT_PID
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,KP)
  __DECLARE_VAR(REAL,TN)
  __DECLARE_VAR(REAL,TV)
  __DECLARE_VAR(REAL,ILIM_L)
  __DECLARE_VAR(REAL,ILIM_H)
  __DECLARE_VAR(BOOL,IEN)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,Y)
  __DECLARE_VAR(BOOL,LIM)

  // FB private variables - TEMP, private and located variables
  FT_INT_BLOCK INTEG;
  FT_DERIV DIFF;

} FT_PID;

void FT_PID_init__(FT_PID *data__, BOOL retain);
// Code part
void FT_PID_body__(FT_PID *data__);
// PROGRAM PROGRAM0
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,KP)
  __DECLARE_VAR(REAL,TN)
  __DECLARE_VAR(REAL,TV)
  __DECLARE_VAR(REAL,ILIM_L)
  __DECLARE_VAR(REAL,ILIM_H)
  __DECLARE_VAR(BOOL,IEN)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,Y)
  __DECLARE_VAR(BOOL,LIM)
  FT_PID FUNC_BLOCK;

} PROGRAM0;

void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain);
// Code part
void PROGRAM0_body__(PROGRAM0 *data__);
#endif //__POUS_H
