void T_PLC_US_BLOCK_init__(T_PLC_US_BLOCK *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->T_PLC_US,0,retain)
  __INIT_EXTERNAL(INT,PLC_TICKS_PER_SEC,data__->PLC_TICKS_PER_SEC,retain)
  __INIT_EXTERNAL(DINT,PLC_SYS_TICK_CNT,data__->PLC_SYS_TICK_CNT,retain)
  __INIT_VAR(data__->DEBUG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->OFFSET,0,retain)
  __INIT_VAR(data__->TEMP,__DWORD_LITERAL(1),retain)
  __INIT_VAR(data__->MODE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FAKTOR,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->V_PLC_TICKS_PER_SEC,0,retain)
  __INIT_VAR(data__->BASE,__UDINT_LITERAL(1000000),retain)
}

// Code part
void T_PLC_US_BLOCK_body__(T_PLC_US_BLOCK *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->INIT,) == __BOOL_LITERAL(FALSE))) {
    __SET_VAR(data__->,V_PLC_TICKS_PER_SEC,,INT_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)__GET_EXTERNAL(data__->PLC_TICKS_PER_SEC,)));
    if ((__GET_VAR(data__->V_PLC_TICKS_PER_SEC,) == __UDINT_LITERAL(1024))) {
      __SET_VAR(data__->,FAKTOR,,__UDINT_LITERAL(1000));
      __SET_VAR(data__->,MODE,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->V_PLC_TICKS_PER_SEC,) > __UDINT_LITERAL(0))) {
      if ((__GET_VAR(data__->V_PLC_TICKS_PER_SEC,) <= __GET_VAR(data__->BASE,))) {
        __SET_VAR(data__->,FAKTOR,,(__GET_VAR(data__->BASE,) / __GET_VAR(data__->V_PLC_TICKS_PER_SEC,)));
        __SET_VAR(data__->,MODE,,__BOOL_LITERAL(FALSE));
      } else {
        __SET_VAR(data__->,FAKTOR,,(__GET_VAR(data__->V_PLC_TICKS_PER_SEC,) / __GET_VAR(data__->BASE,)));
        __SET_VAR(data__->,MODE,,__BOOL_LITERAL(TRUE));
      };
    } else {
      __SET_VAR(data__->,FAKTOR,,__UDINT_LITERAL(1));
    };
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->MODE,)) {
    __SET_VAR(data__->,T_PLC_US,,(DINT_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)__GET_EXTERNAL(data__->PLC_SYS_TICK_CNT,)) / __GET_VAR(data__->FAKTOR,)));
  } else {
    __SET_VAR(data__->,T_PLC_US,,(DINT_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)__GET_EXTERNAL(data__->PLC_SYS_TICK_CNT,)) * __GET_VAR(data__->FAKTOR,)));
  };
  if (__GET_VAR(data__->DEBUG,)) {
    __SET_VAR(data__->,T_PLC_US,,((DWORD_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)(SHL__DWORD__DWORD__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)UDINT_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (UDINT)__GET_VAR(data__->T_PLC_US,)),
        (INT)__GET_VAR(data__->N,)) | SHL__DWORD__DWORD__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__GET_VAR(data__->TEMP,),
        (INT)__GET_VAR(data__->N,)))) - __UDINT_LITERAL(1)) + __GET_VAR(data__->OFFSET,)));
  };

  goto __end;

__end:
  return;
} // T_PLC_US_BLOCK_body__() 





void T_PLC_MS_BLOCK_init__(T_PLC_MS_BLOCK *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->T_PLC_MS,0,retain)
  __INIT_EXTERNAL(INT,PLC_TICKS_PER_SEC,data__->PLC_TICKS_PER_SEC,retain)
  __INIT_EXTERNAL(DINT,PLC_SYS_TICK_CNT,data__->PLC_SYS_TICK_CNT,retain)
  __INIT_VAR(data__->DEBUG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->OFFSET,0,retain)
  __INIT_VAR(data__->TEMP,__DWORD_LITERAL(1),retain)
  __INIT_VAR(data__->MODE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FAKTOR,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->V_PLC_TICKS_PER_SEC,0,retain)
  __INIT_VAR(data__->BASE,__UDINT_LITERAL(1000),retain)
}

