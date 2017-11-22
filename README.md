# Arduino Button Debounce Example

This is a basic example of how to handle a momentary switch as a digital input. The example has an LED connected to a PWM pin which increases by a fith of its total analogue output for each press on the debounced button.

## What the hell is switch bouncing, anyway?

Have you ever hooked up a momentary switch, only to press it an experience jittery behavior on the running Arduino? Well, this is likely because the switch "bounces". Since we are *pretty close* to the bare metal when programming Arduinos, we start to experience som physical quirks in our software. Something we're never used to when moving further away from the *metal*.

**This is what you expect when pressing a momentary switch:**

![](https://i.imgur.com/Ak7tRnz.png)

... and as such you expect the voltage to go from 0V to 3.3V or 5V, an thus producing a *digital high*. This happens... eventually...

**This is what *actually* happens:**

![](https://i.imgur.com/WOMJSQP.png)

The digital state of the switch *bounces* up and down many times in the matter of very few miliseconds, thus probably producing multiple "toggles" which is picked up by your code, causing unexpected behavior which is Really Hard To Debug™

## The solution

Basically, we need some way to deafen the noise caused by the state bouncing. It really is quite simple, but a REALLY big PITA if you don't know about it.

Here's an example from the source:

```
boolean debounce(boolean last)
{
  boolean current = digitalRead(switchPin);
  
  if(last != current)
  {
    delay(5);
    current = digitalRead(switchPin);
  }
    
  return current;
}
```

This snippet "deafens" the input for 5 miliseconds - should be more than enough to mitigate the state bouncing (yes, it happens really fast).
