require 'marky_markov'
require 'mail'
require 'pry'

Mail.defaults do
  retriever_method :pop3, :address => "pop.gmail.com",
    :port       => 995,
    :user_name  => ENV['PIAZZA_BOT_USERNAME'],
    :password   => ENV['PIAZZA_BOT_PASSWORD'],
    :enable_ssl => true
end

emails = Mail.find(:what => :first, :count => 10, :order => :asc)
emails.select! {|mail| mail.from.any? {|s| s =~ /piazza\.com$/}}

puts "no new mail :(" if emails.empty?

piazza_strs = emails.map do |mail|
  # pulls out the post between the piazza boilerplate
  match = mail.body.decoded.match(/^.*?posted.*?\n{2}(.*?)\n{2}Go to http/m)
  match[1] unless match.nil?
end

markov = MarkyMarkov::Dictionary.new('piazza_v1')
piazza_strs.each do |str|
  markov.parse_string str unless str.nil?
end
markov.save_dictionary!
while true
  puts markov.generate_3_sentences
  sleep 5
end
