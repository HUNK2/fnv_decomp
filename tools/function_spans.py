#!/usr/bin/env python3
"""Canonical function extents: entry to the next entry, minus trailing padding."""
from bisect import bisect_right
import json
from pathlib import Path

SIZE_BASIS = 'function entry to next entry in the same section, or containing section file-backed end, minus trailing 0xCC/0x90 padding; includes switch tables and inline data'


def address_number(value):
    return int(value, 16) if isinstance(value, str) else int(value)


class FunctionSpans:
    def __init__(self, pe, entries):
        self.pe = pe
        self.entries = sorted({address_number(row['address']) for row in entries})
        self.cache = {}

    @classmethod
    def from_index(cls, pe, index):
        return cls(pe, json.loads(Path(index).read_text()))

    def size(self, address):
        address = address_number(address)
        if address in self.cache:
            return self.cache[address]
        position = bisect_right(self.entries, address)
        if not position or self.entries[position - 1] != address:
            raise ValueError('Function entry absent from index: 0x%08x' % address)
        section_end = None
        for start, virtual_size, raw_size, _ in self.pe.sections:
            start += self.pe.base
            end = start + min(virtual_size, raw_size)
            if start <= address < end:
                section_end = end
                break
        if section_end is None:
            raise ValueError('Function entry outside section file-backed data: 0x%08x' % address)
        end = section_end
        if position < len(self.entries) and self.entries[position] < section_end:
            end = self.entries[position]
        data = self.pe.read(address, end - address)
        size = len(data)
        while size and data[size - 1] in (0xcc, 0x90):
            size -= 1
        if not size:
            raise ValueError('Canonical function span contains only padding: 0x%08x' % address)
        self.cache[address] = size
        return size
