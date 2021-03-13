(defun f (L)
  (cond
    ((null (cdr L)) nil)
    (t (cons (car L) (f (cdr L))))))
