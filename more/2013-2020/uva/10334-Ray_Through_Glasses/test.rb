public
  @memo = Array.new(1005, -1)

  def f n
    return @memo[n] = 1 if n == 1 or n == 0
    f(n - 1) if @memo[n - 1] == -1
    f(n - 2) if @memo[n - 2] == -1
    return @memo[n] = @memo[n - 1] + @memo[n - 2]
  end

(0..20).each do |i|
  puts "#{i}: #{f(i)}"
end

puts f 1000
