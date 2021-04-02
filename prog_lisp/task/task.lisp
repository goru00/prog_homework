(defun first-atom (L)
  (cond
    ((atom L) L)
    (t (first-atom (car L)))))
(defun devpair (L)
  (cond
    ((null L) nil)
    ((null (cdr L)) L)
    (t (cons (list (car L) (cadr L)) (devpair (cddr L))))))
(defun devlev1 (L)
  (cond
    ((null L) nil)
    ((null (cdr L)) L)
    (t (list (car L) (devlev1 (cdr L))))))



(defun devlev2 (L)
  (cond
    ((null L) nil)
    (t (devlev2_split (cdr L) (list (car L))))))
(defun devlev2_split (L q)
  (cond
    ((null (cdr L)) (cons q L))
    (t (devlev2_split (cdr L) (cons q (list (car L)))))))



(defun revl (L)
  (cond
    ((null (cdr L)) L)
    (t (cons (revl (cdr L)) (list (car L))))))
(defun remsec (L)
  (cond
    ((null (cdr L)) L)
    (t (cons (car L) (remsec (cddr L))))))
(defun substitue (L old new)
  (cond
    ((null L) nil)
    ((equal old (car L)) (cons new (substitue (cdr L) old new)))
    (t (cons (car L) (substitue (cdr L) old new)))))
(defun flatten (L)
  (cond
    ((null L) nil)
    ((atom L) (list L))
    (t (mapcan 'flatten L))))
(defun depth (L)
  (cond
    ((atom L) 0)
    (t (max (+ 1 (depth (car L))) (depth (cdr L))))))
(defun destlev1 (L)
  (cond
    ((null L) nil)
    ((atom (car L)) (cons (car L) (destlev1 (cdr L))))
    (t (append (destlev1 (car L)) (destlev1 (cdr L))))))

(defun collect (L)
  (cond
    ((null L) nil)
    (t (collect_condition L '()))))
(defun collect_condition (L q)
  (cond
    ((null L) nil)
    ((member (car L) q) (collect_condition (cdr L) q))
    (t (append (collect_append (cdr L) (car L)) (collect_condition (cdr L) (cons (car L) q))))))
(defun collect_append (L q)
  (cond
    ((null L) (cons q NIL))
    ((equal (car L) q) (cons (car L) (collect_append (cdr L) q)))
    (t (collect_append (cdr L) q))))

(defun FORALL (L)
  (cond
    ((equal (P L) NIL) NIL)
    (t)))
(defun P (L)
  (cond
    ((null L) nil)
    ((member L NIL) T)
    (t nil)))

(defun FORSOME (L)
  (cond
    ((equal (P L) NIL) NIL)
    (t)))
(defun P (L)
  (cond
    ((null L) NIL)
    ((equal (car L) NIL) (P (cdr L)))
    (t (car L))))
			   
