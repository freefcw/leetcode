package leetcode

import "testing"

func Test_Parse4Segment(t *testing.T) {
	cases := []string{"00", "01", "000", ""}
	for _, val := range cases {
		num, _ := isValid4Item(val)
		if num != -1 {
			t.Errorf("invalid lead 0: %s => %d", val, num)
		}
	}
}

func Test_Parse6Segment(t *testing.T) {
	cases := []string{"02001", "", "000"}
	for _, val := range cases {
		num, err := isValid6Item(val)
		if err == nil {
			t.Errorf("invalid lead 0: %s => %d %v", val, num, err)
		}
	}
}

func Test_ipv4(t *testing.T) {
	cases := map[string]bool{
		"172.16.254.1":    true,
		"127.0.0.1":       true,
		"255.255.255.255": true,
		"172.16.254.01":   false,
		"256.256.256.256": false,
	}
	for key, val := range cases {
		if isValidIPv4(key) != val {
			t.Errorf("check invalid")
		}
	}
}

func Test_ipv6(t *testing.T) {
	cases := map[string]bool{
		"2001:0db8:85a3:0000:0000:8a2e:0370:7334":  true,
		"2001:db8:85a3:0:0:8A2E:0370:7334":         true,
		"2001:0db8:85a3::8A2E:0370:7334":           false,
		"02001:0db8:85a3:0000:0000:8a2e:0370:7334": false,
	}
	for key, val := range cases {
		if isValidIPv6(key) != val {
			t.Errorf("check invalid %s", key)
		}
	}
}

func Test_validIPAddress(t *testing.T) {
	if validIPAddress("172.16.254.1") != "IPv4" {
		t.Errorf("failed")
	}
	if validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334") != "IPv6" {
		t.Errorf("failed")
	}
	if validIPAddress("256.256.256.256") != "Neither" {
		t.Errorf("failed")
	}
}
