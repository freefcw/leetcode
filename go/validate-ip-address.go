package leetcode

import (
	"errors"
	"strconv"
	"strings"
)

func isValid4Item(segment string) (int, error) {
	if segment == "" {
		return -1, errors.New("empty string")
	}
	num, err := strconv.Atoi(segment)
	if err != nil {
		return -1, err
	}
	if (num != 0 && segment[0] == '0') || (num == 0 && len(segment) > 1) {
		return -1, errors.New("invalid lead 0")
	}
	if num > 255 || num < 0 {
		return -1, errors.New("invalid range")
	}
	return num, nil
}

func isValid6Item(item string) (uint64, error) {
	length := len(item)
	if length > 4 || length == 0 {
		return 0, errors.New("invalid length")
	}
	if item[0] == '0' && length != 4 && length > 1 {
		if item[1] == '0' {
			return 0, errors.New("invalid lead 0")
		}
	}

	num, err := strconv.ParseUint(item, 16, 16)
	if err != nil {
		return 0, err
	}
	return num, nil
}

func isValidIPv4(ip string) bool {
	segments := strings.Split(ip, ".")
	if len(segments) != 4 {
		return false
	}
	for _, item := range segments {
		_, err := isValid4Item(item)
		if err != nil {
			return false
		}
	}

	return true
}

func isValidIPv6(ip string) bool {
	segments := strings.Split(ip, ":")
	if len(segments) != 8 {
		return false
	}
	for _, item := range segments {
		_, err := isValid6Item(item)
		if err != nil {
			return false
		}
	}

	return true
}

func validIPAddress(IP string) string {
	if strings.ContainsRune(IP, '.') {
		if isValidIPv4(IP) {
			return "IPv4"
		}
		return "Neither"
	}
	if strings.ContainsRune(IP, ':') {
		if isValidIPv6(IP) {
			return "IPv6"
		}
		return "Neither"
	}
	return "Neither"
}
