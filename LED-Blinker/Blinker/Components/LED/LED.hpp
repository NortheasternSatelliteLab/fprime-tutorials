// ======================================================================
// \title  LED.hpp
// \author zach
// \brief  hpp file for LED component implementation class
// ======================================================================

#ifndef Blinker_LED_HPP
#define Blinker_LED_HPP

#include "Blinker/Components/LED/LEDComponentAc.hpp"

namespace Blinker {

class LED final : public LEDComponentBase {
  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct LED object
    LED(const char* const compName  //!< The component name
    );

    //! Destroy LED object
    ~LED();

  private:
    // ----------------------------------------------------------------------
    // Handler implementations for commands
    // ----------------------------------------------------------------------

    //! Handler implementation for command BLINKING_ON_OFF
    //!
    //! Command to turn on or off the blinking LED
    void BLINKING_ON_OFF_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                                    U32 cmdSeq,           //!< The command sequence number
                                    const Fw::On& onOff   //!< Indicates whether the blinking should be on or off
                                    ) override;

    Fw::On m_ledState = Fw::On::OFF;       //! Keeps track if LED is on or off
    U64 m_transitionCount = 0;             //! The number of on/off transitions that have occurred
                                           //! from FSW boot up
    U32 m_ticksSinceToggle = 0;            //! Keeps track of rate-group ticks since the last toggle,
                                           //! modulo the blink interval
    Fw::On m_blinkingState = Fw::On::OFF;  //! Indicates whether LED blinking is on or off
};

}  // namespace Blinker

#endif
