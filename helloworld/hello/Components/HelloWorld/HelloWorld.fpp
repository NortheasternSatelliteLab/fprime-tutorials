module hello {
    @ Hello World component
    active component HelloWorld {

        # One async command/port is required for active components
        # This should be overridden by the developers with a useful command/port
        @ TODO
        @ Command to issue greeting with maximum length of 20 characters
        async command SAY_HELLO(
            greeting: string size 20 @< Greeting to repeat in the Hello event
        )

        @ Greeting event with maximum greeting length of 20 characters
        event Hello(
            greeting: string size 20 @< Greeting supplied from the SAY_HELLO command
        ) severity activity high format "I say: {}"

        @ A count of the number of greetings issued
        telemetry GreetingCount: U32

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Enables command handling
        import Fw.Command

        @ Enables event handling
        import Fw.Event

        @ Enables telemetry channels handling
        import Fw.Channel

        @ Port to return the value of a parameter
        param get port prmGetOut

        @Port to set the value of a parameter
        param set port prmSetOut

    }
}