// Code part
void T_PLC_MS_BLOCK_body__(T_PLC_MS_BLOCK *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->INIT,) == __BOOL_LITERAL(FALSE))) {
    __SET_VAR(data__->,V_PLC_TICKS_PER_SEC,,INT_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)__GET_EXTERNAL(data__->PLC_TICKS_PER_SEC,)));
    if ((__GET_VAR(data__->V_PLC_TICKS_PER_SEC,) == __UDINT_LITERAL(1024))) {
      __SET_VAR(data__->,FAKTOR,,__UDINT_LITERAL(1));
      __SET_VAR(data__->,MODE,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->V_PLC_TICKS_PER_SEC,) > __UDINT_LITERAL(0))) {
      if ((__GET_VAR(data__->V_PLC_TICKS_PER_SEC,) <= __GET_VAR(data__->BASE,))) {
        __SET_VAR(data__->,FAKTOR,,(__GET_VAR(data__->BASE,) / __GET_VAR(data__->V_PLC_TICKS_PER_SEC,)));
        __SET_VAR(data__->,MODE,,__BOOL_LITERAL(FALSE));
      } else {
        __SET_VAR(data__->,FAKTOR,,(__GET_VAR(data__->V_PLC_TICKS_PER_SEC,) / __GET_VAR(data__->BASE,)));
        __SET_VAR(data__->,MODE,,__BOOL_LITERAL(TRUE));
      };
    } else {
      __SET_VAR(data__->,FAKTOR,,__UDINT_LITERAL(1));
    };
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->MODE,)) {
    __SET_VAR(data__->,T_PLC_MS,,(DINT_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)__GET_EXTERNAL(data__->PLC_SYS_TICK_CNT,)) / __GET_VAR(data__->FAKTOR,)));
  } else {
    __SET_VAR(data__->,T_PLC_MS,,(DINT_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)__GET_EXTERNAL(data__->PLC_SYS_TICK_CNT,)) * __GET_VAR(data__->FAKTOR,)));
  };
  if (__GET_VAR(data__->DEBUG,)) {
    __SET_VAR(data__->,T_PLC_MS,,((DWORD_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)(SHL__DWORD__DWORD__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)UDINT_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (UDINT)__GET_VAR(data__->T_PLC_MS,)),
        (INT)__GET_VAR(data__->N,)) | SHL__DWORD__DWORD__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__GET_VAR(data__->TEMP,),
        (INT)__GET_VAR(data__->N,)))) - __UDINT_LITERAL(1)) + __GET_VAR(data__->OFFSET,)));
  };

  goto __end;

__end:
  return;
} // T_PLC_MS_BLOCK_body__() 





void INTEGRATE_init__(INTEGRATE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->E,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->K,1.0,retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->X_LAST,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  T_PLC_MS_BLOCK_init__(&data__->T_PLC_MS,retain);
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->TX,0,retain)
}

// Code part
void INTEGRATE_body__(INTEGRATE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  T_PLC_MS_BLOCK_body__(&data__->T_PLC_MS);
  __SET_VAR(data__->,TX,,__GET_VAR(data__->T_PLC_MS.T_PLC_MS,));
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,X_LAST,,__GET_VAR(data__->X,));
  } else if (__GET_VAR(data__->E,)) {
    __SET_VAR(data__->,Y,,(((((__GET_VAR(data__->X,) + __GET_VAR(data__->X_LAST,)) * 0.5E-3) * UDINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,)))) * __GET_VAR(data__->K,)) + __GET_VAR(data__->Y,)));
    __SET_VAR(data__->,X_LAST,,__GET_VAR(data__->X,));
  };
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));

  goto __end;

__end:
  return;
} // INTEGRATE_body__() 





void FT_INT_BLOCK_init__(FT_INT_BLOCK *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->K,1.0,retain)
  __INIT_VAR(data__->RUN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT_MIN,__REAL_LITERAL(-1.0E-37),retain)
  __INIT_VAR(data__->OUT_MAX,__REAL_LITERAL(1.0E37),retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->LIM,__BOOL_LITERAL(FALSE),retain)
  INTEGRATE_init__(&data__->INTEG,retain);
}

// Code part
void FT_INT_BLOCK_body__(FT_INT_BLOCK *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,OUT,,0.0);
  } else {
    __SET_VAR(data__->INTEG.,E,,__GET_VAR(data__->RUN,));
    __SET_VAR(data__->INTEG.,X,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->INTEG.,K,,__GET_VAR(data__->K,));
    __SET_VAR(data__->INTEG.,Y,,__GET_VAR(data__->OUT,));
    INTEGRATE_body__(&data__->INTEG);
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->INTEG.Y));
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->INTEG.Y,));
  };
  if ((__GET_VAR(data__->OUT,) >= __GET_VAR(data__->OUT_MAX,))) {
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->OUT_MAX,));
    __SET_VAR(data__->,LIM,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->OUT,) <= __GET_VAR(data__->OUT_MIN,))) {
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->OUT_MIN,));
    __SET_VAR(data__->,LIM,,__BOOL_LITERAL(TRUE));
  } else {
    __SET_VAR(data__->,LIM,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // FT_INT_BLOCK_body__() 





void FT_DERIV_init__(FT_DERIV *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->K,1.0,retain)
  __INIT_VAR(data__->RUN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->OLD,0,retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TC,0,retain)
  T_PLC_US_BLOCK_init__(&data__->T_PLC_US,retain);
}

// Code part
void FT_DERIV_body__(FT_DERIV *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  T_PLC_US_BLOCK_body__(&data__->T_PLC_US);
  __SET_VAR(data__->,TX,,__GET_VAR(data__->T_PLC_US.T_PLC_US,));
  __SET_VAR(data__->,TC,,UDINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,))));
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,OLD,,__GET_VAR(data__->IN,));
  } else if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->TC,) > 0.0))) {
    __SET_VAR(data__->,OUT,,((((__GET_VAR(data__->IN,) - __GET_VAR(data__->OLD,)) / __GET_VAR(data__->TC,)) * 1000000.0) * __GET_VAR(data__->K,)));
    __SET_VAR(data__->,OLD,,__GET_VAR(data__->IN,));
  } else {
    __SET_VAR(data__->,OUT,,0.0);
  };
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  T_PLC_US_BLOCK_body__(&data__->T_PLC_US);
  __SET_VAR(data__->,TX,,__GET_VAR(data__->T_PLC_US.T_PLC_US,));
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->RUN,) && ((__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,)) > __UDINT_LITERAL(0)))) {
    __SET_VAR(data__->,OUT,,((((__GET_VAR(data__->IN,) - __GET_VAR(data__->OLD,)) / UDINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,)))) * 1000000.0) * __GET_VAR(data__->K,)));
  } else {
    __SET_VAR(data__->,OUT,,0.0);
  };
  __SET_VAR(data__->,OLD,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));

  goto __end;

