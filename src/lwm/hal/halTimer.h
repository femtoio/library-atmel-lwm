/**
 * \file halTimer.h
 *
 * \brief Arduino implementation of the HAL interface
 *
 * Copyright (C) 2014, Matthijs Kooijman <matthijs@stdin.nl>
 *
 * This file is licensed under the 2-clause BSD license:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 * WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef _HAL_TIMER_H_
#define _HAL_TIMER_H_

// Normally, this interface is implemented using an interrupt handler
// that fires every 10ms or so, incrementing the halTimerIrqCount. Since
// we don't want to spend another timer just for keeping track of
// milliseconds, we just use the return value of millis() instead.

// This defines the multiplier to translate from halTimerIrqCount to
// milliseconds, which is just 1 in our case
#define HAL_TIMER_INTERVAL      1ul // ms

#define halTimerIrqCount (millis())

/*- Definitions ------------------------------------------------------------*/
#define TIMER_PRESCALER  8
#define TIMER_TOP        (((F_CPU / 1000ul) / TIMER_PRESCALER) * HAL_TIMER_INTERVAL)

// extern volatile uint8_t halTimerIrqCount;

extern void HAL_IrqHandlerSPI(void);

#endif // _HAL_TIMER_H_
