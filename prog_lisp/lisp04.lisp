(defun MyReverse (L)
  (if (null L)
      L
      (append (MyReverse (cdr L)) (list (car L)))))
