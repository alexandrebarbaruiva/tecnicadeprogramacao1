load('ball.txt');
figure;
hold on;
axis([-1, 1, -1, 1])
for c = 1:100,
   b1 = plot(ball(c,1), ball(c,2), 'bo');
   b2 = plot(ball(c,3), ball(c,4), 'r*');
   x = [ball(c,1),ball(c,3)];
   y = [ball(c,2),ball(c,4)];
   line = plot(x, y, '-');
   axis([-1, 1, -1, 1]);
   pause(0.3);
   set(line,'Visible','off')
   set(b1,'Visible','off')
   set(b2,'Visible','off')
end
