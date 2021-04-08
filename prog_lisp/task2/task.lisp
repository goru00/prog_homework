;; var3
;; первое задание
;; для первого выражения
(/ (+ (- x 1) (sqrt (- (expt x 2) 6))) (* 3 (- x 2)))
;; для второго выражения
(/ (+ (expt (+ (* x x) (expt (sin x) 2)) (/ 1 3)) (expt (+ (* 2 x) 1) 2)) (+ (expt (cos x) 2) 1))

((lambda(x)(/ (+ (- x 1) (sqrt (- (expt x 2) 6))) (* 3 (- x 2))))3)

((lambda(x)(/ (+ (expt (+ (* x x) (expt (sin x) 2)) (/ 1 3)) (expt (+ (* 2 x) 1) 2)) (+ (expt (cos x) 2) 1)))2)
;; второе задание
(defun f2 (x y) (abs(+ (expt x 3) (* 4 (expt x 2)) (* 7 (expt y (cos x))))))
;; третье задание 
(defun f3_rec (n)
  (cond
    ((= n 1) 1)
    ((= n 2) 2)
    (t (- (* (expt (f3_rec (- n 2)) 2) 2) (* 7 (f3_rec (- n 1)))))))
(defun f3 (n)
  (f3_iter 1 2 n))
(defun f3_iter (arg1 arg2 c)
  (cond
    ((= c 2) arg2)
    (t (f3_iter arg2 (- (* 2 arg1 arg1) (* 7 arg2)) (- c 1)))))

(time (f3 10))
(time (f3_rec 10))
;; четвертое задание
(defun f4 (L)
  (cond
    ((null L) nil)
    (t (append (cons (caddr L) (list (cadr L) (car L))) (f4 (cdddr L))))))
;; пятое задание
(defun f5 (L1 L2)
  (cond
    ((null L1) L2)
    ((null L2) L1)
    (t (cons (- (car L1) (car L2)) (f5 (cdr L1) (cdr L2))))))
