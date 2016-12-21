(ns hackerrank.test_euler009
  (:require [clojure.string :as s]
            [clojure.test :refer :all]
            [hackerrank.euler009 :refer [solve]]))

(deftest test-solve
  (is (= "-1" (-> "1\n4"
                  (with-in-str (solve))
                  with-out-str
                  s/trim)))
  (is (= "60" (-> "1\n12"
                  (with-in-str (solve))
                  with-out-str
                  s/trim))))
