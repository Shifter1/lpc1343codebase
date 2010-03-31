/**************************************************************************/
/*! 
    @file     at25040.h
    @author   K. Townsend (microBuilder.eu)
    @date     22 March 2010
    @version  0.10


    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2010, microBuilder SARL
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**************************************************************************/

#ifndef _AT25040_H_
#define _AT25040_H_

#include "sysdefs.h"

#define AT25_RDSR_RDY       0x01
#define AT25_RDSR_WEN       0x02
#define AT25_A8             0x08        // For addresses > 0xFF (AT25040 only) A8 must be added to R/W commands
#define AT25_MAXADDRESS     0x0200      // AT25040 = 0X0200, AT25020 = 0x100, AT25010 = 0x80

/**************************************************************************/
/*! 
    AT25040 Commands
*/
/**************************************************************************/
typedef enum
{
  AT25_WREN = 0x06,
  AT25_WRDI = 0x04,
  AT25_RDSR = 0x05,
  AT25_WRSR = 0x01,
  AT25_READ = 0x03,
  AT25_WRITE = 0x02
} at25_Commands_e;

/**************************************************************************/
/*! 
    Error messages
*/
/**************************************************************************/
typedef enum
{
  AT25_ERROR_OK = 0,            // Everything executed normally
  AT25_ERROR_TIMEOUT_WE,        // Timed out waiting for write enable status
  AT25_ERROR_TIMEOUT_WFINISH,   // Timed out waiting for write to finish
  AT25_ERROR_ADDRERR,           // Address out of range
  AT25_ERROR_BUFFEROVERFLOW,    // Max 6 bytes can be read/written in one operation
  AT2_ERROR_LAST
}
at25Error_e;

void at25Init (void);
at25Error_e at25Read (uint16_t address, uint8_t *buffer, uint32_t bufferLength);
at25Error_e at25Write (uint16_t address, uint8_t *buffer, uint32_t bufferLength);

#endif