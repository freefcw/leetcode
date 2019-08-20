package leetcode

import "testing"

func TestSimpleNumberToWords(t *testing.T) {
	tests := []struct {
		input  int
		expect string
	}{
		{
			input:  0,
			expect: "",
		}, {
			input:  1,
			expect: "One",
		}, {
			input:  19,
			expect: "Nineteen",
		}, {
			input:  10,
			expect: "Ten",
		}, {
			input:  20,
			expect: "Twenty",
		}, {
			input:  21,
			expect: "Twenty One",
		}, {
			input:  29,
			expect: "Twenty Nine",
		}, {
			input:  99,
			expect: "Ninety Nine",
		}, {
			input:  100,
			expect: "One Hundred",
		}, {
			input:  123,
			expect: "One Hundred Twenty Three",
		}, {
			input:  120,
			expect: "One Hundred Twenty",
		}, {
			input:  201,
			expect: "Two Hundred One",
		}, {
			input:  999,
			expect: "Nine Hundred Ninety Nine",
		},
	}

	for _, item := range tests {
		actual := simpleNumberToWords(item.input)
		if actual != item.expect {
			t.Fatalf("%d expect %s, actual %s\n", item.input, item.expect, actual)
		}
	}
}

func TestNumberToWords(t *testing.T) {
	tests := []struct {
		input  int
		expect string
	}{
		{
			input:  0,
			expect: "Zero",
		}, {
			input:  1,
			expect: "One",
		}, {
			input:  20,
			expect: "Twenty",
		}, {
			input:  120,
			expect: "One Hundred Twenty",
		}, {
			input:  999,
			expect: "Nine Hundred Ninety Nine",
		}, {
			input:  1000,
			expect: "One Thousand",
		}, {
			input:  12345,
			expect: "Twelve Thousand Three Hundred Forty Five",
		}, {
			input:  1000000,
			expect: "One Million",
		}, {
			input:  1234567,
			expect: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven",
		}, {
			input:  1234567891,
			expect: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One",
		},
	}

	for _, item := range tests {
		actual := numberToWords(item.input)
		if actual != item.expect {
			t.Fatalf("%d expect %s, actual %s\n", item.input, item.expect, actual)
		}
	}
}
