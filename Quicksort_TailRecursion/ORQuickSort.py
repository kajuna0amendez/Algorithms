#!/usr/bin/env python2
# -*- coding: utf-8 -*-
__author__ = "Andres Mendez-Vazquez"
__copyright__ = "Tail Recursive QuickSort"
__credits__ = ["Andres Mendez-Vazquez"]
__version__ = "1.0.0"
__license__ = "Berkley 3.0"
__maintainer__ = "Andres Mendez-Vazquez"
__email__ = "amendez@gdl.cinvestav.mx"
__status__ = "Development"

import numpy as np
import sys
import time
import random

class TailRecurseException:
  def __init__(self, args, kwargs):
    self.args = args
    self.kwargs = kwargs

def tail_call_optimized(g):
  """
  This function decorates a function with tail call
  optimization. It does this by throwing an exception
  if it is it's own grandparent, and catching such
  exceptions to fake the tail call optimization
  
  This function fails if the decorated
  function recurses in a non-tail context.
  """
  def func(*args, **kwargs):
    f = sys._getframe()
    if f.f_back and f.f_back.f_back \
        and f.f_back.f_back.f_code == f.f_code:
      raise TailRecurseException(args, kwargs)
    else:
      while 1:
        try:
          return g(*args, **kwargs)
        except TailRecurseException, e:
          args = e.args
          kwargs = e.kwargs
  func.__doc__ = g.__doc__
  return func

def DriveTailRecursiveQuickSort(Array):
  """
  The Driver of QuickSort
  """
  Rec = 0
  Left = 0 
  Right = len(Array)-1
  Stack = list()
  Stack.append((Left,Right))
  TailRecursionQuickSort(Array, Stack, Rec)
  
@tail_call_optimized
def TailRecursionQuickSort(Array, Stack, Rec):
  """
  Part of an exepriment for Tail recursion
  """
  Rec += 1
  fRec = True
  down = 0
  up = 0
  #print 'Recursion %i'% Rec
  while Stack:
    Left, Right = Stack.pop(len(Stack)-1)
    if Left < Right:
      # Generate a Random Pivote from U(0,1)
      a = np.random.random_sample(1)[0]   
      # Use an accumulator for the probabilites
      accumulator = 0.0
      M = Right-Left+1
      for i in xrange(M):
        accumulator += 1.0/float(M)
        if (a < accumulator):
          pivot =  Left + i
          break
      #Exchange pivot with right element
      Array[pivot], Array[Right] = Array[Right], Array[pivot]
      # Partition in Place
      key = Array[Right]
      it = Left - 1
      for j in xrange(Left,Right):
        if Array[j]<=key:
          it += 1
          Array[it], Array[j] = Array[j], Array[it]
      Array[it+1], Array[Right] = Array[Right], Array[it+1]
      pivot = it + 1
      # Select the Section to be send to the Tail Recursion
      if fRec == True:
        fRec = False
        if pivot-Left < Right-pivot:
          down = Left
          up = pivot-1
          Stack.append((pivot+1, Right))
        else:
          down = pivot+1
          up = Right
          Stack.append((Left, pivot-1))
      else:
        # Here the classic iterative QuickSort
        Stack.append((Left, pivot-1))
        Stack.append((pivot+1, Right))
  # Enter into the tail recursion if it is possible
  if down < up:
    Stack.append((down, up))
    TailRecursionQuickSort(Array, Stack, Rec)
    
if __name__ == '__main__':  
  n = 10000
  Test = 1
  Sampling = 100
  cnt = 0 
  acc1 = 0
  acc2 = 0
  np.random.seed()
  if Test == 0:
    n = 100
    Array = random.sample(range(2*n), n)
    DriveTailRecursiveQuickSort(Array)
    print Array[0:n]
  else:
    while cnt<Sampling:
      Array = random.sample(range(2*n), n)
      ticks1 = time.time()
      DriveTailRecursiveQuickSort(Array)
      ticks2 = time.time()
      Array = random.sample(range(2*n), n)
      ticks3 = time.time()
      sorted(Array)
      ticks4 = time.time()
      cnt += 1
      acc1 += ticks2-ticks1
      acc2 += ticks4-ticks3
    nQSTr = float(acc1)/float(Sampling)
    nSort = float(acc2)/float(Sampling)
    print 'The Average Number of Ticks for QuickSort TailRecursion %f'\
          %nQSTr
    print 'The Average Number of Ticks for TimSort %f'\
          %nSort  
    print 'Speed Up Over QuickSortTailRecusrion %f'%(nQSTr/nSort)
