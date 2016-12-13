(ns hackerrank.euler009)

(defn max-prod [n]
  (let [ans (for [a (range 1 n)
                  :let [b (quot (- (* 2 a n) (* n n)) (* 2 (- a n)))
                        c (- n a b)]
                  :when (and (> c b) (> c a) (> b a) 
                             (= (+ (* a a) (* b b)) (* c c)))]
              (* a b c))]
    (if (seq ans) (apply max ans) -1)))
  
(defn solve []
  (letfn [(read-int [] (->> (read-line) Integer/parseInt))]
    (loop [t (read-int) ans []]
      (if (> t 0)
        (recur (dec t) (conj ans (max-prod (read-int))))
        (doseq [x ans] (println x))))))