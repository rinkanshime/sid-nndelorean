/*
 * -------------------------------------------------------------------
 * NNDeLorean SID
 * DeLorean DMC-12 Time Machine Status Indicator Display prop 
 * from Back to the Future trilogy 
 * created for NNDeLorean - first russian DMC-12 Time Machine
 * (C) 2024 Mark Michurin (Rinkanshime)
 * https://github.com/rinkanshime/SID_NNDeLorean
 * https://nndelorean.ru
 *
 * Spectrum Analyzer
 *
 * -------------------------------------------------------------------
 * License: MIT
 * 
 * Permission is hereby granted, free of charge, to any person 
 * obtaining a copy of this software and associated documentation 
 * files (the "Software"), to deal in the Software without restriction, 
 * including without limitation the rights to use, copy, modify, 
 * merge, publish, distribute, sublicense, and/or sell copies of the 
 * Software, and to permit persons to whom the Software is furnished to 
 * do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef _SID_SA_H
#define _SID_SA_H

extern bool saActive;   // Read only!
extern bool doPeaks;

#define SA_START_DELAY  1000   // Delay to skip the mic's startup noise

void sa_activate(bool init = true, unsigned long start_Delay = SA_START_DELAY);
void sa_deactivate();

int sa_setAmpFact(int newAmpFact);

void sa_loop();

#endif
