package leetcode

import "testing"

func Test_simplify_path(t *testing.T) {
	income := "/home/../foo/"
	result := simplifyPath(income)
	if result != "/foo" {
		t.Errorf("%s:%s", income, result)
	}
	income = "/home/../../foo/"
	result = simplifyPath(income)
	if result != "/foo" {
		t.Errorf("%s:%s", income, result)
	}
	income = "/home/../foo/../"
	result = simplifyPath(income)
	if result != "/" {
		t.Errorf("%s:%s", income, result)
	}
	income = "/home//foo/../"
	result = simplifyPath(income)
	if result != "/home" {
		t.Errorf("%s:%s", income, result)
	}
	income = "/..//foo/../"
	result = simplifyPath(income)
	if result != "/" {
		t.Errorf("%s:%s", income, result)
	}
	income = "/a/./b/../../c/"
	result = simplifyPath(income)
	if result != "/c" {
		t.Errorf("%s:%s", income, result)
	}
}
