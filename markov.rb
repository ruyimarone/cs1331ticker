require 'marky_markov'
require 'mail'
require 'pry'

class PiazzaStrings
  def initialize()
    Mail.defaults do
      retriever_method :pop3, :address => "pop.gmail.com",
        :port       => 995,
        :user_name  => ENV['PIAZZA_BOT_USERNAME'],
        :password   => ENV['PIAZZA_BOT_PASSWORD'],
        :enable_ssl => true
    end
  end

  def get()
    emails = Mail.find(:what => :first, :count => 10, :order => :asc)
    emails.select! {|mail| mail.from.any? {|s| s =~ /piazza\.com$/}}

    puts emails.empty? ? "no new mail :(" : "downloaded #{emails.length} email(s)"

    emails.map do |mail|
      # pulls out the post between the piazza boilerplate
      match = mail.body.decoded.match(/^.*?posted.*?\n{2}(.*?)\n{2}Go to http/m)
      unless match.nil?
        result = match[1].gsub(/=[A-Z0-9]/, '') 
        return result.gsub(/\s{2,}|\n/, ' ')
      else
        return nil
      end
    end
  end
end

class PiazzaMarkov
  def initialize
    @markov = MarkyMarkov::Dictionary.new('piazza_v1')
  end
  
  def parse_strings(strings)
    strings.each do |str|
      @markov.parse_string str unless str.nil?
    end
    @markov.save_dictionary!
  end

  def generate_sentences(n)
    @markov.generate_n_sentences n
  end
end

piazza_strings = PiazzaStrings.new
piazza_markov  = PiazzaMarkov.new
threads = []
string_buffer = []
buffer_control = Mutex.new
threads << Thread.new do
  while true
    strings = piazza_strings.get
    buffer_control.synchronize {
      string_buffer.concat strings
    }
    sleep 60
  end
end

Thread::abort_on_exception = true

threads << Thread.new do
  while true
    buffer_control.synchronize {
      piazza_markov.parse_strings string_buffer unless string_buffer.empty?
      string_buffer.clear
    }
    `clear`
    puts piazza_markov.generate_sentences 2
    sleep 5
  end
end

threads.each(&:join)