__end:
  return;
} // FT_DERIV_body__() 





void FT_PID_init__(FT_PID *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->KP,1.0,retain)
  __INIT_VAR(data__->TN,1.0,retain)
  __INIT_VAR(data__->TV,1.0,retain)
  __INIT_VAR(data__->ILIM_L,-1.0E38,retain)
  __INIT_VAR(data__->ILIM_H,1.0E38,retain)
  __INIT_VAR(data__->IEN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->LIM,__BOOL_LITERAL(FALSE),retain)
  FT_INT_BLOCK_init__(&data__->INTEG,retain);
  FT_DERIV_init__(&data__->DIFF,retain);
}

// Code part
void FT_PID_body__(FT_PID *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TN,) > 0.0)) {
    __SET_VAR(data__->INTEG.,IN,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->INTEG.,K,,(1.0 / __GET_VAR(data__->TN,)));
    __SET_VAR(data__->INTEG.,RUN,,__GET_VAR(data__->IEN,));
    __SET_VAR(data__->INTEG.,RST,,__GET_VAR(data__->RST,));
    __SET_VAR(data__->INTEG.,OUT_MIN,,__GET_VAR(data__->ILIM_L,));
    __SET_VAR(data__->INTEG.,OUT_MAX,,__GET_VAR(data__->ILIM_H,));
    FT_INT_BLOCK_body__(&data__->INTEG);
  } else {
    __SET_VAR(data__->INTEG.,RST,,__BOOL_LITERAL(FALSE));
    FT_INT_BLOCK_body__(&data__->INTEG);
  };
  __SET_VAR(data__->DIFF.,IN,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->DIFF.,K,,__GET_VAR(data__->TV,));
  FT_DERIV_body__(&data__->DIFF);
  __SET_VAR(data__->,Y,,(__GET_VAR(data__->KP,) * ((__GET_VAR(data__->INTEG.OUT,) + __GET_VAR(data__->DIFF.OUT,)) + __GET_VAR(data__->IN,))));
  __SET_VAR(data__->,LIM,,__GET_VAR(data__->INTEG.LIM,));

  goto __end;

__end:
  return;
} // FT_PID_body__() 





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->KP,1.0,retain)
  __INIT_VAR(data__->TN,1.0,retain)
  __INIT_VAR(data__->TV,1.0,retain)
  __INIT_VAR(data__->ILIM_L,-1.0E38,retain)
  __INIT_VAR(data__->ILIM_H,1.0E38,retain)
  __INIT_VAR(data__->IEN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->LIM,__BOOL_LITERAL(FALSE),retain)
  FT_PID_init__(&data__->FUNC_BLOCK,retain);
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,FUNC_BLOCK.IN,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->,FUNC_BLOCK.KP,,__GET_VAR(data__->KP,));
  __SET_VAR(data__->,FUNC_BLOCK.TN,,__GET_VAR(data__->TN,));
  __SET_VAR(data__->,FUNC_BLOCK.TV,,__GET_VAR(data__->TV,));
  __SET_VAR(data__->,FUNC_BLOCK.ILIM_L,,__GET_VAR(data__->ILIM_L,));
  __SET_VAR(data__->,FUNC_BLOCK.ILIM_H,,__GET_VAR(data__->ILIM_H,));
  __SET_VAR(data__->,FUNC_BLOCK.IEN,,__GET_VAR(data__->IEN,));
  __SET_VAR(data__->,FUNC_BLOCK.RST,,__GET_VAR(data__->RST,));
  FT_PID_body__(&data__->FUNC_BLOCK);
  __SET_VAR(data__->,Y,,__GET_VAR(data__->FUNC_BLOCK.Y,));
  __SET_VAR(data__->,LIM,,__GET_VAR(data__->FUNC_BLOCK.LIM,));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





