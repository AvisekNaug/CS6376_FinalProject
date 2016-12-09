 function [ out, state ] = controller( in, state )
% Takes flight parameters of an aircraft and outputs the direction control

% in: Data Structure that stores input information for the aircraft
% controller. 
%       (in.x, in.y): Current Location of the aircraft
%       (in.xd, in.yd): Destination of aircraft
%       in.theta: Current direction of motion
%       in.m: Message from neighbouring aircraft 
%           - empty if aircraft not in neighbourhood
%           - (x, y, xd, yd, theta) of other aircraft if non-empty
%           - To access data (say x) from in.m, use in.m.x
%
% out : Data Structure that stores the output information from the aircraft
%       out.val: +1, 0, -1 ( +1 - turn left, 0 - go straight, -1 - turn right)
% 
% state: 
%       any state used by the controller


% Initialize state
if (isempty(state))
    state.mode = 0; 
end

% Code to generate controller output

%Finding the shortest path using manhattan heuristic
LeftTurn = wrapTo360(in.theta + 90);
RightTurn = wrapTo360(in.theta - 90);
Straight = in.theta;
in.x1 = in.x;
in.y1 = in.y;
if LeftTurn == 90
    in.y1 = in.y + 1;
elseif LeftTurn == 0 || LeftTurn == 360
    in.x1 = in.x + 1;
elseif LeftTurn == 270
    in.y1 = in.y - 1;
elseif LeftTurn == 180
    in.x1 = in.x - 1;
end
LeftTurnManhattanDistance1 = abs(in.xd-in.x1)+abs(in.yd-in.y1);
in.x2 = in.x;
in.y2 = in.y;
if RightTurn == 90
    in.y2 = in.y + 1;
elseif RightTurn == 0 || RightTurn == 360
    in.x2 = in.x + 1;
elseif RightTurn == 270
    in.y2 = in.y - 1;
elseif RightTurn == 180;
    in.x2 = in.x - 1;
end
RightTurnManhattanDistance1 = abs(in.xd-in.x2)+abs(in.yd-in.y2);
in.x3 = in.x;
in.y3 = in.y;
if Straight == 90
    in.y3 = in.y + 1;
elseif Straight == 0 || Straight == 360
    in.x3 = in.x + 1;
elseif Straight == 270
    in.y3 = in.y - 1;
elseif Straight == 180
    in.x3 = in.x - 1;
end
StraightManhattanDistance1 = abs(in.xd-in.x3)+abs(in.yd-in.y3);

PossibleMoves1 = [LeftTurnManhattanDistance1,RightTurnManhattanDistance1,StraightManhattanDistance1];
[BestMoveValue1,BestMoveIndex1] = min(PossibleMoves1);
if BestMoveValue1==LeftTurnManhattanDistance1
	newPosition1.x = in.x1;
    newPosition1.y = in.y1;
elseif BestMoveValue1==RightTurnManhattanDistance1
	newPosition1.x = in.x2;
    newPosition1.y = in.y2;
elseif BestMoveValue1==StraightManhattanDistance1
	newPosition1.x = in.x3;
    newPosition1.y = in.y3;
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
if (~isempty(in.m))
    %Checking the positions for the other aircraft.
    LeftTurn = wrapTo360(in.m.theta + 90);
    RightTurn = wrapTo360(in.m.theta - 90);
    Straight = in.m.theta;
    in.m.x1 = in.m.x;
    in.m.y1 = in.m.y;
    if LeftTurn == 90
        in.m.y1 = in.m.y + 1;
    elseif LeftTurn == 0 || LeftTurn == 360
        in.m.x1 = in.m.x + 1;
    elseif LeftTurn == 270
        in.m.y1 = in.m.y - 1;
    elseif LeftTurn == 180
        in.m.x1 = in.m.x - 1;
    end
    LeftTurnManhattanDistance2 = abs(in.m.xd-in.m.x1)+abs(in.m.yd-in.m.y1);
    in.m.x2 = in.m.x;
    in.m.y2 = in.m.y;
    if RightTurn == 90
        in.m.y2 = in.m.y + 1;
    elseif RightTurn == 0 || RightTurn == 360
        in.m.x2 = in.m.x + 1;
    elseif RightTurn == 270
        in.m.y2 = in.m.y - 1;
    elseif RightTurn == 180
        in.m.x2 = in.m.x - 1;
    end
    RightTurnManhattanDistance2 = abs(in.m.xd-in.m.x2)+abs(in.m.yd-in.m.y2);
    in.m.x3 = in.m.x;
    in.m.y3 = in.m.y;
    if Straight == 90
        in.m.y3 = in.m.y + 1;
    elseif Straight == 0 || Straight == 360
        in.m.x3 = in.m.x + 1;
    elseif Straight == 270
        in.m.y3 = in.m.y - 1;
    elseif Straight == 180
        in.m.x3 = in.m.x - 1;
    end
    StraightManhattanDistance2 = abs(in.m.xd-in.m.x3)+abs(in.m.yd-in.m.y3);

    PossibleMoves2 = [LeftTurnManhattanDistance2,RightTurnManhattanDistance2,StraightManhattanDistance2];
    [BestMoveValue2,~] = min(PossibleMoves2);
    if BestMoveValue2==LeftTurnManhattanDistance2
        newPosition2.x = in.m.x1;
        newPosition2.y = in.m.y1;
    elseif BestMoveValue2==RightTurnManhattanDistance2
        newPosition2.x = in.m.x2;
        newPosition2.y = in.m.y2;
    elseif BestMoveValue2==StraightManhattanDistance2
        newPosition2.x = in.m.x3;
        newPosition2.y = in.m.y3;
    end
    %Comparing
    while((newPosition1.x==in.m.x && newPosition1.y==in.m.y && newPosition2.x==in.x && newPosition2.y==in.y)||(newPosition1.x==newPosition2.x ...
            && newPosition1.y==newPosition2.y)||(in.xd==in.x&&in.x==newPosition1.x)&&(abs(in.yd-in.y)<abs(in.yd-newPosition1.y))...
            ||(in.yd==in.y&&in.y==newPosition1.y)&&(abs(in.xd-in.x)<abs(in.xd-newPosition1.x)))          
        PossibleMoves1(BestMoveIndex1) = [];
        [BestMoveValue1,BestMoveIndex1] = min(PossibleMoves1);          
        if BestMoveValue1==LeftTurnManhattanDistance1
            newPosition1.x = in.x1;
            newPosition1.y = in.y1;
        elseif BestMoveValue1==RightTurnManhattanDistance1
            newPosition1.x = in.x2;
            newPosition1.y = in.y2; 
        elseif BestMoveValue1==StraightManhattanDistance1
            newPosition1.x = in.x3;
            newPosition1.y = in.y3;
        
        end
    end
end
if BestMoveValue1==LeftTurnManhattanDistance1
	out.val = 1;
elseif BestMoveValue1==RightTurnManhattanDistance1
	out.val = -1;
elseif BestMoveValue1==StraightManhattanDistance1
	out.val = 0;
end
end
























