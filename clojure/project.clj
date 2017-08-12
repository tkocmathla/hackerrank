(defproject hackerrank "0.1.0-SNAPSHOT"
  :description "HackerRank solutions"
  :url "https://github.com/tkocmathla/hackerrank"
  :license {:name "Eclipse Public License"
            :url "http://www.eclipse.org/legal/epl-v10.html"}
  :dependencies [[org.clojure/clojure "1.9.0-alpha4"]]
  :main ^:skip-aot hackerrank.core
  :target-path "target/%s"
  :profiles {:uberjar {:aot :all}})
