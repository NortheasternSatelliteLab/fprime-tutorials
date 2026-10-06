// ======================================================================
// \title  LED.cpp
// \author zach
// \brief  cpp file for LED component implementation class
// ======================================================================

#include "Blinker/Components/LED/LED.hpp"

namespace Blinker {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

LED ::LED(const char* const compName) : LEDComponentBase(compName) {}

LED ::~LED() {}

// ----------------------------------------------------------------------
// Handler implementations for commands
// ----------------------------------------------------------------------

void LED::BLINKING_ON_OFF_cmdHandler(FwOpcodeType opCode, U32 cmdSeq, const Fw::On& onOff) {
    this->m_toggleCounter = 0;               // Reset count on any successful command
    this->m_blinking = Fw::On::ON == onOff;  // Update blinking state

    // TODO: Emit an event SetBlinkingState to report the blinking state (onOff).
    // NOTE: This event will be added during the "Events" exercise.
    this->log_ACTIVITY_HI_SetBlinkingState(onOff);

    // TODO: Report the blinking state (onOff) on channel BlinkingState.
    // NOTE: This telemetry channel will be added during the "Telemetry" exercise.

    // Provide command response
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);

}

}  // namespace Blinker
