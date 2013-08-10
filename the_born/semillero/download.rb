1.upto(8) do |i|
  input = "http://acm.student.cs.uwaterloo.ca/~acm00/111002/data/C.#{i}.dat"
  output = "http://acm.student.cs.uwaterloo.ca/~acm00/111002/data/C.#{i}.diff"
  
  `wget #{input}`
  `wget #{output}`
end