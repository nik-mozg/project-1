add_test([=[TestCaseSearchServer.TestSimple]=]  C:/develop/40/build/tests/runTests.exe [==[--gtest_filter=TestCaseSearchServer.TestSimple]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TestCaseSearchServer.TestSimple]=]  PROPERTIES WORKING_DIRECTORY C:/develop/40/build/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TestCaseSearchServer.TestTop5]=]  C:/develop/40/build/tests/runTests.exe [==[--gtest_filter=TestCaseSearchServer.TestTop5]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TestCaseSearchServer.TestTop5]=]  PROPERTIES WORKING_DIRECTORY C:/develop/40/build/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  runTests_TESTS TestCaseSearchServer.TestSimple TestCaseSearchServer.TestTop5)
