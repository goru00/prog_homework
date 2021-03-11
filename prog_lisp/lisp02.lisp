(defun ListSum (n)
  (if (null n)
	   0
	   (+ (car n) (ListSum(cdr n)))))
