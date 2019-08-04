package others

import (
	"bytes"
	"testing"
)

func Test_findMin(t *testing.T) {
	tests := []struct {
		input  []byte
		expect []byte
	}{
		{
			input:  []byte{9, 6, 5, 4, 3},
			expect: []byte{6, 5, 4, 3},
		}, {
			input:  []byte{9, 5, 6, 2, 1},
			expect: []byte{5, 6, 2, 1},
		}, {
			input:  []byte{3, 5, 6, 2, 1},
			expect: []byte{3, 5, 2, 1},
		},
	}
	for _, item := range tests {
		actual := findMin(item.input)
		if !bytes.Equal(actual, item.expect) {
			t.Fatalf("expect %v, actual %v\n", item.expect, actual)
		}
	}
}
