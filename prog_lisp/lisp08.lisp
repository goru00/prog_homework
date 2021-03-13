(defun f3 (L)
  (cond
    ((null (cdr L)) (car L))
    ((> (car L) (f3 (cdr L))) (car L))
    (t (f3 (cdr L)))))
