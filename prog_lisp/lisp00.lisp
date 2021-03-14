(defun myMember (L n)
  (cond
    ((null L) nil)
    ((equal n (car L)) L)
    (t (myMember (cdr L) n))))
