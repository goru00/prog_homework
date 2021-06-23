;; 1
(defmacro f1 (&rest arg)
  (if arg
      (if (eval (caar arg))
	  (cons 'progn (cdar arg))
	  (cons 'cond2 (cdr arg)))))
;; 2
(defmacro f2 (condit &rest body)
  `(if ,condit (progn ,@body)))
;; 3
(defun f3 (L K)
  (cond
    ((null L) nil)
    ((append (mapcar #'(lambda (x) (list (car L) x)) K) (f3 (cdr L) K)))))

;; 4
(defun f4 (L)
  (if L (append (mapcar #'(lambda (x)
			    (list (car L) x)) (cdr L))
		(f4 (cdr L))) ))
;; 5
(defun f5 (L)
  (cond
    ((null L) nil)
    ((null (cdr L)) (list L))
    (t(loop for el in L append (mapcar (lambda (x) (cons el x)) (f5 (remove el L)))))))
      
    

