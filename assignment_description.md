# PLC Programming Assignment: Temperature Controller with Iterative Prompt Engineering

## Overview

In this assignment, you will generate Structured Text (ST) code for a Temperature Controller using a language model. Your goal is to iteratively refine your prompts until you obtain code that compiles successfully with the MatIEC compiler. The generated code **must** include the following blocks:

- **Function Block:** Encapsulates the temperature control logic.
- **Program:** Instantiates and calls the function block, handling input and output mapping.
- **Configuration Block:** Sets up the execution environment (resource, task, and program instance).

## Assignment Requirements

1. **Iteration Limits and Fallback:**
   - **Iteration Requirement:** You must refine your prompt iteratively.
     - **Fallback Trigger:** If, after **7 iterations**, no valid solution is produced, your input to the model should include a working example.
     - **Iteration Cap:** Do not exceed **15 iterations**.
   - **Fallback Requirement:** If you reach the fallback condition, your input to the model should include, in addition to the compiler output, the following fallback message:
     ```
     Here is an example working code:
     ```
     Followed immediately by the complete working example code exactly as found in the ENERGY.ST file.
   - **Stop Condition:** If the compiler output looks like this, that means your code is compiling with no problem, and you can submit the generated code.
        ```
        Generating C files...
        POUS.c
        POUS.h
        LOCATED_VARIABLES.h
        VARIABLES.csv
        Config0.c
        Config0.h
        Res0.c
        Moving Files...
        Compiling for Linux
        Generating object files...
        Generating glueVars...
        Compiling main program...
        Compilation finished successfully!
        ```

2. **Tool Requirement:**
   - For fairness, all students must use the **Gemini2.0 Flash**. This is a strict requirment!

3. **Submission Requirements:**
   - **Compiler Screenshots:** Submit screenshots of the MatIEC compiler output for each iteration.
   - **Chat History:** Create a publicly shareable link for the complete chat history with Gemini that documents your prompt refinement process. For a guide on how to create a shareable link check: [Share a chat](https://support.google.com/gemini/answer/13743730?).
   - The final generated PLC code.

4. **Compiler Setup:**
   - For instructions on how to set up the compiler environment and compile the generated code, please check the `readme.md` file.

5. **Grading:**
   - Grading will be based on how well you follow the guidelines outlined in this assignment description. As long as you adhere to the guidelines, it is acceptable even if the final code after 15 iterations is not compilable. However, if you do not follow the guidelines, points will be deducted.

## PLC Programming Specification: Temperature Controller

### System Overview
The Temperature Controller is designed to regulate a heating element in order to maintain a user-defined temperature setpoint. The controller continuously monitors the current temperature, compares it with the setpoint, and activates or deactivates the heater based on this comparison and predefined safety limits. Your generated code must include the following blocks:

- **Function Block:** Implements the temperature control logic.
- **Program:** Instantiates the function block and maps its inputs/outputs.
- **Configuration Block:** Defines the resource, task, and program instance for execution.

### Functional Requirements

1. **Input Signals:**
   - **Temperature Sensor (Analog Input):** Provides the current temperature reading.
   - **Setpoint Input (Analog/Digital Input):** Specifies the desired temperature value.
   - **System Enable/Disable (Digital Input):** A flag that activates or deactivates the controller.

2. **Output Signals:**
   - **Heater Control (Digital Output):** Controls the activation of the heating element.
   - **Alarm/Indicator (Digital Output):** Signals when the temperature exceeds a safe threshold or a fault occurs.

3. **Control Logic:**
   - **Temperature Regulation:**  
     - If the system is enabled and the current temperature is below the setpoint by a fixed hysteresis value (e.g., 1.0°C), activate the heater.
     - Once the temperature reaches or exceeds the setpoint, deactivate the heater.
   - **Safety Control:**  
     - If the temperature exceeds a predefined maximum limit (e.g., 100.0°C), immediately deactivate the heater and trigger an alarm.
   - **Initialization and Shutdown:**  
     - On startup, validate sensor inputs and initialize outputs to a safe state (heater OFF).
     - Ensure safe shutdown procedures in the event of critical errors.

### Technical Details

- **Programming Language:** Structured Text (ST)
- **Compiler:** MatIEC
- **Sampling Interval:** Sample temperature sensor values at regular intervals (e.g., every 500 ms).
- **Debounce Mechanism:** Implement debounce logic for the system enable/disable signal to avoid false triggering.
- **Hysteresis:** Use a hysteresis margin (e.g., 1.0°C) to prevent rapid toggling near the setpoint.

## Initial Prompt for the Language Model

When interacting with the language model, use the following initial prompt:

> **Prompt:**  
> "Based on the following PLC programming specification for a Temperature Controller, generate Structured Text (ST) code that implements this specification. Include a function block for the temperature control logic, a program that instantiates and calls this function block, and a configuration block. **Only output the code and nothing else.**"

After the above prompt, include the program specification written above [PLC Programming Specification: Temperature Controller](#plc-programming-specification-temperature-controller)

---

For any question: yachamye@uci.edu

Good luck!
