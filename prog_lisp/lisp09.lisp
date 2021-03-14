(defun setList (L)
  (cond
    ((null L) nil)
    ((member (car L) (cdr L)) (setList (cdr L)))
    (t (cons (car L) (setList (cdr L))))))

