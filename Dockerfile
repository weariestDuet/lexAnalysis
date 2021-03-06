FROM gcc:10
WORKDIR /lexAnalysis/
COPY ./* ./
RUN g++ -Wall -Wextra -std=c++14 -O2 -fsanitize=address lexAnalysis.cpp -o program
RUN chmod +x program
