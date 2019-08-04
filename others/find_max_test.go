package others

import (
	"bytes"
	"testing"
)

func Test_findMax(t *testing.T) {
	tests := []struct {
		input  []byte
		expect []byte
	}{
		{
			input:  []byte{9, 6, 5, 4, 3},
			expect: []byte{9, 6, 5, 4},
		}, {
			input:  []byte{9, 5, 6, 2, 1},
			expect: []byte{9, 6, 2, 1},
		}, {
			input:  []byte{3, 5, 6, 2, 1},
			expect: []byte{5, 6, 2, 1},
		},
	}
	for _, item := range tests {
		actual := findMax(item.input)
		if !bytes.Equal(actual, item.expect) {
			t.Fatalf("expect %v, actual %v\n", item.expect, actual)
		}
	}
}
