package others

import "testing"

func Test_numberOfZeros(t *testing.T) {
	tests := []struct {
		input  int
		expect int
	}{
		{
			input:  1,
			expect: 0,
		}, {
			input:  5,
			expect: 1,
		}, {
			input:  10,
			expect: 7,
		}, {
			input:  100,
			expect: 1124,
		}, {
			input:  11,
			expect: 9,
		},
	}
	for _, item := range tests {
		actual := numberOfZeros(item.input)
		if actual != item.expect {
			t.Fatalf("expect %d, actual %d\n", item.expect, actual)
		}
	}
}
