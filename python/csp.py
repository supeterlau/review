# https://chrispenner.ca/posts/python-tail-recursion
# http://baruchel.github.io/python/2013/12/03/tail-recursion-in-python/
# http://baruchel.github.io/python/2015/07/10/continuation-passing-style-in-python/

import traceback

# csp 的目标是 tail-call optimization

# argument and the current size of the stack
def disp(x):
    print(len(traceback.extract_stack()), x)

def test(k, n):
    return test(k, n-1) if n > 0 else k(42)

# (lambda : 2)()
# 2

def test1():
    return test(disp, 100)

Wrapper = lambda f: lambda c, *a: f(lambda x: lambda : c(x), *a)()

def test2():
    return Wrapper(test)(disp, 100)

# 1. Wrapper(test) ->
# lambda c, *a: test(lambda x: lambda: c(x), *a)()
# c = disp, *a = 100
# 2. Wrapper(test)(disp, 100) ->
# test(lambda x: lambda: disp(x), 100)()
