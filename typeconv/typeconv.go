package typeconv

import (
	"bytes"
	"encoding/gob"
)

// 将任意类型转换为[]byte
// 不要尝试用此函数转换公私钥
// 不要尝试用此函数转换big.Int
func ToBytes(data any) []byte {
	var buf bytes.Buffer
	enc := gob.NewEncoder(&buf)
	enc.Encode(data)
	return buf.Bytes()
}

// 将[]byte转换为任意类型
// 不要尝试用此函数转换公私钥
// 不要尝试用此函数转换big.Int
func FromBytes[T any](data []byte) T {
	buf := bytes.NewBuffer(data)
	dec := gob.NewDecoder(buf)
	var ret T
	dec.Decode(&ret)
	return ret
}
