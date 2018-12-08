clc, clear;

xAxis = 1:10;
xAxisD = 0.25:0.25:2.5;
%%%%%%%%%%%%%%%%%%%%%%%%%%
% Blocking Prob.         %
%%%%%%%%%%%%%%%%%%%%%%%%%%
% Lambda and Rho Data for Blocking Prob.
bpRandomL = [0.00000 0.02456 0.33168 0.49822 0.59820 0.66491 0.71252 0.74821 0.77599 0.79821];
bpMinQL = [0.00000 0.00000 0.33150 0.49820 0.59820 0.66481 0.71241 0.74821 0.77591 0.79821];
bpTheoryL = [0 0 0 0 0 0 0 1 1 1];

% Mu Data for Blocking Prob.
bpRandomM = [0.49824 0.49820 0.49823 0.49823 0.49826 0.49823 0.49828 0.49822 0.49823 0.49823];
bpMinQM = [0.49820 0.49820 0.49820 0.49820 0.49820 0.49820 0.49820 0.49820 0.49820 0.49820];
bpTheoryM = [1 0 0 0 0 0 0 0 0 0];


%%%%%%%%%%%%%%%%%%%%%%%%%%
% Avg. Queue Length      %           
%%%%%%%%%%%%%%%%%%%%%%%%%%
% Lambda and Rho Data for Avg. Queue Length
qlRandomL = [0 4 9 9 9 9 9 9 9 9];
qlMinQL = [0 0 9 9 9 9 9 9 9 9];
qlTheoryL = [0.018 0.083 0.225 0.5 1.04 2.25 6.125 10 10 10];

% Mu Data for Avg. Queue Length
qlRandomM = [9 9 9 9 9 9 9 9 9 9];
qlMinQM = [9 9 9 9 9 9 9 9 9 9];
qlTheoryM = [10 5 1.67 0.83 0.5 0.33 0.24 0.18 0.14 0.11];


%%%%%%%%%%%%%%%%%%%%%%%%%%
% Avg. Waiting Time      %           
%%%%%%%%%%%%%%%%%%%%%%%%%%
% Lambda and Rho Data for Avg. Waiting Time (microseconds)
wtRandomL = [0.014 0.010 0.012 0.015 0.018 0.021 0.025 0.027 0.030 0.033];
wtMinQL = [0.015 0.012 0.013 0.017 0.021 0.025 0.029 0.033 0.037 0.041];
wtTheoryL = qlTheoryL ./ 0.5:0.5:5;

% Mu Data for Avg. Waiting Time (microseconds)
wtRandomM = [0.015 0.015 0.015 0.015 0.015 0.015 0.015 0.015 0.015 0.015];
wtMinQM = [0.017 0.017 0.017 0.017 0.017 0.017 0.017 0.017 0.017 0.017];
wtTheoryM = qlTheoryM * 2;


% UNCOMMENT CODE SECTIONs BELOW TO CREATE GRAPHS


% a = plot(xAxis, bpRandomL, xAxis, bpMinQL, xAxis, bpTheoryL);
% xlabel('Lambda');
% ylabel('Blocking Probability');
% legend(a, 'Random', 'Min Queue', 'Theory');
% title('Blocking Probability vs. Lambda');


% a = plot(xAxisD, bpRandomL, xAxisD, bpMinQL, xAxisD, bpTheoryL);
% xlabel('Rho');
% ylabel('Blocking Probability');
% legend(a, 'Random', 'Min Queue', 'Theory');
% title('Blocking Probability vs. Rho');


% a = plot(xAxis, bpRandomM, xAxis, bpMinQM, xAxis, bpTheoryM);
% xlabel('Mu');
% ylabel('Blocking Probability');
% legend(a, 'Random', 'Min Queue', 'Theory');
% title('Blocking Probability vs. Mu');


% a = plot(xAxis, qlRandomL, xAxis, qlMinQL, xAxis, qlTheoryL);
% xlabel('Lambda');
% ylabel('Average Queue Length');
% legend(a, 'Random', 'Min Queue', 'Theory');
% title('Average Queue Length vs. Lambda');


% a = plot(xAxisD, qlRandomL, xAxisD, qlMinQL, xAxisD, qlTheoryL);
% xlabel('Rho');
% ylabel('Average Queue Length');
% legend(a, 'Random', 'Min Queue', 'Theory');
% title('Average Queue Length vs. Rho');


% a = plot(xAxis, qlRandomM, xAxis, qlMinQM, xAxis, qlTheoryM);
% xlabel('Mu');
% ylabel('Average Queue Length');
% legend(a, 'Random', 'Min Queue', 'Theory');
% title('Average Queue Length vs. Mu');


% a = plot(xAxis, wtRandomL, xAxis, wtMinQL, xAxis, wtTheoryL);
% xlabel('Lambda');
% ylabel('Average Waiting Time');
% legend(a, 'Random', 'Min Queue', 'Theory');
% title('Average Waiting Time vs. Lambda');


% a = plot(xAxisD, wtRandomL, xAxisD, wtMinQL, xAxisD, wtTheoryL);
% xlabel('Rho');
% ylabel('Average Waiting Time');
% legend(a, 'Random', 'Min Queue', 'Theory');
% title('Average Waiting Time vs. Rho');


% a = plot(xAxis, wtRandomM, xAxis, wtMinQM, xAxis, wtTheoryM);
% xlabel('Mu');
% ylabel('Average Waiting Time');
% legend(a, 'Random', 'Min Queue', 'Theory');
% title('Average Waiting Time vs. Mu');

