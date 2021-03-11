(defun MyLast (L)
  (if (null (cdr L))
      (cons (car L) nil)
      (MyLast (cdr L))))
