(defun f1 (L)
  (cond
    ((null (cdr L)) nil)
    (t (cons (cadr L) (f (cddr L))))))
