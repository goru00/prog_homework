(defun f2 (L n)
  (cond
    ((= n 0) (cdr L))
    (t (cons (car L) (f2 (cdr L) (- n 1))))))
