require 'mail'

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
    emails = Mail.find(:what => :first, :count => 20, :order => :asc)
    puts "length: #{emails.length}"
    emails.each {|mail| p mail.subject}
    emails.select! do |mail| 
      mail.header['from'].value =~ /1331/ \
        and mail.from.any? {|s| s =~ /piazza\.com$/}
    end

    if emails.empty?
      puts "no new mail"
    else 
      puts "downloaded #{emails.length} email(s)"
      File.open('emails.log', 'a') do |logfile|
        emails.map do |mail|
          # pulls out the post between the piazza boilerplate
          match = mail.body.decoded.match(/^.*?posted.*?\n{2}(.*?)\n{2}Go to http/m)
          logfile.puts "Subject: " + mail.subject
          logfile.puts mail.body.decoded
          unless match.nil?
            result = match[1]
            result = result.unpack "M" # somehow this fixes q-encoding artifacts
            logfile.puts "\n~~~~~~~~parsed~~~~~~~~"
            logfile.puts result
            logfile.puts "~~~~~~~~~~end~~~~~~~~~~"
            result
          else
            nil
          end
        end
      end
    end
  end
end


if __FILE__ == $0
  Thread::abort_on_exception = true
  piazza_strings = PiazzaStrings.new
  Thread.new do
    while true
      piazza_strings.get
      sleep 6
    end
  end.join
end
