;; 1
(defun f1 (f L K)
  (cond
    ((null L) nil)
    ((null K) nil)
    (t(cons(funcall f (car L) (car K)) (f1 f (cdr L) (cdr K))))))

(f1 (lambda (x y) (/ (+ (* x x) y) (+ (* x x) 1))) '(1 3 9 4) '(2 7 4 3))
;; 2
(defun f2 (L)
  (cond
    ((null (cdr L)) (car L))
    ((< (car L) (f2 (cdr L))) (car L))
    (t(f2(cdr L)))))
;; 3
(defun f3 (L K)
  (cond
    ((null (car L)) nil)
    ((member (car L) K) (car L))
    (t (f3 (cdr L) K))))
;; 4
(defmacro printf (L K)
  (progn
    (dolist (a L t)
      (princ a) (princ '_))
    (terpri)
    (dolist (a K t)
      (princ '_) (princ a))))
