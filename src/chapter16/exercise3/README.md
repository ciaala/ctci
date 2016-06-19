#16.3 Intersection
Given two straight line segments (represented as start point and an end point),
computed the point of intersection, if any.
    
    A1 (a1x,a1y)
    A2 (a2x,a2y)
    B1 (b1x,b1y)
    B2 (b2x,b2y)
    
    ma = (a2x-a1x)/(a2y-a1y)
    qa = a1y - ma * a1x  
    mb = (b2x-b1x)/(b2y-b1y)
    qb = b1y - mb * b1x

    if ma == mb 
        print parallel lines
        if qa = qb
            line are on top of each other
    else
        ma*Cx + qa = mb*Cx +qb
        Cx(ma-mb) = qb - qa
        Cx = (qb-qa)/(ma-mb)
        Cy = ma * Cx + qa

     
        

