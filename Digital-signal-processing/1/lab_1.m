function lab_1()
T = 2;
A = 1.0;
sigma = 0.5;

% Границы расчетов
mult = 10;
t = -mult:1/200:mult;
x10 = zeros(size(t));
x10((abs(t) - T) < 0) = 1;
x20 = A * exp(-(t/sigma).^2);

% Расчет импульсных функций
pe=20;
delta = 1/pe;
t1 = -mult:delta:mult;
x1 = zeros(size(t1));
x1((abs(t1) - T) < 0) = 1;
x2 = A * exp(-(t1/sigma).^2);

%восстановленный аналоговый сигнал
Q = zeros(length(t1),length(t));

for i=1:length(t1)
    Q(i,:) = sinc((t-t1(i))*pe).*x1(i);
    
end
Q1 = zeros(length(t1),length(t));
for i=1:length(t1)
    Q1(i,:) = sinc((t-t1(i))*pe).*x2(i);
end

x11=sum(Q);
x22=sum(Q1);

figure (1);
subplot(2,1,1)
plot(t,x10,'r',t,x11,'b');
subplot(2,1,2)
plot(t,x20,'r',t,x22,'black');
end


