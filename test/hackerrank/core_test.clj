(ns hackerrank.core-test
  (:require [clojure.string :as s]
            [clojure.test :refer :all]
            [hackerrank.core]))

(deftest test-euler009 
  (is (= "-1" (-> "1\n4"
                  (with-in-str (hackerrank.euler009/solve))
                  with-out-str
                  s/trim)))
  (is (= "60" (-> "1\n12"
                  (with-in-str (hackerrank.euler009/solve))
                  with-out-str
                  s/trim))))