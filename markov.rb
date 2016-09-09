require 'marky_markov'
require 'mail'

Mail.defaults do
  retriever_method :pop3, :address => "pop.gmail.com",
    :port       => 995,
    :user_name  => ENV['PIAZZA_BOT_USERNAME'],
    :password   => ENV['PIAZZA_BOT_PASSWORD'],
    :enable_ssl => true
end

# mail.all only gets the latest messages it hasn't already recieved :(
emails = Mail.all
puts "no new mail :(" if emails.empty?

emails.each do |mail|
  p mail.body
end

