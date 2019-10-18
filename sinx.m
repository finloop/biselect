x = 0.1:0.05:6;
y = sin(x);

plot(x, y);
hold on

fplot(0);
xlim([0.1,6])
y1 = get(gca,'ylim');

plot([1 1], y1);
plot([5 5], y1);
title("y = sin(x)")